/* firm.cpp
*
*  written by Niels Haan
*/ 

#include "firm.h"

Firm::Firm(Parameters parameters) {
	time = 0;
	costs = 0;
	performance = 0;
	benefitCostRatio = 0;
	numberOfPeopleFired = 0;
	numberOfMachinePurchases = 1;
	initHumans(parameters, humans, parameters.numberOfHumans);
	machine = Machine(parameters.qualityOfTheMachine, parameters.longevityMachine, parameters.priceMachine);
}

void Firm::initHumans(Parameters parameters, std::vector<Human> &humans, int sampleSize) {
	Human human;
	for (int i=0; i<sampleSize; i++) {
		human = Human(parameters);
		humans.push_back(human);
	}
}

void Firm::nextIteration(Parameters parameters) {
	double previousRatio;
	numberOfPeopleSubstitutable = 0;
	for (int h=0; h<parameters.numberOfHumans; h++) {
		humans[h].update(parameters, machine);
		if (humans[h].getComplementarity() > parameters.substitutableTreshold) {
			numberOfPeopleSubstitutable++;
		}
		if (time > 0) {
			previousRatio = benefitCostRatio;
		} else {
			previousRatio = -std::numeric_limits<double>::infinity();
		}
		
		performance += humans[h].getComplementarity()*machine.getPerformance()/parameters.numberOfHumans + (1 - humans[h].getComplementarity())*humans[h].getPerformance();
		costs += humans[h].getCosts() / parameters.timeForWage + machine.getCosts()/machine.getLongevity();
		benefitCostRatio = performance / costs;

		if (previousRatio > benefitCostRatio && humans[h].getComplementarity() > parameters.substitutableTreshold 
			&& machine.getPerformance()/parameters.numberOfHumans > humans[h].getPerformance()) {
			// fire human

			//replace human with other human
			humans.at(h) = Human(parameters);

			//adjustment costs for new human
			costs += humans[h].getRecruitmentCosts();

			numberOfPeopleSubstitutable--;
			numberOfPeopleFired++;
		}
	}
	if (time != 0 && time % machine.getLongevity() == 0) {
		numberOfMachinePurchases++;
		machine.resetPerformance();
	}
	time++;
}

double Firm::getPerformance() {
	return performance;
}

double Firm::getCosts() {
	return costs;
}

double Firm::getBenefitCostRatio() {
	return benefitCostRatio;
}

int Firm::getNumberOfPeopleSubstitutable() {
	return numberOfPeopleSubstitutable;
}

int Firm::getNumberOfPeopleFired() {
	return numberOfPeopleFired;
}

void Firm::print() {
	std::cout << std::fixed << std::setprecision(2) << "Firm: " << "[" << time << ", " << performance << ", " << costs << ", " << benefitCostRatio << ", " << numberOfPeopleSubstitutable << ", " << numberOfPeopleFired << "]" << std::endl;
}

void Firm::printHumans() {
	for (int i=0; i<(int)humans.size(); i++) {
		humans[i].print();
	}	
}