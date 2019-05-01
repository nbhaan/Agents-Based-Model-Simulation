/* machine.cpp
*
*  written by Niels Haan
*/ 

#include "machine.h"

Machine::Machine(double quality, int longevity, double maxPrice): quality(quality), longevity(longevity), 
	costs(quality*maxPrice), performance(0)
{ }

void Machine::use(double input, int sampleSize) {
	performance = performance + quality*input;
}

void Machine::resetPerformance() {
	performance = 0;
}

double Machine::getPerformance() {
	return performance;
}

int Machine::getLongevity() {
	return longevity;
}

double Machine::getCosts() {
	return costs;
}