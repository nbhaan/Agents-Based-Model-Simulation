/* human.h
*
*  written by Niels Haan
*/ 

#ifndef HUMAN_H
#define HUMAN_H

#include "parameters.h"
#include "machine.h"
#include <random>
#include <stdlib.h>
#include <iostream>
#include <vector>

class Human {
private:
	double performance;
	double costs;
	double complementarity;
	bool fired;
public:
	Human() { };
	Human(Parameters parameters);
	void update(Parameters parameters, std::vector<Human> &humans, Machine &machine, int index);
	void print();
	double getPerformance() const; 
	double getComplementarity() const;
	double getCosts() const;
	bool isFired();
	bool operator<(const Human &h) const;
};

#endif