#include "JSONFileCreator.h"
#include "PortfolioTotalsStack.h"
#include "Simulator.h"
#include "SimulatorConfiguration.h"
#include "TradeOutcome.h"
#include <iostream>
#include <string>

using namespace std;

Simulator::Simulator(SimulatorConfiguration config) {
	originalProps = config;
	simProps = config;

	cumulativeTradeCount = 0;
	cumulativeSimCount = 0;

	cout << "We're starting with: $" << config.principal << endl;
}

int Simulator::getSimulationCount() {
	if (cumulativeSimCount == 0) {
		cout << "No simulations have been run yet." << endl;
	}
	return cumulativeSimCount;
}

int Simulator::getTradeCount() {
	if (cumulativeTradeCount == 0) {
		cout << "No simulations have been run yet." << endl;
	}
	return cumulativeTradeCount;
}

bool Simulator::determineOutcome(double winDecimal) {
	bool outcome = (rand() % 100) < (winDecimal * 100);
	// cout << outcome << endl;
	return outcome;
}

TradeOutcome Simulator::runSingleTrade() {
	TradeOutcome result;
	result.outcome = determineOutcome(simProps.winDecimal);
	if (result.outcome == true) {
		simProps.principal *= (1 + simProps.rewardDecimal);
		result.newPortfolioAmount = simProps.principal;
	}
	else if (result.outcome == false) {
		simProps.principal *= (1 - simProps.riskDecimal);
		result.newPortfolioAmount = simProps.principal;
	}
	return result;
}

double Simulator::popLastPortfolio() {
	if (cumulativeTradeCount > 0) {
		cumulativeTradeCount -= 1;
		return totalsStack.pop();
	}
	cout << "No Portfolio Totals have been added yet." << endl;
	return 0;
}

void Simulator::addPortfolio(TradeOutcome result) {
	totalsStack.push(result.newPortfolioAmount);
	cumulativeTradeCount += 1;
	// cout << "Pushed $" << totalsStack.peek() << " to the stack" << endl;
}

void Simulator::runSingleSimulation() {
	for (int i = 0; i < simProps.numOfTrades; i++) {
		TradeOutcome result = runSingleTrade();
		addPortfolio(result);
	}
	simProps = originalProps;  // reset to original configuration
	cumulativeSimCount += 1;
}

void Simulator::runSimulations() {
	int numSims = simProps.numOfSimulations;
	for (int i = 0; i < numSims; i++) {
		runSingleSimulation();
	}
	// Store minPortfolio, maxPortfolio into a SimulationStatObj
	statObj.maxPortfolioAmount = totalsStack.getMax();
	statObj.minPortfolioAmount = totalsStack.getMin();
	// Convert simulationStatObj to a map
	map<string, double> statsMap;
	statsMap.insert(pair<string, double>("minPortfolioAmount", statObj.minPortfolioAmount));  // Why is this backwards in the json file?
	statsMap.insert(pair<string, double>("maxPortfolioAmount", statObj.maxPortfolioAmount));
	// Pass statsMap to a new JSON File Creator
	JSONFileCreator jfc(statsMap);
	// Create a json file in the current directory
	jfc.createJSONFile("simulationResult.json");
}
