#pragma once
struct SimulatorConfiguration {
	double principal = 0;  // Initial portfolio amount
	double riskDecimal = 0;  // User's desired risk on each trade (expressed as a decimal)
	double rewardDecimal = 0;  // User's desired reward on each trade (expressed as a decimal)
	double winDecimal = 0;  // The ratio of user's total wins to total trades (expressed as a decimal)
	double lossDecimal = 0;  // The ratio of a user's total losses to total trades (expressed as a decimal)
	double breakEvenDecimal = 0;  // The ratio of wins to total trades required to completely break even
	int numOfTrades = 0;  // The total number of trades to be simulated in each simulation run
	int numOfSimulations = 0;  // The number of simulations desired to be run (more simulations = most likely behavior)
};
