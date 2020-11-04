#pragma once
#include "PortfolioTotalsStack.h";
#include "SimulatorConfiguration.h"
#include "SimulationStatObj.h"
#include "TradeOutcome.h"

class Simulator
{
	// Vars from config
	SimulatorConfiguration originalProps;
	SimulatorConfiguration simProps;

	// Vars for internal processes
	PortfolioTotalsStack totalsStack;
	SimulationStatObj statObj;
	int cumulativeTradeCount;
	int cumulativeSimCount;

	// Returns the average portfolio total
	double calcPortfolioAverage();

	// Decide if trade was won or lost
	bool determineOutcome(double winDecimal);

public:
	// Default constructor
	Simulator(SimulatorConfiguration config);

	// Pop the last calculated portfolio added to the stack
	double popLastPortfolio();

	// Add another portfolio to the stack
	void addPortfolio(TradeOutcome result);

	// Get the current number of comleted trades
	int getTradeCount();

	// Get the current number of completed simulations
	int getSimulationCount();

	// Runs a single trade and push the result to the inner stack
	TradeOutcome runSingleTrade();

	// Runs a single simulation of specified number of trades and adds the total to the stack
	void runSingleSimulation();

	// Compress the history of stacks so that only the final one remains in totalStacks, and statsStack holds statistical information
	void compressTotalsStack();

	// Completes the desired number of simulations back-to-back
	void runSimulations();

	// Export all simulation totals for use in data visualization
	double* exportPortfolioTotals();
};

