#ifndef PlainMonteCarlo.hpp
#define PlainMonteCarlo.hpp

#include <random>
#include <vector>



template<class Integrand, typename T>
T integratePlainMonteCarlo (Integrand& f,  const unsigned dimension, const ulong maxSamples){
//   typedef double T;
  
  //init random number genrator
  std::default_random_engine generator;
  std::uniform_real_distribution<T> distribution(0.0, 1.0);
  
  T sum = 0;
  T weight = T(1) / maxSamples ;
  std::vector<T> newpoint(dimension);
  for ( ulong i=0; i < maxSamples ; ++i){
      for (uint j=0; j<dimension; ++j){
          newpoint[j] = distribution(generator);
      }

      sum += weight * f(newpoint);
    
  }
  
    return sum;
}

template<class Integrand>
double integratePlainMonteCarlo (Integrand& f,  const unsigned dimension, const ulong maxSamples){

  //init random number genrator
  std::default_random_engine generator;
  std::uniform_real_distribution<double> distribution(0.0, 1.0);

  double sum = 0;
  double weight = double(1) / maxSamples ;
  std::vector<double> newpoint(dimension);
  for ( ulong i=0; i < maxSamples ; ++i){
      for (uint j=0; j<dimension; ++j){
          newpoint[j] = distribution(generator);
      }
      sum += weight * f(newpoint);
  }

    return sum;
}

#endif /* PlainMonteCarlo.hpp */


