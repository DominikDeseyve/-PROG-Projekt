#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "person.h"

using namespace std;
using namespace ContactManager;


Person::Person(string pLastname, string pFirstname, GenderType pGender, uint32_t pAge, uint8_t pPostcode, string pPlace, string pStreet, uint32_t pHousenumber, uint8_t pPrefix, uint8_t pPhonenumber) {
	this->lastname = pLastname;
	this->firstname = pFirstname;
	this->gender = pGender;
	this->age = pAge;
	this->postcode = pPostcode;
	this->place = pPlace;
	this->street = pStreet;
	this->housenumber = pHousenumber;
	this->prefix = pPrefix;
	this->phonenumber = pPhonenumber;
}

stringstream Person::getCSV_string() {
	stringstream ss;
	ss << lastname << ';' << firstname << ';' << gender << ';' << age << ';' << postcode << ';' << place << ';' << street << ';' << housenumber << ';' << prefix << ';' << phonenumber << ';';
	return ss;
}

stringstream Person::printAllPersons() {
	stringstream ss;

	ss << lastname << firstname << age << place;

	return ss;
}

ostream& ContactManager::operator<<(ostream& os, const Person& pPerson)
{
	string line = pPerson.firstname;
	os << line;
	return os;
}
