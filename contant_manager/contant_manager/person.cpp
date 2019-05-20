#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "person.h"

using namespace std;
using namespace ContactManager;


Person::Person(string pLastname, string pFirstname, GenderType pGender, uint32_t pAge, uint32_t pPostcode, string pPlace, string pStreet, uint32_t pHousenumber, uint32_t pPrefix, uint32_t pPhonenumber) {
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

stringstream Person::csv_string() {
	stringstream ss;
	ss << lastname << ';' << firstname << ';' << gender << ';' << age << ';' << postcode << ';' << place << ';' << street << ';' << housenumber << ';' << prefix << ';' << phonenumber << '\n';
	return ss;
}

stringstream Person::last_csv_string() {
	stringstream ss;
	ss << lastname << ';' << firstname << ';' << gender << ';' << age << ';' << postcode << ';' << place << ';' << street << ';' << housenumber << ';' << prefix << ';' << phonenumber;
	return ss;
}

stringstream Person::printAllPersons() {
	stringstream ss;
	ss << setw(20) << lastname << setw(20) << firstname << setw(10) << age << setw(15) << place;
	return ss;
}

stringstream Person::printPerson() {
	stringstream ss;
	ss << endl << "Nachname: " << lastname << endl << "Vorname: " << firstname << endl << "Geschlecht: " << gender << endl << "Alter: " << age << endl << "Wohnort: " << postcode << " " << place << endl << "Strasse: " << street << " " << housenumber << endl << "Telefonnummer: " << prefix << "/" << phonenumber << endl;
	return ss;
}

ostream& ContactManager::operator<<(ostream& os, const Person& pPerson)
{
	string line = pPerson.firstname;
	os << line;
	return os;
}
