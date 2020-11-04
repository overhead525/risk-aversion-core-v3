#pragma once
#include <iostream>
#include <stack>

using namespace std;

class PortfolioTotalsStack
{
	stack<double> s;
	double maxPortfolio;
	double minPortfolio;

public:
	// The constructor
	PortfolioTotalsStack();

	// Returns the highest portfolio simulation calculated so far
	double getMax();

	// Returns the smallest portfolio simulation calculated so far
	double getMin();

	// Returns the last calculated portfolio simulation total
	double peek();

	// Remove the last simulated portfolio from the stack
	double pop();

	// Pushes a portfolio total to the top of the stack, 
	void push(double portfolioTotal);
};

