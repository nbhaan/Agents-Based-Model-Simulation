/* machine.cpp
*
*  written by Niels Haan
*/ 

#include "machine.h"
#include <iostream>

Machine::Machine(double learningRate, double performance, double costs, double learningRateDecay): learningRate(learningRate), 
	performance(performance), costs(costs), learningRateDecay(learningRateDecay)
{ }

void Machine::use(double input) {
	performance = performance + learningRate*input;
	learningRate = learningRate*(1 - learningRateDecay);
}

double Machine::getPerformance() {
	return performance;
}

double Machine::getCosts() {
	return costs;
}