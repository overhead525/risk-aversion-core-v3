#pragma once
#include <string>
#include <nlohmann\json.hpp>
#include "SimulationStatObj.h"

using namespace std;
using json = nlohmann::json;

class JSONFileCreator
{
	json jObj;
	string jsonOutputString;
	map<string, double> statsMap;
	pair<string, double> stat;

	// Create a JSON object from the passed in stats structure
	void createJSONObject();

	// Convert JSON Object to string before write to file
	void createStringFromJSON();

public:

	// Default constructor
	JSONFileCreator(map<string, double> stats);

	// Create a JSON File
	bool createJSONFile(string filename);
};

