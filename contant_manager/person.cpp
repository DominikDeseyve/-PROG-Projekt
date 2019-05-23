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

void Person::editPerson(int ind, string input) {
	
	switch (ind) {
	case 0:
		this->lastname = input;
		break;
	case 1:
		this->firstname = input;
		break;
	case 2:
		GenderType helpGender;

		switch (stoi(input))
		{
			case 0: helpGender = GenderType::MAN; break;
			case 1: helpGender = GenderType::WOMAN; break;
			case 2: helpGender = GenderType::DIVERSE; break;
		}

		this->gender = helpGender;
		break;
	case 3:
		this->age = stoi(input);
		break;
	case 4:
		this->postcode = stoi(input);
		break;
	case 5:
		this->place = input;
		break;
	case 6:
		this->street = input;
		break;
	case 7:
		this->housenumber = stoi(input);
		break;
	case 8:
		this->prefix = stoi(input);
		break;
	case 9:
		this->phonenumber = stoi(input);
		break;
	default: cout << endl << "Die eingegebene Nummer war falsch!" << endl; break;
	}
}

string enum_to_string() {
	
	return 0;
}

static GenderType string_to_enum(string tmp) {
	GenderType gender;

	switch (stoi(tmp))
	{
		case 0: gender = GenderType::MAN; break;
		case 1: gender = GenderType::WOMAN; break;
		case 2: gender = GenderType::DIVERSE; break;
		default: gender = GenderType::DIVERSE; break;
	}
	return gender;
}

ostream& ContactManager::operator<<(ostream& os, const Person& pPerson)
{
	string line = pPerson.firstname;
	os << line;
	return os;
}
