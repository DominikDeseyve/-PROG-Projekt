#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <iomanip>

#include "controller.h"
#include "person.h"


using namespace std;
using namespace ContactManager;

/********************************************************************/
/************ 				Controller 					*************/
/********************************************************************/

Controller::Controller(){
	//Setze Standardpath für CSV-Datei
	this->csvPath = "contacts.csv";
}

/********************************************************************/
/************		Kontakte laden und speichern		*************/
/********************************************************************/

// Kontakte aus CSV-Datei laden
void Controller::loadContacts() {
	// lokale Attribute
	ifstream file;
	string firstname, lastname, helpPostcode, place, street, helpHousenumber, helpAge, helpPrefix, helpPhonenumber, helpGender;
	uint32_t age, housenumber, prefix, phonenumber, postcode;
	GenderType gender = GenderType::DIVERSE;

	// CSV-Datei oeffnen
	file.open(this->csvPath);

	// Trennungstoken für die CSV-Datei
	char token = ';';

	if (file) {
		// jede Zeile wird einzeln ausgelesen
		while (!file.eof()) {
			getline(file, firstname, token);
			getline(file, lastname, token);
			getline(file, helpGender, token);
			getline(file, helpAge, token);
			getline(file, helpPostcode, token);
			getline(file, place, token);
			getline(file, street, token);
			getline(file, helpHousenumber, token);
			getline(file, helpPrefix, token);
			getline(file, helpPhonenumber, '\n');

			// Die Werte aus der CSV-Datei werden in die entsprechenden Werte umgewandelt
			age = stoi(helpAge);
			postcode = stoi(helpPostcode);
			housenumber = stoi(helpHousenumber);
			phonenumber = stoi(helpPhonenumber);
			prefix = stoi(helpPrefix);

			// String wird in entsprechenden enum-Wert umgewandelt
			gender = Controller::intToEnum(helpGender);

			// Person wird angelegt mit den entsprechenden Werten
			Person *person1 = new Person(firstname, lastname, gender, age, postcode, place, street, housenumber, prefix, phonenumber);

			// Die erstellte Person (=> person1) wird in der Personenliste an letzter Stelle angefügt
			this->person.push_back(*person1);
		}

		// CSV-Datei wird wieder geschlossen
		file.close();
	}
	// Falls die CSV-Datei nicht ausgelesen werden kann
	else {
		cout << "  Datei kann nicht geladen werden!" << endl;
	}
}

// Kontakte in CSV-Datei speichern
void Controller::saveContacts() {
	// lokale Attribute
	ofstream file;

	// CSV-Datei oeffnen
	file.open(this->csvPath);

	// jeden Kontakt in eine Zeile schreiben
	for (size_t i = 0; i < person.size(); i++)
	{
		// Jede Person in eine Zeile schreiben
		if (i < person.size() - 1) {
			file << person[i].csv_string().str() << "\n";
		}
		// Letzte Person in eine Zeile schreiben, aber ohne "\n"
		else {
			file << person[i].csv_string().str();
		}
	}

	// CSV Datei schliessen
	file.close();
}

/********************************************************************/
/************				Actionhandler				*************/
/********************************************************************/

// Handler fuer die einzelnen Funktionen des Hauptmenues
void Controller::actionHandler(int number) {

	switch (number)
	{
		// Das Menue wird erneut ausgegeben
		case 0: system("clear");
			printMenu();
			break;

		// Alle Kontakte werden ausgegeben und anschließend wird das Menue wieder ausgegeben
		case 1: printContacts();
			printMenu();
			break;

		// Funktion zum Ausgeben eines einzelnen Kontakts wird aufgerufen
		case 2: printSingleContact(); break;

		// Funktion zum Erstellen eines Kontakts wird aufgerufen
		case 3: createContact(); break;

		// Funktion zum Bearbeiten eines Kontakts wird aufgerufen
		case 4: editContact(); break;

		// Funktion zum Loeschen eines Kontakts wird aufgerufen
		case 5: deleteContact(); break;

		// Funktion zum Sortieren der Kontakte wird aufgerufen
		case 6: sortContacts(); break;

		// Funktion zum Beenden des Programms wird aufgerufen
		case 7: exitProgram(); break;
		default: break;
	}
}

/********************************************************************/
/************			Printfunktionen					*************/
/********************************************************************/

