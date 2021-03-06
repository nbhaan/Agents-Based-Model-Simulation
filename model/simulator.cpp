/* simulator.cpp
*
*  written by Niels Haan
*/ 

#include "simulator.h"
#include "omp.h"
#include <fstream>
#include <iomanip>
#include <math.h>

Simulator::~Simulator() {
	free(parameters);
}

bool stringToBool(std::string s) {
	if (s == "true" || s == "True" || s == "TRUE" || s == "T" || s == "t") {
		return true;
	} else if (s == "false" || s == "False" || s == "False" || s == "F" || s == "f") {
		return false;
	} else {
		std::cerr << "Invalid argument for function stringToBool" << std::endl;
		return false;
	}
}

void Simulator::initFirms() {
	for(int i=0; i<parameters->numberOfFirms; i++) {
		firms.push_back(Firm(*parameters));
	}
}

void Simulator::run() {
	int progress = 0;
	avgPerformances.resize(parameters->time);
	avgCosts.resize(parameters->time);
	avgNumberOfPeopleSubstitutable.resize(parameters->time);
	avgNumberOfPeopleFired.resize(parameters->time);
	avgMachinePerformance.resize(parameters->time);

	initFirms();

	std::cout << "Running simulation.." << std::endl;
	for (int t=0; t<parameters->time; t++) {		
		for (int i=0; i<parameters->numberOfFirms; i++) {
			firms[i].nextIteration(*parameters);
			avgPerformances[t] += firms[i].getPerformance() / parameters->numberOfFirms;
			avgCosts[t] += firms[i].getCosts() / parameters->numberOfFirms;
			avgNumberOfPeopleSubstitutable[t] += (double)firms[i].getNumberOfPeopleSubstitutable() / parameters->numberOfFirms;
			avgNumberOfPeopleFired[t] += (double)firms[i].getNumberOfPeopleFired() / parameters->numberOfFirms;
			avgMachinePerformance[t] += firms[i].getMachinePerformance() / parameters->numberOfFirms;
		}
		progress++;
		std::cout << "\r" << std::fixed << std::setprecision(2) << "Progress: " << (double)progress/parameters->time * 100 << "%   " << std::flush;
	}
	std::cout << std::endl << "Simulation finished." << std::endl;
}

bool Simulator::readInput(std::string filename) {
	std::ifstream file(filename);
	std::string line;

	if (!file) {
		std::cerr << "Error: unable to open " << filename << " for reading." << std::endl;
		return false;
	}

	getline(file, line);
	int time = stoi(line);
	getline(file, line);
	int numberOfHumans = stoi(line);
	getline(file, line);
	int numberOfFirms = stoi(line);
	getline(file, line);
	int introMachine = stoi(line);
	getline(file, line);
	double costsPerfDependency = stod(line);
	getline(file, line);
	char typeOfWork = line.at(0);
	getline(file, line);
	double costsMachine = stod(line);
	getline(file, line);
	double initPerfMachine = stod(line);
	getline(file, line);
	double learningRateOfTheMachine = stod(line);
	getline(file, line);
	double substitutableTreshold = stod(line);
	getline(file, line);
	double jobVariety = stod(line);
	getline(file, line);
	double learningRateDecay = stod(line);
	parameters = new Parameters(time, numberOfHumans, numberOfFirms, introMachine, costsPerfDependency, typeOfWork, costsMachine, initPerfMachine, learningRateOfTheMachine, substitutableTreshold, jobVariety, learningRateDecay);

	return true;
}

void Simulator::saveOutput(std::string filename) {
	std::ofstream output;
	output.open(filename);

	for (int t=0; t<parameters->time; t++) {
		output << std::fixed << std::setprecision(4) << t << "; " << avgPerformances[t] << "; " << avgCosts[t] << "; " << avgNumberOfPeopleSubstitutable[t] << "; " << avgNumberOfPeopleFired[t] << "; " << avgMachinePerformance[t] << std::endl;
	}
	std::cout << filename << " created." << std::endl;
}