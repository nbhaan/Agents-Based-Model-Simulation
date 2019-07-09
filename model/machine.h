/* machine.h
*
*  written by Niels Haan
*/ 

#ifndef MACHINE_H
#define MACHINE_H

class Machine {
private:
	double learningRate;
	double performance;
	double costs;
	double learningRateDecay;
public:
	Machine(){ };
	Machine(double learningRate, double performance, double costs, double learningRateDecay);
	void use(double input);
	double getPerformance();
	double getCosts();
};

#endif