// Menue ausgeben
void Controller::printMenu() {
	// Ausgabe des Menues
	cout << endl << "\x1B[0;36m" << "+++++++     HAUPTMENUE       +++++++";
	cout << endl << "------------------------------------" << "\x1B[0;37m" << endl;

	cout << "  | 0 | Hauptmenue anzeigen" << endl;
	cout << "  | 1 | Alle Kontakte auflisten" << endl;
	cout << "  | 2 | Einen Kontakt vollstaendig auflisten" << endl;
	cout << "  | 3 | Kontakt erstellen" << endl;
	cout << "  | 4 | Kontakt bearbeiten" << endl;
	cout << "  | 5 | Kontakt loeschen" << endl;
	cout << "  | 6 | Kontakte sortieren" << endl;
	cout << "  | 7 | Programm speichern und beenden" << endl;

	// Eingabe der entsprechenden Nummer
	string coutText = "  Gib deine Nummer ein: ";
	string menuNumber = waitForInput(coutText, 0, 7);

	cout << endl << "------------------------------------------------------------------------------------------------------------" << endl;

	// Actionhandler nach Eingabe ausfuehren, um entsprechende Funktion aufzurufen
	actionHandler(stoi(menuNumber));
}

// Alle Kontakte ausgeben
void Controller::printContacts() {
	// Konsole wird gecleared
	system("clear");

	cout << endl << "\x1B[0;36m" << "  Alle Kontakte: ";
	cout << endl << "------------------------------------" << "\x1B[0;37m" << endl;

	// Ausgabe des Tabellenkopf
	cout << setw(5) << " Nr." << setw(20) << "Vorname" << setw(20) << "Nachname" << setw(10) << "Alter" << setw(15) << "Ort" << endl;
	cout << "------------------------------------------------------------------------" << endl;

	// Ausgabe der einzelnen Kontakte Zeile fuer Zeile
	for (uint32_t i = 0; i < person.size(); i++){

		cout << setw(5) << to_string(i+1)+".)" << person[i].printAllPersons().str() << endl;
	}

	cout << endl << "------------------------------------------------------------------------------------------------------------" << endl;
}

// Einzelnen Kontakt ausgeben
void Controller::printSingleContact() {
	// Konsole wird gecleared und alle Kontakte werden ausgegeben
	system("clear");
	printContacts();

	cout << endl << "\x1B[0;36m" << "  Einen Kontakt auflisten";
	cout << endl << "------------------------------------" << "\x1B[0;37m" << endl;

	// Eingabe des gewuenschten Kontakts
	string coutText = "  Gib die Nummer des gewuenschten Kontakts ein: ";
	string contactNumber = waitForInput(coutText, 1, person.size());

	cout << endl << "\x1B[1;35m" << "  Ausgabe des Kontakts: " << contactNumber;
	cout << endl << "------------------------------" << "\x1B[0;37m";

	// Ausgabe des gewuenschten Kontakts
	cout << person[stoi(contactNumber)-1].printPerson().str();

	cout << endl << "------------------------------------------------------------------------------------------------------------" << endl;

	// Ausgabe des Menues
	printMenu();
}

/********************************************************************************/
/************		Kontakte erstellen, bearbeiten und loeschen		*************/
/********************************************************************************/

// Kontakt erstellen
void Controller::createContact() {
	// Konsole wird gecleared
	system("clear");

	cout << endl << "\x1B[0;36m" << "  Einen Kontakt erstellen";
	cout << endl << "------------------------------------" << "\x1B[0;37m" << endl;

	// lokale Attribute
	string firstname, lastname, place, street, gender;
	uint32_t age, housenumber, prefix, phonenumber, postcode;

	// einzelne Eingaben für die entsprechenden Werte
	firstname = waitForInput("  Gib deinen Vornamen ein: ", "str");

	lastname = waitForInput("  Gib deinen Nachnamen ein: ", "str");

	gender = waitForInput("  Gib dein Geschlecht ein (Man = 0, Woman = 1, Diverse = 2): ", "int");

	age = stoi(waitForInput("  Gib dein Alter ein: ", "int"));

	postcode = stoi(waitForInput("  Gib deine Postleitzahl ein: ", "int"));

	place = waitForInput("  Gib deinen Wohnort ein: ", "str");

	cout << endl << "  Gib deine Strasse ein (ohne Hausnummer!): ";
	cin >> street;
	
	housenumber = stoi(waitForInput("  Gib deine Hausnummer ein: ", "int"));

	prefix = stoi(waitForInput("  Gib deine Vorwahl ein: ", "int"));

	phonenumber = stoi(waitForInput("  Gib deine Telefonnummer ein: ", "int"));

	// Person mit den eingegebenen Werten anlegen
	Person* person1 = new Person(firstname, lastname, Controller::intToEnum(gender), age, postcode, place, street, housenumber, prefix, phonenumber);

	// Die erstellte Person (=> person1) wird in der Personenliste an letzter Stelle angefügt
	person.push_back(*person1);

	cout << endl << "\x1B[0;32m" << "  Der Kontakt " << firstname + " " + lastname << " wurde erfolgreich erstellt!" << "\x1B[0;37m" << endl;
	cout << endl << "------------------------------------------------------------------------------------------------------------" << endl;

	// Ausgabe des Menues
	printMenu();
}

