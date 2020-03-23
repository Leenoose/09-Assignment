#include "CrawlerObject.h"

CrawlerObject::CrawlerObject(string job, string ind, string qual, string contr, string sal, string url)
	: jobTitle(job)
	, industry(ind)
	, qualification(qual)
	, contract(contr)
	, salary(sal)
	, listingUrl(url)
{
}

string CrawlerObject::getJobTitle() {
	return this->jobTitle;
}

string CrawlerObject::getIndustry() {
	return this->industry;
}
string CrawlerObject::getContract() {
	return this->contract;
}
string CrawlerObject::getQualification() {
	return this->qualification;
}
string CrawlerObject::getSalary() {
	return this->salary;
}
string CrawlerObject::getUrl() {
	return this->listingUrl;
}
