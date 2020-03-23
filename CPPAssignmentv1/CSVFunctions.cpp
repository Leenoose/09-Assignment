#ifndef CSVFUNCTION_CPP
#define CSVFUNCTION_CPP

#include "CSVFunctions.h"

vector<jobObj*> CSVFunctions::readCsv(string fileName) {
	ifstream in(fileName);
	vector<jobObj*> row;
	string jobTitle, industry, contract, qualification, salary, listingUrl;

	while (in) {
		getline(in, jobTitle, ',');
		getline(in, industry, ',');
		getline(in, qualification, ',');
		getline(in, contract, ',');
		getline(in, salary, ',');
		getline(in, listingUrl);

		jobObj* job = new jobObj(jobTitle, industry, contract, qualification, salary, listingUrl);
		row.push_back(job);
	}
	in.close();


	return row;
}

vector<jobObj*> CSVFunctions::filterCsv(vector<jobObj*> rows, string filterBy, int columnHeader) {
	vector<jobObj*> filteredRows;
	string temp;
	switch (columnHeader) {
	case 1: //filter by jobs
		for (int i = 1;i < rows.size();i++) { // start from 1, because first row is for header.
			temp = rows.at(i)->returnJob();
			size_t found = temp.find(filterBy);

			if (found != string::npos) { //check if keyword was found in row. If found, copy the row to a new vector.
				jobObj* filteredJob = new jobObj(
					rows.at(i)->returnJob(),
					rows.at(i)->returnSpecialization(),
					rows.at(i)->returnEmploymentType(),
					rows.at(i)->returnQualification(),
					rows.at(i)->returnSalary(),
					rows.at(i)->returnJobLink()
				);
				filteredRows.push_back(filteredJob);
			}
		}
		break;
	case 2://filter by industry
		for (int i = 1;i < rows.size();i++) { // start from 1, because first row is for header.
			temp = rows.at(i)->returnSpecialization();
			size_t found = temp.find(filterBy);

			if (found != string::npos) {
				jobObj* filteredJob = new jobObj(
					rows.at(i)->returnJob(),
					rows.at(i)->returnSpecialization(),
					rows.at(i)->returnEmploymentType(),
					rows.at(i)->returnQualification(),
					rows.at(i)->returnSalary(),
					rows.at(i)->returnJobLink()
				);
				filteredRows.push_back(filteredJob);
			}
		}
		break;
	case 3://filter by employment type
		for (int i = 1;i < rows.size();i++) { // start from 1, because first row is for header.
			temp = rows.at(i)->returnEmploymentType();
			size_t found = temp.find(filterBy);

			if (found != string::npos) {
				jobObj* filteredJob = new jobObj(
					rows.at(i)->returnJob(),
					rows.at(i)->returnSpecialization(),
					rows.at(i)->returnEmploymentType(),
					rows.at(i)->returnQualification(),
					rows.at(i)->returnSalary(),
					rows.at(i)->returnJobLink()
				);
				filteredRows.push_back(filteredJob);
			}
		}
		break;
	case 4://filter by qualification required
		for (int i = 1;i < rows.size();i++) { // start from 1, because first row is for header.
			temp = rows.at(i)->returnQualification();
			size_t found = temp.find(filterBy);

			if (found != string::npos) {
				jobObj* filteredJob = new jobObj(
					rows.at(i)->returnJob(),
					rows.at(i)->returnSpecialization(),
					rows.at(i)->returnEmploymentType(),
					rows.at(i)->returnQualification(),
					rows.at(i)->returnSalary(),
					rows.at(i)->returnJobLink()
				);
				filteredRows.push_back(filteredJob);
			}
		}
		break;
	}
	return filteredRows;
}



double CSVFunctions::getMean(vector<jobObj*> rows) {
	double total = 0;
	double rowSize = rows.size() - 1; //Excluding first row that contains the headers.
	for (int i = 1;i < rows.size();i++) {
		string salary = rows.at(i)->returnSalary();
		total += stod(salary);
	}
	return total / rowSize;
}

double CSVFunctions::getMedian(vector<jobObj*> rows) {
	int rowSize = rows.size() - 1; //exclude first row
	double medianIndex, secondMedianIndex;
	if ((rowSize + 1) % 2 == 0){
		medianIndex = (rowSize + 1) / 2;
		secondMedianIndex = medianIndex + 1;
		double median1 = stod(rows.at(medianIndex)->returnSalary());
		double median2 = stod(rows.at(secondMedianIndex)->returnSalary());
		return (median1 + median2) / 2;

	}
	else {
		medianIndex = (rowSize + 1) / 2;
		return stod(rows.at(medianIndex)->returnSalary());
	}
	cout << "Number of rows: " << rowSize << endl;
	cout << "Median index: " << medianIndex << endl;
	
	return medianIndex;

}

double CSVFunctions::getStandardDeviation(vector<jobObj*> rows) {
	int rowSize = rows.size() - 1; //exclude first row
	double mean = getMean(rows);
	double result = 0;
	string temp;
	double temp2, temp3;
	double tempSquared = 0;
	for (int i = 1;i < rowSize;i++) {
		temp = rows.at(i)->returnSalary();
		temp2 = stod(temp) - mean;
		temp3 = temp2 - mean;
		tempSquared = temp3 * temp3;
		result += tempSquared;
	}
	double variance = tempSquared / rowSize;
	double standardDeviation = sqrt(variance);

	return standardDeviation;
}

void CSVFunctions::printCSV(vector<jobObj*> rowVector) {
	for (int i = 0;i < rowVector.size();i++) {
		cout << rowVector.at(i)->returnJob() << endl;
		cout << rowVector.at(i)->returnSpecialization() << endl;
		cout << rowVector.at(i)->returnEmploymentType() << endl;
		cout << rowVector.at(i)->returnQualification() << endl;
		cout << rowVector.at(i)->returnSalary() << endl;
		cout << rowVector.at(i)->returnJobLink() << endl;
	}
}


#endif