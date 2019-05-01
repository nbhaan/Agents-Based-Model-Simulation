/* human.cpp
*
*  written by Niels Haan
*/ 

#include "human.h"

const double MEAN = 0.0;
const double STANDARD_DEVIATION = 1.0;

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
	performance = randomValueFromNormalDistribution(50, 10);
	setWithinSpecifiedRange(performance, 0, 100);
	costs = randomValueFromNormalDistribution(2500, 500);
	setWithinSpecifiedRange(costs, 1000, 1000000);
	complementarity = randomValueFromNormalDistribution(0.7, 0.2);
	setWithinSpecifiedRange(complementarity, 0, 1);
	fired = false;
}

void Human::update(Parameters parameters, std::vector<Human> &humans, Machine &machine, int index) {
	if (complementarity > parameters.substitutableTreshold) {
		//std::cout << "I am replaceable and still alive!" << std::endl;
		if (machine.getPerformance() / parameters.numberOfHumans > performance) {
			fired = true;
		} else {
			// reason to sabotage
			machine.use(-abs(randomValueFromNormalDistribution(MEAN, STANDARD_DEVIATION)), parameters.numberOfHumans);
		} 
	} else {
		//reason to use machine to full benefit
		machine.use(abs(randomValueFromNormalDistribution(MEAN, STANDARD_DEVIATION)), parameters.numberOfHumans);
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

bool Human::isFired() {
	return fired;
}

bool Human::operator<(const Human &h) const {
    return performance < h.getPerformance();
}