#include <iostream>
#include <ctime>
#include <boost/foreach.hpp>
#include "SimulatorConfiguration.h"
#include "Simulator.h"
#include "JSONFileCreator.h"

using namespace std;

void drive(int argc, char* argv[]) {
	for (int i = 0; i < argc; i++) {
		cout << argv[i] << endl;
	}

	SimulatorConfiguration config;
	config.principal = atof(argv[1]);
	config.riskDecimal = atof(argv[2]);
	config.rewardDecimal = atof(argv[3]);
	config.winDecimal = atof(argv[4]);
	config.lossDecimal = atof(argv[5]);
	config.breakEvenDecimal = atof(argv[6]);
	config.numOfTrades = atof(argv[7]);
	config.numOfSimulations = atof(argv[8]);

	Simulator s(config);
	s.runSimulations();
}

int main(int argc, char* argv[]) {
	srand(time(0));
	drive(argc, argv);
}
