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
	double benefitCostRatio;
	int numberOfPeopleSubstitutable;
	int numberOfPeopleFired;
	int numberOfMachinePurchases;
	std::vector<Human> humans;
	Machine machine;
	void initHumans(Parameters parameters, std::vector<Human> &humans, int sampleSize);
public:
	Firm() { };
	Firm(Parameters parameters);
	void nextIteration(Parameters parameters);
	double getPerformance();
	double getCosts();
	double getBenefitCostRatio();
	int getNumberOfPeopleSubstitutable();
	int getNumberOfPeopleFired();
	void print();
	void printHumans();
};

#endif