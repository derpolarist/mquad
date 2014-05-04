#ifndef PlainMonteCarlo.hpp
#define PlainMonteCarlo.hpp

#include <random>
#include <vector>



template<class Integrand, typename T>
T integratePlainMonteCarlo (Integrand& f,  const unsigned Dimension, const ulong MaxSamples){
//   typedef double T;
  
  //init random number genrator
  std::default_random_engine generator;
  std::uniform_real_distribution<double> distribution(0.0, 1.0);
  
  T sum = 0;
  T weight = T(1) / MaxSamples ;
  std::vector<T> newpoint(Dimension);
  for ( ulong i=0; i < MaxSamples ; ++i){
      for (uint j=0; j<Dimension; ++j){
          newpoint[j] = distribution(generator);
      }

      sum += weight * f(newpoint);
    
  }
  
    return sum;
}

template<class Integrand>
double integratePlainMonteCarlo (Integrand& f,  const unsigned Dimension, const ulong MaxSamples){

  //init random number genrator
  std::default_random_engine generator;
  std::uniform_real_distribution<double> distribution(0.0, 1.0);

  double sum = 0;
  double weight = double(1) / MaxSamples ;
  std::vector<double> newpoint(Dimension);
  for ( ulong i=0; i < MaxSamples ; ++i){
      for (uint j=0; j<Dimension; ++j){
          newpoint[j] = distribution(generator);
      }

      sum += weight * f(newpoint);

  }

    return sum;
}

#endif /* PlainMonteCarlo.hpp */


