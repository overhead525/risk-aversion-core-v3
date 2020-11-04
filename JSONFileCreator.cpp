#include "JSONFileCreator.h"
#include <string>
#include <boost/foreach.hpp>
#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;

JSONFileCreator::JSONFileCreator(map<string, double> stats) {
	statsMap = stats;
}

void JSONFileCreator::createJSONObject() {
	pair<string, double> smp;
	BOOST_FOREACH(smp, statsMap) {
		jObj[smp.first] = smp.second;
	}
}

void JSONFileCreator::createStringFromJSON() {
	jsonOutputString = jObj.dump();
}

bool JSONFileCreator::createJSONFile(string filename) {
	createJSONObject();
	createStringFromJSON();
	try
	{
		ofstream targetFile;
		targetFile.open(filename);
		targetFile << jsonOutputString;
		targetFile.close();
	}
	catch (const std::exception&)
	{
		cout << "Could not successfully create file." << endl;
		return false;
	}
	cout << "File successfully created!";
	return true;
}
