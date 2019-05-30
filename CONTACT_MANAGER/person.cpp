#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "person.h"

using namespace std;
using namespace ContactManager;


Person::Person(string pFirstname, string pLastname, GenderType pGender, uint32_t pAge, uint32_t pPostcode, string pPlace, string pStreet, uint32_t pHousenumber, uint32_t pPrefix, uint32_t pPhonenumber) {
	this->firstname = pFirstname;
	this->lastname = pLastname;
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
	ss << firstname << ';' << lastname << ';' << gender << ';' << age << ';' << postcode << ';' << place << ';' << street << ';' << housenumber << ';' << prefix << ';' << phonenumber << '\n';
	return ss;
}

stringstream Person::last_csv_string() {
	stringstream ss;
	ss << firstname << ';' << lastname << ';' << gender << ';' << age << ';' << postcode << ';' << place << ';' << street << ';' << housenumber << ';' << prefix << ';' << phonenumber;
	return ss;
}

stringstream Person::printAllPersons() {
	stringstream ss;
	ss << setw(20) << firstname << setw(20) << lastname << setw(10) << age << setw(15) << place;
	return ss;
}

stringstream Person::printPerson() {
	stringstream ss;
	ss << endl << setw(18) << "  Vorname: " << firstname << endl << setw(18) << "  Nachname: " << lastname << endl << setw(18) << "  Geschlecht: " << enum_to_string(gender) << endl << setw(18) << "  Alter: " << age << endl << setw(18) << "  Wohnort: " << postcode << " " << place << endl << setw(18) << "  Strasse: " << street << " " << housenumber << endl << setw(18) << "  Telefonnummer: " << prefix << "/" << phonenumber << endl;
	return ss;
}

void Person::editPerson(int ind, string input) {

	switch (ind) {
	case 0:
		this->firstname = input;
		break;
	case 1:
		this->lastname = input;
		break;
	case 2:
		this->gender = string_to_enum(input);
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
	default: cout << endl << "  Die eingegebene Nummer war falsch!" << endl; break;
	}
}

string Person::enum_to_string(GenderType tmp) {
	
	string gender;
	
	switch (tmp){
		case MAN: gender = "maennlich"; break;
		case WOMAN: gender = "weiblich"; break;
		case DIVERSE: gender = "divers"; break;
		default: gender = "divers"; break;
	}
	return gender;
}

GenderType Person::string_to_enum(string tmp) {
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

void age_sort() {
	
}

void firstname_sort() {

}

void lastname_sort() {

}

void place_sort() {

}