// Kontakt bearbeiten
void Controller::editContact() {
	// Konsole wird gecleared und alle Kontakte werden ausgegeben
	system("clear");
	printContacts();

	cout << endl << "\x1B[0;36m" << "  Einen Kontakt bearbeiten";
	cout << endl << "------------------------------------" << "\x1B[0;37m" << endl;

	// Eingabe der Nummer des entsprechenden Kontakts
	string coutText = "  Gib die Nummer des Kontakts ein, welchen du bearbeiten moechtest: ";
	string contactNumber = waitForInput(coutText, 1, person.size());

	// Eingabe der Nummer des entsprechenden Attributs
	cout << endl << "  0.) Vorname" << endl << "  1.) Nachname" << endl << "  2.) Geschlecht" << endl << "  3.) Alter" << endl << "  4.) Postleitzahl" << endl << "  5.) Wohnort" << endl << "  6.) Strasse" << endl << "  7.) Hausnummer" << endl << "  8.) Vorwahl" << endl << "  9.) Telefonnummer" << endl;

	string coutText2 = "  Gib die Nummer des Kontakts ein, welchen du bearbeiten moechtest: ";
	string elementNumber = waitForInput(coutText2, 0, 9);

	string coutText3;
	string newInput;

	switch (stoi(elementNumber)) {
		case 0: 
			coutText3 = "  Gib den neuen Vornamen ein: ";
			newInput = waitForInput(coutText3, "str");
			break;
		case 1: 
			coutText3 = "  Gib den neuen Nachname ein: ";
			newInput = waitForInput(coutText3, "str");
			break;
		case 2:	
			coutText3 = "  Gib das neue Geschlecht ein (Man = 0, Woman = 1, Diverse = 2): ";
			newInput = waitForInput(coutText3, "int");
			break;
		case 3: 
			coutText3 = "  Gib das neue Alter ein: ";
			newInput = waitForInput(coutText3, "int");
			break;
		case 4:
			coutText3 = "  Gib die neue Postleitzahl ein: ";
			newInput = waitForInput(coutText3, "int");
			break;
		case 5:
			coutText3 = "  Gib den neuen Wohnort ein: ";
			newInput = waitForInput(coutText3, "str");
			break;
		case 6:
			cout << endl << "  Gib die neue Strasse ein (ohne Hausnummer!): ";
			cin >> newInput;
			break;
		case 7:
			coutText3 = "  Gib die neue Hausnummer ein: ";
			newInput = waitForInput(coutText3, "int");
			break;
		case 8:
			coutText3 = "  Gib die neue Vorwahl ein: ";
			newInput = waitForInput(coutText3, "int");
			break;
		case 9:
			coutText3 = "  Gib die neue Telefonnummer ein: ";
			newInput = waitForInput(coutText3, "int");
			break;
		default: break;
	}

	// entsprechende Person in der Personenliste wird bearbeitet
	person[stoi(contactNumber) - 1].editPerson(stoi(elementNumber), newInput);

	cout << endl << "\x1B[0;32m" << "  Der Kontakt " << contactNumber << " wurde erfolgreich bearbeitet!" << "\x1B[0;37m" << endl;
	cout << endl << "------------------------------------------------------------------------------------------------------------" << endl;

	// Ausgabe des Menues
	printMenu();
}

