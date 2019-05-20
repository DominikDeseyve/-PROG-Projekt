#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <istream>
#include <iomanip>

#include "controller.h"
#include "person.h"


using namespace std;
using namespace ContactManager;

/********************************************************************/
/************		Controller							*************/
/********************************************************************/
Controller::Controller(){
	loadContacts(person);
	
	printMenu();
	
	//printContacts();
}

/********************************************************************/
/************		Kontakte laden und speichern		*************/
/********************************************************************/
void Controller::loadContacts(vector<Person>& person) {
	ifstream file;
	string lastname, firstname, helpPostcode, place, street, helpHousenumber, helpAge, helpPhonenumber, helpPrefix, helpGender;
	uint32_t age, housenumber;
	uint8_t prefix, phonenumber, postcode;
	GenderType gender;

	//CSV-Datei öffnen
	file.open("contacts.csv");

	char token = ';';

	if (file) {
		//jede Zeile auslesen
		while (!file.eof()) {
			getline(file, lastname, token);
			getline(file, firstname, token);
			getline(file, helpGender, token);
			getline(file, helpAge, token);
			getline(file, helpPostcode, token);
			getline(file, place, token);
			getline(file, street, token);
			getline(file, helpHousenumber, token);
			getline(file, helpPrefix, token);
			getline(file, helpPhonenumber, '.');

			//Die Daten in richtige Datentypen wandeln
			age = stoi(helpAge);
			postcode = stoi(helpPostcode);
			housenumber = stoi(helpHousenumber);
			phonenumber = stoi(helpPhonenumber);
			prefix = stoi(helpPrefix);

			switch (stoi(helpGender))
			{
			case 0: gender = GenderType::MAN; break;
			case 1: gender = GenderType::WOMAN; break;
			case 2: gender = GenderType::DIVERSE; break;
			}

			//Person anlegen und Werte übergeben
			Person* person1 = new Person(lastname, firstname, gender, age, postcode, place, street, housenumber, prefix, phonenumber);
			person.push_back(*person1);
		}

		//CSV-Datei wird wieder geschlossen
		file.close();
	} 
	else {
		//CSV-Datei konnte nicht ausgelesen werden
		cout << "Unable to open file" << endl;
	}
}

void Controller::saveContacts(vector<Person>& person) {
	//lokale Variablen
	ofstream file;

	//CSV-Datei öffnen
	file.open("contacts.csv");

	// jedes Buch in eine Zeile schreiben
	for (size_t i = 0; i < person.size(); i++)
	{
		file << person[i].getCSV_string().str();
	}

	// CSV Datei schließen    
	file.close();
}

/********************************************************************/
/************		Actionhandler						*************/
/********************************************************************/
void Controller::actionHandler(int number) {
	
	switch (number)
	{
	case 0: printMenu(); break;
	case 1: printContacts(person); break;
	case 2: printSingleContact(person); break;
	case 3: createContact(person); break;
	case 4: editContact(person); break;
	case 5: deleteContact(person); break;
	case 6: exitProgram(person); break;
	default: cout << endl << "Your number was wrong!" << endl; break;
	}
}

/********************************************************************/
/************		Printfunktionen						*************/
/********************************************************************/

void Controller::printMenu() {
	//Ausgabe des Menues
	cout << endl << "++++++ MAIN - MENU ++++++" << endl;
	cout << " | 0 | Show main menu" << endl;
	cout << " | 1 | Print all contacts" << endl;
	cout << " | 2 | Print single contact" << endl;
	cout << " | 3 | Create new contact" << endl;
	cout << " | 4 | Edit contact" << endl;
	cout << " | 5 | Delete single contact" << endl;
	cout << " | 6 | Close Application" << endl;

	//Eingabe der entsprechenden Nummer
	int menu_number;
	cout << endl << "Enter your number: ";
	cin >> menu_number;

	//Actionhandler nach Eingabe ausführen
	actionHandler(menu_number);
}

void Controller::printContacts(vector<Person>& person) {
	cout << endl << "Alle Kontakte: ";
	cout << endl << "---------------------------------" << endl;

	//Ausgabe des Tabellenkopf
	cout << setw(5) << " Nr." << setw(20) << "Nachname" << setw(20) << "Vorname" << setw(6) << "Age" << setw(15) << "Ort" << endl;
	cout << "--------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < person.size(); i++)
	{
		int tmp = i + 1;
		string ind = " " + to_string(tmp) + ".)";
		cout << ind << person[i].printAllPersons().str() << endl;
	}
	printMenu();
}

void Controller::printSingleContact(vector<Person>& person) {
	cout << endl << "Einen Kontakt printen";

	printMenu();
}

/********************************************************************************/
/************		Kontakte erstellen, bearbeiten und loeschen		*************/
/********************************************************************************/
void Controller::createContact(vector<Person>& person) {
	cout << endl << "Einen Kontakt erstellen";

	printMenu();
}

void Controller::editContact(vector<Person>& person) {
	cout << endl << "Einen Kontakt bearbeiten";

	printMenu();
}

void Controller::deleteContact(vector<Person>& person) {
	cout << endl << "Einen Kontakt loeschen";

	printMenu();
}

void Controller::exitProgram(vector<Person>& person) {
	//saveContacts(person);

	cout << endl << "------------------------------";
	cout << endl << "Das Programm wird nun beendet!";
	cout << endl << "------------------------------";
}