/* human.cpp
*
*  written by Niels Haan
*/ 

#include "human.h"

const double MEAN_STANDARDIZED_DIST = 0.0;
const double STANDARDIZED_SD = 1.0;

// type of jobs
const double ROUTINIZED_MEAN = 0.8;
const double NORMAL_MEAN = 0.5;
const double CREATIVE_MEAN = 0.2;

double randomValueFromNormalDistribution(double mean, double sd) {
	std::random_device rd; 
	std::mt19937 gen(rd()); 
	std::normal_distribution<double> distribution(mean, sd);
	return distribution(gen);
}

void setWithinSpecifiedRange(double &var, double min, double max) {
	if (var < min) {
		var = min;
	} else if (var > max) {
		var = max;
	}
}

Human::Human(Parameters parameters) {
	performance = randomValueFromNormalDistribution(MEAN_STANDARDIZED_DIST, STANDARDIZED_SD);
	costs = parameters.costsPerfDependency*-performance + (1 - parameters.costsPerfDependency)*randomValueFromNormalDistribution(MEAN_STANDARDIZED_DIST, STANDARDIZED_SD);

	switch(parameters.typeOfWork) {
		case 'r': // routinized job
			complementarity = randomValueFromNormalDistribution(ROUTINIZED_MEAN, parameters.jobVariety);
			break;
		case 'n': // normal job
			complementarity = randomValueFromNormalDistribution(NORMAL_MEAN, parameters.jobVariety);
			break;
		case 'c': // creative job
			complementarity = randomValueFromNormalDistribution(CREATIVE_MEAN, parameters.jobVariety);
			break;
	}
	setWithinSpecifiedRange(complementarity, 0, 1);
}

void Human::update(Parameters parameters, Machine &machine) {
	if (complementarity > parameters.substitutableTreshold) {
		// reason to sabotage
		machine.use(-abs(randomValueFromNormalDistribution(MEAN_STANDARDIZED_DIST, STANDARDIZED_SD))/parameters.numberOfHumans);
	} else {
		// reason to use machine to full benefit
		machine.use(abs(randomValueFromNormalDistribution(MEAN_STANDARDIZED_DIST, STANDARDIZED_SD))/parameters.numberOfHumans);
	}
}

void Human::print() {
	std::cout << "Human: " << "[" << performance << ", " << costs << ", " << complementarity << "]" << std::endl;
}

double Human::getPerformance() const {
	return performance;
}

double Human::getComplementarity() const {
	return complementarity;
}

double Human::getCosts() const {
	return costs;
}

double Human::getRecruitmentCosts() {
	return abs(randomValueFromNormalDistribution(MEAN_STANDARDIZED_DIST, STANDARDIZED_SD));
}

bool Human::operator<(const Human &h) const {
    return performance < h.getPerformance();
}