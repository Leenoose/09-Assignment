#ifndef CSVFUNCTION_H
#define CSVFUNCTION_H
#include<sstream>
#include<fstream>
#include<vector>

#include "jobObj.h"

using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::cout;
using std::endl;

class CSVFunctions {
public:
	vector<jobObj*> readCsv(string);
	double getMean(vector<jobObj*>);
	double getMedian(vector<jobObj*>);
	double getStandardDeviation(vector<jobObj*>);
	vector<jobObj*> filterCsv(vector <jobObj*>, string, int);
	void printCSV(vector<jobObj*>);

};

#endif