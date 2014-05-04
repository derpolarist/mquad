#include <vector>
#include <iostream>
#include <stdlib.h>     /* exit, EXIT_FAILURE */

//TODO write generic quadrature rule

struct Domain {
 unsigned long dimensionality;
 std::vector<int> upper;
 std::vector<int> lower;

 Domain ():
     dimensionality(3),
     upper(3),
     lower(3) {
     upper[0] = 1; upper[1] = 2; upper[2] = 1;
     lower[0] = 0; lower[1] = 0; lower[2] = 0;
 }
};

struct ToyFunction1 {
    typedef std::vector<double> ArgumentType;
    typedef double              ReturnType;

    const struct Domain domain;

    double operator()(std::vector<double>& x) {
        return x[0]*x[1]*x[2];
    }
};

template<typename Integrand>
class FullGrid {
public:
    typedef typename Integrand::ArgumentType ArgumentType;
    typedef typename Integrand::ReturnType ReturnType;

    class Iterator {
    private:
        unsigned long nIntegrationPoints;
        unsigned long nDimensions;
        unsigned long nPointsPerDimension;
        unsigned long i, j, total;
        std::vector<double> delta;
    public:
        ReturnType weight;
        ArgumentType point;

        Iterator(FullGrid<Integrand>& g, Integrand& f):
            point(f.domain.dimensionality),
            delta(f.domain.dimensionality) {

            //TODO some typecasts have to be done here
            nDimensions = f.domain.dimensionality;
            nPointsPerDimension = g.maxNumberIntegrationPoints/nDimensions;
            if (nPointsPerDimension == 0) {
                std::cout << "Less integration points than dimensions" << std::endl;
                exit(EXIT_FAILURE); //TODO use expection handling instead
            }
            nIntegrationPoints = nDimensions * nPointsPerDimension;

            for( unsigned long k=0; k < nDimensions; ++k) {
                delta[k] = (f.domain.upper[k] - f.domain.lower[k])/double(nPointsPerDimension);
            }
            weight = 1.0/double(nIntegrationPoints);

            total = 0;
            i = 1;
            j = 0;
            // set point to initial value
            // this should work for ArgumentType being
            // e.g. double[], std::vector<...>, numpy::ndarray
            point[j] = delta[j];
            for(unsigned long k=1; k < nDimensions; ++k)
                point[k] = 0.0;

        }

        Iterator& operator++ () {
            if(i == nPointsPerDimension) {
                ++j;
                i = 1;
            }else{
                ++i;
            }
            point[j] += delta[j];
            ++total;
        }

        bool end() {
            return total == nIntegrationPoints;
        }
    };
public:
    unsigned long maxNumberIntegrationPoints;

    FullGrid(unsigned long n = 1000):
        maxNumberIntegrationPoints(n) {
    }
};

int main() {
    ToyFunction1 f;
    FullGrid<ToyFunction1> fullgrid;

    double res = 0.0;
    for( FullGrid<ToyFunction1>::Iterator p(fullgrid, f); !p.end(); ++p ) {
        res += p.weight * f(p.point);
    }
    std::cout << res << std::endl;
}
