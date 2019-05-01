/* parameters.cpp
*
*  written by Niels Haan
*/ 

#include "parameters.h"

Parameters::Parameters(int time, int numberOfHumans, int numberOfFirms, int longevityMachine, int timeForWage, double maxPriceMachine, 
	double qualityOfTheMachine, double substitutableTreshold, bool parallel): time(time), numberOfHumans(numberOfHumans), 
	numberOfFirms(numberOfFirms), longevityMachine(longevityMachine), timeForWage(timeForWage), maxPriceMachine(maxPriceMachine), 
	qualityOfTheMachine(qualityOfTheMachine), substitutableTreshold(substitutableTreshold), parallel(parallel)
{ }