// Kontakt loeschen
void Controller::deleteContact() {
	// Konsole wird gecleared und alle Kontakte werden ausgegeben
	system("clear");
	printContacts();

	cout << endl << "\x1B[0;36m" << "  Einen Kontakt loeschen";
	cout << endl << "------------------------------------" << "\x1B[0;37m" << endl;

	// Eingabe des Kontakts der geloescht werden soll
	string coutText = "  Gib die Nummer des Kontakts ein, welchen du loeschen moechtest: ";
	string contactNumber = waitForInput(coutText, 1, person.size());

	// entsprechende Person wird aus der Personenliste geloescht
	person.erase(person.begin() + (stoi(contactNumber)-1));

	cout << endl << "\x1B[0;32m" << "  Der Kontakt " << contactNumber << " wurde erfolgreich geloescht!" << "\x1B[0;37m" << endl;
	cout << endl << "------------------------------------------------------------------------------------------------------------" << endl;

	// Ausgabe des Menues
	printMenu();
}

//Kontakte sortieren
void Controller::sortContacts() {
	// Konsole wird gecleared
	system("clear");

	cout << endl << "\x1B[0;36m" << "  Kontakte sortieren";
	cout << endl << "------------------------------------" << "\x1B[0;37m" << endl;

	cout << "  0.) Vorname" << endl << "  1.) Nachname" << endl << "  2.) Alter" << endl << "  3.) Wohnort" << endl;

	// Eingabe der Nummer nach der sortiert werden soll
	string coutText = "  Gib die Nummer ein, nach der du aufsteigend sortieren moechtest: ";
	string sortNumber = waitForInput(coutText, 0, 3);

	switch (stoi(sortNumber)) {
		// nach dem Vornamen aufsteigend sortieren
		case 0: sortFirstname(); break;

		// nach dem Nachnamen aufsteigend sortieren
		case 1: sortLastname(); break;

		// nach dem Alter aufsteigend sortieren
		case 2: sortAge(); break;

		// nach dem Wohnort aufsteigend sortieren
		case 3: sortPlace(); break;
		default: break;
	}

	cout << endl << "\x1B[0;32m" << "  Die Kontaktliste wurde erfolgreich sortiert!" << "\x1B[0;37m" << endl;
	cout << endl << "------------------------------------------------------------------------------------------------------------" << endl;

	// Ausgabe des Menues
	printMenu();
}

/********************************************************************************/
/************					Sortierfunktionen					*************/
/********************************************************************************/

// Bubblesort-Algorithmus zum aufsteigenden Sortieren des Vornamens
void Controller::sortFirstname(){
	for (int i = 1; i < person.size(); i++)
	{
		for (int a = 0; a < person.size() - i; a++)
		{
			if (person[a+1].getFirstname().compare(person[a].getFirstname()) < 0)
			{
				Person tmp_person = person[a];
				person[a] = person[a+1];
				person[a+1] = tmp_person;
			}
		}
	}
}

// Bubblesort-Algorithmus zum aufsteigenden Sortieren des Nachnamens
void Controller::sortLastname(){
	for (int i = 1; i < person.size(); i++)
	{
		for (int a = 0; a < person.size() - i; a++)
		{
			if (person[a+1].getLastname().compare(person[a].getLastname()) < 0)
			{
				Person tmp_person = person[a];
				person[a] = person[a+1];
				person[a+1] = tmp_person;
			}
		}
	}
}

// Bubblesort-Algorithmus zum aufsteigenden Sortieren des Alters
void Controller::sortAge(){
	for (int i = 1; i < person.size(); i++)
	{
		for (int a = 0; a < person.size() - i ; a++)
		{
			if (person[a].getAge() > person[a+1].getAge())
			{
				Person tmp_person = person[a];
				person[a] = person[a+1];
				person[a+1] = tmp_person;
			}
		}
	}
}

// Bubblesort-Algorithmus zum aufsteigenden Sortieren des Wohnorts
void Controller::sortPlace(){
	for (int i = 1; i < person.size(); i++)
	{
		for (int a = 0; a < person.size() - i; a++)
		{
			if (person[a+1].getPlace().compare(person[a].getPlace()) < 0)
			{
				Person tmp_person = person[a];
				person[a] = person[a+1];
				person[a+1] = tmp_person;
			}
		}
	}
}

/********************************************************************************/
/************		Programm beenden und Kontakte speichern			*************/
/********************************************************************************/

void Controller::exitProgram() {
	// Konsole wird gecleared
	system("clear");

	// Funktion zum Speichern der Kontakte in der CSV-Datei wird ausgeführt
	saveContacts();

	cout << endl << "\x1B[0;32m" << "------------------------------------------------------------";
	cout << endl << "-------------- Das Programm wird nun beendet! --------------";
	cout << endl << "------------------------------------------------------------" << "\x1B[0;37m" << endl << endl;
}

