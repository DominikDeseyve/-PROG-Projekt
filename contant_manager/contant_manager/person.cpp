#include <iostream>
#include <string>
#include "person.h"

using namespace std;
using namespace ContactManager;


Person::Person(string pLastname, string pFirstname, GenderType pGender, uint32_t pAge, string pPlace, string pStreet, uint32_t pHousenumber, uint8_t pPrefix, uint8_t pPhonenumber) {
	this->lastname = pLastname;
	this->firstname = pFirstname;
	this->gender = pGender;
	this->age = pAge;
	this->place = pPlace;
	this->street = pStreet;
	this->housenumber = pHousenumber;
	this->prefix = pPrefix;
	this->phonenumber = pPhonenumber;
}


ostream& ContactManager::operator<<(ostream& os, const Person& pPerson)
{
	string line = pPerson.firstname;
	os << line;
	return os;
}
