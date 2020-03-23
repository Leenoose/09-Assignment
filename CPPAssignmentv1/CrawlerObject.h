#ifndef CRAWLEROBJECT_H
#define CRAWLEROBJECT_H
#include<iostream>
using std::string;
class CrawlerObject {
private:
	string jobTitle;
	string industry;
	string contract;
	string qualification;
	string salary;
	string listingUrl;
public:
	CrawlerObject(string, string, string, string, string, string);
	string getJobTitle();
	string getIndustry();
	string getContract();
	string getQualification();
	string getSalary();
	string getUrl();
};
#endif