vector<Person> Controller::getPersons() {
	return person;
}

void Controller::setCSVPath(string path) {
	this->csvPath = path;
	cout << "\x1B[0;32m" << "Die CSV-Datei names '" << this->csvPath << "' wird geladen... \x1B[0;37m" << endl;
}

/********************************************************************************/
/************					Input - Funktion					*************/
/********************************************************************************/

string Controller::waitForInput(string coutText, string type){
	
	bool correctInput = false;
	string tmp;

	if(type == "str"){
		while (!correctInput) {
			cout << endl << coutText;
			cin >> tmp;

			correctInput = checkString(tmp);
		}	
		return tmp;
	} 
	else {
		while (!correctInput) {
			cout << endl << coutText;
			cin >> tmp;

			correctInput = checkInt(tmp);
		}	
		return tmp;
	}
}

string Controller::waitForInput(string coutText, int pMin, int pMax){
	bool correctInput = false;
	string tmp;

	while (!correctInput) {
		cout << endl << coutText;
		cin >> tmp;
		correctInput = checkInt(tmp, pMin, pMax);
	}	
	return tmp;
}


/********************************************************************************/
/************					Check - Funtkionen					*************/
/********************************************************************************/

bool Controller::checkInt(string input){
	bool isInt = true;

	//Überprüfe jede einzelne Zahl
	int i = 0;
	while(isInt && i < input.length()) {
		if(!isdigit(input[i])){
			cerr << "\x1B[0;31m" << "  Die eingegebene Zahl ist nicht korrekt!" << "\x1B[0;37m" << endl;
			isInt = false;
		}
		i++;
	}

	//Überprüfe auf Leerstring
	if(input.empty()) {
		cerr << "\x1B[0;31m" << "  Die eingegebene Zahl ist leer!" << "\x1B[0;37m" << endl;
		isInt = false;
	}

	//Überprüfe auf Länge der Zahl
	if(input.length() > 12) {
		cerr << "\x1B[0;31m" << "  Die eingegebene Zahl ist zu lang!" << "\x1B[0;37m" << endl;
		isInt = false;
	}
	return isInt;
}

bool Controller::checkInt(string input, int pMin, int pMax){
	bool isInt = false;
	if(Controller::checkInt(input)) {
		int number = stoi(input);
		if(number >= pMin && number <= pMax) {
			isInt = true;
		} else {
			cerr << "\x1B[0;31m" << "  Die eingegebene Zahl ist nicht korrekt!" << "\x1B[0;37m" << endl;
		}
	}
	return isInt;
}

bool Controller::checkString(string input){
	bool isString = true;	

	//Jeden Buchstaben überprüfen
	int i = 0;
	while(isString && i < input.length()) {
		if(!isalpha(input[i]) && input[i] != '-'){
			cerr << "\x1B[0;31m" << "  Der eingegebene Text ist kein String!" << "\x1B[0;37m" << endl;
			isString = false;
		}
		i++;
	}

	//Überprüfe auf Leerstring
	if(input.empty()) {
		cerr << "\x1B[0;31m" << "  Der eingegebene Text ist leer!" << "\x1B[0;37m" << endl;
		isString = false;
	}

	//Überprüfe maximale Länge
	if(input.length() > 30 || input.length() < 2) {
		cerr << "\x1B[0;31m" << "  Die Länge des eingegebenen Text ist nicht korrekt!" << "\x1B[0;37m" << endl;
		isString = false;
	}
	return isString;
}

/********************************************************************************/
/************				Convert - Funtkionen					*************/
/********************************************************************************/

// enum wird in String umgewandelt
string Controller::enumToInt(GenderType tmp) {
	
	string gender;
	switch (tmp){
		case MAN: gender = "maennlich"; break;
		case WOMAN: gender = "weiblich"; break;
		case DIVERSE: gender = "divers"; break;
		default: gender = "divers"; break;
	}
	return gender;
}

// String wird in enum umgewandelt
GenderType Controller::intToEnum(string tmp) {
	GenderType gender;
	if(Controller::checkInt(tmp)) {
		switch (stoi(tmp))
		{
			case 0: gender = GenderType::MAN; break;
			case 1: gender = GenderType::WOMAN; break;
			case 2: gender = GenderType::DIVERSE; break;
			default: gender = GenderType::DIVERSE; break;
		}
	} else {
		return GenderType::DIVERSE;
	}
	return gender;
}
