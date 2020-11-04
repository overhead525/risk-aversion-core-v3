#include "PortfolioTotalsStack.h"
#include <iostream>
#include <stack>

using namespace std;

PortfolioTotalsStack::PortfolioTotalsStack() {}

double PortfolioTotalsStack::getMax() {
	if (s.empty()) {
		cout << "Stack is empty" << endl;
		return -1.00;
	}
	else {
		// cout << "Maximum portfolio in the stack is: $" << maxPortfolio << endl;
		return maxPortfolio;
	}
}

double PortfolioTotalsStack::getMin() {
	if (s.empty()) {
		cout << "Stack is empty" << endl;
		return -1;
	}
	else {
		// cout << "Minimum portfolio in the stack is: $" << minPortfolio << endl;
		return minPortfolio;
	}
}

double PortfolioTotalsStack::peek() {
	if (s.empty()) {
		cout << "Stack is empty" << endl;
		return -1;
	}

	// cout << "Last calculated portfolio is: $" << s.top();

	return s.top();
}

double PortfolioTotalsStack::pop() {
	if (s.empty()) {
		cout << "Stack is empty" << endl;
		return -1;
	}

	double last = s.top();

	if (last == minPortfolio)
		minPortfolio = 0;

	// cout << "Last portfolio $" << last << "removed from the stack" << endl;
	s.pop();

	return last;
}

void PortfolioTotalsStack::push(double portfolioTotal) {
	if (s.empty()) {
		maxPortfolio = portfolioTotal;
		minPortfolio = portfolioTotal;
		s.push(portfolioTotal);
		// cout << "Number inserted: " << portfolioTotal << endl;
		return;
	}
	else
		if (maxPortfolio < portfolioTotal)
			maxPortfolio = portfolioTotal;
	if (minPortfolio > portfolioTotal)
		minPortfolio = portfolioTotal;
	s.push(portfolioTotal);
	// Calculate rolling average of portfolioTotals and update in private variable
	// Will probably need an accumulator as well
}

// Driver Code
void drive() {
	PortfolioTotalsStack pts;
	pts.getMax();
}
