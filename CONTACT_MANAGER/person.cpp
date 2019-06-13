#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "person.h"
#include "controller.h"

using namespace std;
using namespace ContactManager;

// Konstruktor --> Person wird erstellt
Person::Person(string pFirstname, string pLastname, GenderType pGender, uint32_t pAge, uint32_t pPostcode, string pPlace, string pStreet, uint32_t pHousenumber, string pPrefix, uint32_t pPhonenumber) {
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

// Stringstream zum Speichern eines Kontaktes in der CSV-Datei wird zurückgegeben
stringstream Person::csv_string() {
	stringstream ss;
	ss << firstname << ';' << lastname << ';' << gender << ';' << age << ';' << postcode << ';' << place << ';' << street << ';' << housenumber << ';' << prefix << ';' << phonenumber;
	return ss;
}

// Stringstream für die Ausgabe eines Kontakts wird zurückgegeben
stringstream Person::printAllPersons() {
	stringstream ss;
	ss << setw(20) << firstname << setw(20) << lastname << setw(10) << age << setw(15) << place;
	return ss;
}

// Stringstream für die Ausgabe eines kompletten Kontakts wird zurückgegeben
stringstream Person::printPerson() {
	stringstream ss;
	ss << endl << setw(18) << "  Vorname: " << firstname << endl << setw(18) << "  Nachname: " << lastname << endl << setw(18) << "  Geschlecht: " << Controller::enumToInt(gender) << endl << setw(18) << "  Alter: " << age << endl << setw(18) << "  Wohnort: " << postcode << " " << place << endl << setw(18) << "  Strasse: " << street << " " << housenumber << endl << setw(18) << "  Telefonnummer: " << prefix << "/" << phonenumber << endl;
	return ss;
}

// Person wird bearbeitet
void Person::editPerson(int ind, string input) {

	switch (ind) {
	case 0:
		this->firstname = input;
		break;
	case 1:
		this->lastname = input;
		break;
	case 2:
		this->gender = Controller::intToEnum(input);
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
		this->prefix = input;
		break;
	case 9:
		this->phonenumber = stoi(input);
		break;
	default: break;
	}
}

ostream& operator<< (ostream& os, const Person& tmpPerson){
	os <<  endl << setw(18) << "  Vorname: " << tmpPerson.firstname << endl ;//<< setw(18) << "  Nachname: " << tmpPerson.getLastname << endl << setw(18) << "  Geschlecht: " << Controller::enumToInt(tmpPerson.getGender) << endl << setw(18) << "  Alter: " << tmpPerson.getAge << endl << setw(18) << "  Wohnort: " << tmpPerson.getPostcode << " " << tmpPerson.getPlace << endl << setw(18) << "  Strasse: " << tmpPerson.getStreet << " " << tmpPerson.getHousenumber << endl << setw(18) << "  Telefonnummer: " << tmpPerson.getPrefix << "/" << tmpPerson.getPhonenumber << endl;
	return os;
}