/* parameters.cpp
*
*  written by Niels Haan
*/ 

#include "parameters.h"

Parameters::Parameters(int time, int numberOfHumans, int numberOfFirms, int introMachine, double costsPerfDependency, char typeOfWork, double costsMachine, double initPerfMachine, 
	double learningRateOfTheMachine, double substitutableTreshold, double jobVariety, double learningRateDecay): time(time), numberOfHumans(numberOfHumans), 
	numberOfFirms(numberOfFirms), introMachine(introMachine), costsPerfDependency(costsPerfDependency), typeOfWork(typeOfWork), costsMachine(costsMachine), initPerfMachine(initPerfMachine), 
	learningRateOfTheMachine(learningRateOfTheMachine), substitutableTreshold(substitutableTreshold), jobVariety(jobVariety), learningRateDecay(learningRateDecay) 
{ }