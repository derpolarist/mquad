#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

#include <mquad/PlainMonteCarlo.hpp>



struct myFunc{
     unsigned dimension;
  
      double operator()( const std::vector<double>& x){
	double sum = 0;
	for (unsigned j=0; j<x.size(); ++j)	sum += x[j];
	return exp(sum);
      }

} f;


int main(){
	std::cout << "test" << std::endl;


    std::cout << std::setprecision(12) << "Value = " << integratePlainMonteCarlo<myFunc, double>(f, 2, 100) << std::endl;
   std::cout <<  std::setprecision(12) << "Value = " << integratePlainMonteCarlo(f, 2, 100) << std::endl;
}
