#include <iostream>
#include <vector>
#include <cmath>

#include <mquad/PlainMonteCarlo.hpp>

double f(const std::vector<double>& x){
	double sum = 0;
	for (unsigned j=0; j<x.size(); ++j)	sum += x[j];
	return exp(sum);
}


int main(){
	std::cout << "test" << std::endl;
}
