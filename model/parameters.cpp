/* parameters.cpp
*
*  written by Niels Haan
*/ 

#include "parameters.h"

Parameters::Parameters(int time, int numberOfHumans, int numberOfFirms, int longevityMachine, int timeForWage, double costsPerfDependency, char typeOfWork, double priceMachine, 
	double qualityOfTheMachine, double substitutableTreshold, bool parallel): time(time), numberOfHumans(numberOfHumans), 
	numberOfFirms(numberOfFirms), longevityMachine(longevityMachine), timeForWage(timeForWage), costsPerfDependency(costsPerfDependency), typeOfWork(typeOfWork), priceMachine(priceMachine), 
	qualityOfTheMachine(qualityOfTheMachine), substitutableTreshold(substitutableTreshold), parallel(parallel)
{ }