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
	const int introMachine;
	const double costsPerfDependency;
	const char typeOfWork;
	const double costsMachine;
	const double initPerfMachine;
	const double learningRateOfTheMachine;
	const double substitutableTreshold;
	const double jobVariety;
	const double learningRateDecay;

	Parameters(int time, int numberOfHumans, int numberOfFirms, int introMachine, double costsPerfDependency, char typeOfWork, double costsMachine, 
		double initPerfMachine, double learningRateOfTheMachine, double substitutableTreshold, double jobVariety, double learningRateDecay);
};

#endif