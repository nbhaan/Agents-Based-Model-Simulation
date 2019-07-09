/* firm.h
*
*  written by Niels Haan
*/ 

#ifndef FIRM_H
#define FIRM_H

#include "parameters.h"
#include "machine.h"
#include "human.h"
#include <vector>
#include <iostream>
#include <iomanip>

class Firm {
private:
	int time;
	double costs;
	double performance;
	int numberOfPeopleSubstitutable;
	int numberOfPeopleFired;
	std::vector<Human> humans;
	Machine machine;
	void initHumans(Parameters parameters, std::vector<Human> &humans, int sampleSize);
public:
	Firm() { };
	Firm(Parameters parameters);
	void nextIteration(Parameters parameters);
	double getMachinePerformance();
	double getPerformance();
	double getCosts();
	int getNumberOfPeopleSubstitutable();
	int getNumberOfPeopleFired();
	void print();
	void printHumans();
};

#endif