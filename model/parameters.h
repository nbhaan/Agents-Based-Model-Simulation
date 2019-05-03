/* parameters.h
*
*  written by Niels Haan
*/ 

#ifndef PARAMETERS_H
#define PARAMETERS_H

class Parameters {
public:
	const int time;
	const int numberOfHumans;
	const int numberOfFirms;
	const int longevityMachine;
	const int timeForWage;
	const double costsPerfDependency;
	const char typeOfWork;
	const double priceMachine;
	const double qualityOfTheMachine;
	const double substitutableTreshold;
	const bool parallel;

	Parameters(int time, int numberOfHumans, int numberOfFirms, int longevityMachine, int timeForWage, double costsPerfDependency, 
		char typeOfWork, double priceMachine, double qualityOfTheMachine, double substitutableTreshold, bool parallel);
};

#endif