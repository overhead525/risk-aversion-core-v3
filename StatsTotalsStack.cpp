#include "StatsTotalsStack.h"
#include <exception>
#include <iostream>

using namespace std;

StatsTotalsStack::StatsTotalsStack() {};

SimulationStatObj StatsTotalsStack::peek() {
	if (s.empty()) {
		// cout << "Stack is empty" << endl;
		throw "ERROR: Stack is empty";
	}
	else {
		return s.top();
	}
}

class stackUnderflowException : public exception
{
	virtual const char* what() const throw()
	{
		return "ERROR: Stack is empty";
	}
} stackUnderflow;

SimulationStatObj StatsTotalsStack::pop() {
	if (s.empty()) {
		cout << "Stack is empty" << endl;
		throw stackUnderflow;
	}
	else {
		SimulationStatObj top = s.top();
		s.pop();
		return top;
	}
}

void StatsTotalsStack::push(SimulationStatObj statObj) {
	s.push(statObj);
	cout << "Simulation object pushed to stack." << endl;
	return;
}
