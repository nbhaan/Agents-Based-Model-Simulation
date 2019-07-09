/* firm.cpp
*
*  written by Niels Haan
*/ 

#include "firm.h"

Firm::Firm(Parameters parameters) {
	time = 0;
	costs = 0;
	performance = 0;
	numberOfPeopleFired = 0;
	initHumans(parameters, humans, parameters.numberOfHumans);
	machine = Machine(parameters.learningRateOfTheMachine, parameters.initPerfMachine, parameters.costsMachine, parameters.learningRateDecay);
}

void Firm::initHumans(Parameters parameters, std::vector<Human> &humans, int sampleSize) {
	Human human;
	for (int i=0; i<sampleSize; i++) {
		human = Human(parameters);
		humans.push_back(human);
	}
}

void Firm::nextIteration(Parameters parameters) {
	performance = 0;
	costs = 0;
	numberOfPeopleSubstitutable = 0;
	for (int h=0; h<(int)humans.size(); h++) {
		if (humans[h].getComplementarity() > parameters.substitutableTreshold) {
			numberOfPeopleSubstitutable++;
		}

		if (time > parameters.introMachine) {
			humans[h].update(parameters, machine);
			if (machine.getPerformance() > humans[h].getPerformance() && humans[h].getComplementarity() <= parameters.substitutableTreshold) {
				performance += (humans[h].getComplementarity()*machine.getPerformance() + (1 - humans[h].getComplementarity())*humans[h].getPerformance()) / parameters.numberOfHumans;
			} else {
				performance += humans[h].getPerformance() / parameters.numberOfHumans;
			}
			
			costs += humans[h].getCosts() / (parameters.numberOfHumans + 1);

			if (humans[h].getComplementarity() > parameters.substitutableTreshold && machine.getPerformance() > humans[h].getPerformance()) {
				// fire human

				// replace human with other human
				humans.at(h) = Human(parameters);

				// adjustment costs for new human
				costs += humans[h].getRecruitmentCosts();

				// remove human instead of replacing
				//humans.erase(humans.begin() + h);

				numberOfPeopleSubstitutable--;
				numberOfPeopleFired++;
			}
		} else {
			performance += humans[h].getPerformance() / parameters.numberOfHumans;
			costs += humans[h].getCosts() / parameters.numberOfHumans;
		}
	}
	if (time > parameters.introMachine) {
		costs += machine.getCosts() / (parameters.numberOfHumans + 1);
	}
	time++;
}

double Firm::getMachinePerformance() {
	return machine.getPerformance();
}

double Firm::getPerformance() {
	return performance;
}

double Firm::getCosts() {
	return costs;
}

int Firm::getNumberOfPeopleSubstitutable() {
	return numberOfPeopleSubstitutable;
}

int Firm::getNumberOfPeopleFired() {
	return numberOfPeopleFired;
}

void Firm::print() {
	std::cout << std::fixed << std::setprecision(2) << "Firm: " << "[" << time << ", " << performance << ", " << costs << ", " << numberOfPeopleSubstitutable << ", " << numberOfPeopleFired << "]" << std::endl;
}

void Firm::printHumans() {
	for (int i=0; i<(int)humans.size(); i++) {
		humans[i].print();
	}	
}