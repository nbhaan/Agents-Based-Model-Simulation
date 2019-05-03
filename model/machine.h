/* machine.h
*
*  written by Niels Haan
*/ 

#ifndef MACHINE_H
#define MACHINE_H

class Machine {
private:
	double quality;
	int longevity;
	double costs;
	double performance;
public:
	Machine(){ };
	Machine(double quality, int longevity, double maxPrice);
	void use(double input);
	void resetPerformance();
	double getPerformance();
	int getLongevity();
	double getCosts();
};

#endif