/* main.cpp
*
*  written by Niels Haan
*/ 

#include "simulator.h"
#include <time.h>

int main(int argc, char *argv[]) {
	clock_t startTime = clock();
	if (argc < 2 || argc > 3) {
        std::cerr << "Usage: " << argv[0] << " in-file [out-file]" << std::endl;
        return 1;
    } 

    Simulator simulator;

    if (!simulator.readInput(argv[1])) {
        std::cerr << "Error: reading input from " << argv[1] << " failed - no output generated."<< std::endl;
        return 1;
    }

    std::string ofname;
    if (argc >= 3) {
    	ofname = argv[2];
    } else {
    	ofname = argv[1];
    	if (ofname.size() >= 3 && ofname.substr(ofname.size() - 3) == ".in") {
            ofname = ofname.substr(0, ofname.size() - 3);
        }
        ofname += ".out";
    }
    simulator.run();
    simulator.saveOutput(ofname);
    
	std::cout << "--- " << (double)(clock() - startTime)/CLOCKS_PER_SEC << " seconds ---" << std::endl;
    return 0;
}