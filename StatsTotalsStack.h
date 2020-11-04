#pragma once
#include <stack>
#include "SimulationStatObj.h"

using namespace std;

class StatsTotalsStack
{
	stack<SimulationStatObj> s;

public:
	// The constructor
	StatsTotalsStack();

	// Returns the last added SimulationStatObj
	SimulationStatObj peek();

	// Removes the last added SimulationStatObj
	SimulationStatObj pop();

	// Pushes a portfolio total to the top of the stack
	void push(SimulationStatObj statObj);
};

