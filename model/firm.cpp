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
	machine = Machine(parameters.qualityOfTheMachine, parameters.longevityMachine, parameters.maxPriceMachine);
}

void Firm::initHumans(Parameters parameters, std::vector<Human> &humans, int sampleSize) {
	Human human;
	for (int i=0; i<sampleSize; i++) {
		human = Human(parameters);
		humans.push_back(human);
	}
}

void Firm::nextIteration(Parameters parameters) {
	numberOfPeopleSubstitutable = 0;
	for (int h=0; h<parameters.numberOfHumans; h++) {
		humans[h].update(parameters, humans, machine, h);
		if (humans[h].getComplementarity() > parameters.substitutableTreshold) {
			numberOfPeopleSubstitutable++;
		}
		if (humans[h].isFired()) {
			//std::cout << "Human fired! Lets get a new one!" << std::endl;
			//humans[h].print();
			
			performance -= humans[h].getPerformance();
			costs -= humans[h].getCosts();
			
			humans.at(h) = Human(parameters);
			
			//std::cout << "is replaced by" << std::endl;
			//humans[h].print();
			
			performance += humans[h].getPerformance();
			costs += humans[h].getCosts();
			
			numberOfPeopleSubstitutable--;
			numberOfPeopleFired++;
		}
		performance += humans[h].getComplementarity()*machine.getPerformance()/parameters.numberOfHumans + (1 - humans[h].getComplementarity())*humans[h].getPerformance();
		costs += humans[h].getCosts() / parameters.timeForWage + machine.getCosts()/machine.getLongevity();
	}
	if (time != 0 && time % machine.getLongevity() == 0) {
		//std::cout << "Machine has to be replaced!" << std::endl;
		numberOfMachinePurchases++;
		machine.resetPerformance();
	}
	benefitCostRatio = performance / costs;
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