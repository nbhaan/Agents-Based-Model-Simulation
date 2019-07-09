/* simulator.h
*
*  written by Niels Haan
*/ 

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include "parameters.h"
#include "firm.h"

class Simulator {

private:
	Parameters *parameters;
	std::vector<Firm> firms;
	std::vector<double> avgPerformances;
	std::vector<double> avgCosts;
	std::vector<double> avgNumberOfPeopleSubstitutable;
	std::vector<double> avgNumberOfPeopleFired;
	std::vector<double> avgMachinePerformance;
	void initFirms();
public:
	Simulator() { };
	~Simulator();
	void run();
	bool readInput(std::string filename);
	void saveOutput(std::string filename);
};

#endif