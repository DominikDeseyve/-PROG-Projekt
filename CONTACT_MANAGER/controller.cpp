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

/*************************************/
/************ Controller ************ /
/*************************************/
Controller::Controller(){
	loadContacts(person);
}

/********************************************************************/
/************		Kontakte laden und speichern		*************/
/********************************************************************/

// Kontakte aus CSV-Datei laden
void Controller::loadContacts(vector<Person>& person) {
	// lokale Attribute
	ifstream file;
	string firstname, lastname, helpPostcode, place, street, helpHousenumber, helpAge, helpPhonenumber, helpPrefix, helpGender;
	uint32_t age, housenumber, prefix, phonenumber, postcode;
	GenderType gender = GenderType::DIVERSE;

	// CSV-Datei oeffnen
	file.open("contacts.csv");

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
			person.push_back(*person1);
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
void Controller::saveContacts(vector<Person>& person) {
	// lokale Attribute
	ofstream file;

	// CSV-Datei oeffnen
	file.open("contacts.csv");

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
/************		Actionhandler						*************/
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
		case 1: printContacts(person);
			printMenu();
			break;

		// Funktion zum Ausgeben eines einzelnen Kontakts wird aufgerufen
		case 2: printSingleContact(person); break;

		// Funktion zum Erstellen eines Kontakts wird aufgerufen
		case 3: createContact(person); break;

		// Funktion zum Bearbeiten eines Kontakts wird aufgerufen
		case 4: editContact(person); break;

		// Funktion zum Loeschen eines Kontakts wird aufgerufen
		case 5: deleteContact(person); break;

		// Funktion zum Sortieren der Kontakte wird aufgerufen
		case 6: sortContacts(person); break;

		// Funktion zum Beenden des Programms wird aufgerufen
		case 7: exitProgram(person); break;
	}
}

/********************************************************************/
/************		Printfunktionen						*************/
/********************************************************************/

// Menue ausgeben
void Controller::printMenu() {
	// Ausgabe des Menues
	cout << endl << "\x1B[0;36m" << "+++++++     HAUPTMENUE       +++++++";
	cout << endl << "------------------------------------" << "\x1B[0;37m" << endl;

	cout << "  | 0 | Hauptmenue anzeigen" << endl;
	cout << "  | 1 | Alle Kontakte auflisten" << endl;
	cout << "  | 2 | Einen Kontakt auflisten" << endl;
	cout << "  | 3 | Kontakt erstellen" << endl;
	cout << "  | 4 | Kontakt bearbeiten" << endl;
	cout << "  | 5 | Kontakt loeschen" << endl;
	cout << "  | 6 | Kontakte sortieren" << endl;
	cout << "  | 7 | Programm speichern und beenden" << endl;

	// Eingabe der entsprechenden Nummer
	string menu_number;
	bool correctInput = false;

	while (!correctInput) {
		cout << endl << "  Gib deine Nummer ein: ";
		cin >> menu_number;
		correctInput = checkInt(menu_number);

		if(correctInput) {
			if(stoi(menu_number) > 7 || stoi(menu_number) < 0){
				correctInput = false;
				cout << "\x1B[0;31m" << "  Die eingegebene Nummer war falsch!" << "\x1B[0;37m" << endl;
			}
		} else {
			cout << "\x1B[0;31m" << "  Es wurde keine Nummer eingegeben!" << "\x1B[0;37m" << endl;
		}
	}

	cout << endl << "------------------------------------------------------------------------------------------------------------" << endl;

	// Actionhandler nach Eingabe ausfuehren, um entsprechende Funktion aufzurufen
	actionHandler(stoi(menu_number));
}

// Alle Kontakte ausgeben
void Controller::printContacts(vector<Person>& person) {
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
void Controller::printSingleContact(vector<Person>& person) {
	// Konsole wird gecleared und alle Kontakte werden ausgegeben
	system("clear");
	printContacts(person);

	cout << endl << "\x1B[0;36m" << "  Einen Kontakt auflisten";
	cout << endl << "------------------------------------" << "\x1B[0;37m" << endl;

	// Eingabe des gewuenschten Kontakts
	int tmp;

	while (tmp > person.size() || tmp <= 0){
		cout << endl << "  Gib die Nummer des gewuenschten Kontakts ein: ";
		cin >> tmp;

		if(tmp > person.size() || tmp <= 0){
			cout << "\x1B[0;31m" << "  Die eingegebene Nummer war falsch!" << "\x1B[0;37m" << endl;
		}
	}

	cout << endl << "\x1B[1;35m" << "  Ausgabe des Kontakts: " << tmp;
	cout << endl << "------------------------------" << "\x1B[0;37m";

	// Ausgabe des gewuenschten Kontakts
	cout << person[tmp-1].printPerson().str();

	cout << endl << "------------------------------------------------------------------------------------------------------------" << endl;

	// Ausgabe des Menues
	printMenu();
}

/********************************************************************************/
/************		Kontakte erstellen, bearbeiten und loeschen		*************/
/********************************************************************************/

// Kontakt erstellen
void Controller::createContact(vector<Person>& person) {
	// Konsole wird gecleared
	system("clear");

	cout << endl << "\x1B[0;36m" << "  Einen Kontakt erstellen";
	cout << endl << "------------------------------------" << "\x1B[0;37m" << endl;

	// lokale Attribute
	string firstname, lastname, place, street, gender;
	uint32_t age, housenumber, prefix, phonenumber, postcode;
	bool correctInput = false;

	// einzelne Eingaben für die entsprechenden Werte
	cout << "  Gib deinen Vornamen ein: ";
	cin >> lastname;
	/*
	while (!correctInput) {
		cout << "  Gib deinen Vornamen ein: ";
		cin >> firstname;
		correctInput = checkString(firstname);

		if(correctInput) {
			cout << "\x1B[0;31m" << "  Es wurde kein Text eingegeben!" << "\x1B[0;37m" << endl;
		}
	}*/

	cout << "  Gib deinen Nachnamen ein: ";
	cin >> lastname;
	cout << "  Gib dein Geschlecht ein (Man = 0, Woman = 1, Diverse = 2): ";
	cin >> gender;
	cout << "  Gib dein Alter ein: ";
	cin >> age;
	cout << "  Gib deine Postleitzahl ein: ";
	cin >> postcode;
	cout << "  Gib deinen Wohnort ein: ";
	cin >> place;
	cout << "  Gib deine Strasse ein: ";
	cin >> street;
	cout << "  Gib deine Hausnummer ein: ";
	cin >> housenumber;
	cout << "  Gib deine Vorwahl ein: ";
	cin >> prefix;
	cout << "  Gib deine Telefonnummer ein: ";
	cin >> phonenumber;

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
void Controller::editContact(vector<Person>& person) {
	// Konsole wird gecleared und alle Kontakte werden ausgegeben
	system("clear");
	printContacts(person);

	cout << endl << "\x1B[0;36m" << "  Einen Kontakt bearbeiten";
	cout << endl << "------------------------------------" << "\x1B[0;37m" << endl;

	// Eingabe der Nummer des entsprechenden Kontakts
	int tmp;

	while (tmp > person.size() || tmp <= 0){
		cout << endl << "  Gib die Nummer des Kontakts ein, welchen du bearbeiten moechtest: ";
		cin >> tmp;

		if(tmp > person.size() || tmp <= 0){
			cout << "\x1B[0;31m" << "  Die eingegebene Nummer war falsch!" << "\x1B[0;37m" << endl;
		}
	}

	// Eingabe der Nummer des entsprechenden Attributs
	int tmp2;
	cout << endl << "  0.) Vorname" << endl << "  1.) Nachname" << endl << "  2.) Geschlecht" << endl << "  3.) Alter" << endl << "  4.) Postleitzahl" << endl << "  5.) Wohnort" << endl << "  6.) Strasse" << endl << "  7.) Hausnummer" << endl << "  8.) Vorwahl" << endl << "  9.) Telefonnummer" << endl;

	while (tmp2 > 9 || tmp2 < 0){
		cout << endl << "  Gib die Nummer ein, die du bearbeiten moechtest: ";
		cin >> tmp2;

		if(tmp2 > 9 || tmp2 < 0){
			cout << "\x1B[0;31m" << "  Die eingegebene Nummer war falsch!" << "\x1B[0;37m" << endl;
		}
	}

	string tmp3;
	stringstream ss;

	switch (tmp2) {
		case 0: ss << endl << "  Gib den neuen Vornamen ein: "; break;

		case 1: ss << endl << "  Gib den neuen Nachname ein: "; break;

		case 2:	ss << endl << "  Gib das neue Geschlecht ein (Man = 0, Woman = 1, Diverse = 2): "; break;

		case 3: ss << endl << "  Gib das neue Alter ein: "; break;

		case 4:
			cout << endl << "  Gib die neue Postleitzahl ein: ";
			cin >> tmp3;
			break;
		case 5:
			cout << endl << "  Gib den neuen Wohnort ein: ";
			cin >> tmp3;
			break;
		case 6:
			cout << endl << "  Gib die neue Strasse ein: ";
			cin >> tmp3;
			break;
		case 7:
			cout << endl << "  Gib die neue Hausnummer ein: ";
			cin >> tmp3;
			break;
		case 8:
			cout << endl << "  Gib die neue Vorwahl ein: ";
			cin >> tmp3;
			break;
		case 9:
			cout << endl << "  Gib die neue Telefonnummer ein: ";
			cin >> tmp3;
			break;
		default: cout << endl << "  Die eingegebene Nummer war falsch!" << endl; break;
	}

	bool correctInput = false;

	while (!correctInput) {
		cout << ss.str();
		cin >> tmp3;
		correctInput = checkString(tmp3);

		if(correctInput) {
			cout << "\x1B[0;31m" << "  Es wurde kein Text eingegeben!" << "\x1B[0;37m" << endl;
			correctInput = false;
		}
	}
/*
	// entsprechende Person in der Personenliste wird bearbeitet
	person[tmp - 1].editPerson(tmp2, tmp3);
*/
	cout << endl << "\x1B[0;32m" << "  Der Kontakt " << tmp << " wurde erfolgreich bearbeitet!" << "\x1B[0;37m" << endl;
	cout << endl << "------------------------------------------------------------------------------------------------------------" << endl;

	// Ausgabe des Menues
	printMenu();
}

// Kontakt loeschen
void Controller::deleteContact(vector<Person>& person) {
	// Konsole wird gecleared und alle Kontakte werden ausgegeben
	system("clear");
	printContacts(person);

	cout << endl << "\x1B[0;36m" << "  Einen Kontakt loeschen";
	cout << endl << "------------------------------------" << "\x1B[0;37m" << endl;

	// Eingabe der Nummer des entsprechenden Kontakts
	int tmp;

	while (tmp > person.size() || tmp <= 0){
		cout << endl << "  Gib die Nummer ein, welche du loeschen moechtest: ";
		cin >> tmp;

		if(tmp > person.size() || tmp <= 0){
			cout << "\x1B[0;31m" << "  Die eingegebene Nummer war falsch!" << "\x1B[0;37m" << endl;
		}
	}

	// entsprechende Person wird aus der Personenliste geloescht
	person.erase(person.begin() + (tmp-1));

	cout << endl << "\x1B[0;32m" << "  Der Kontakt " << tmp << " wurde erfolgreich geloescht!" << "\x1B[0;37m" << endl;
	cout << endl << "------------------------------------------------------------------------------------------------------------" << endl;

	// Ausgabe des Menues
	printMenu();
}

//Kontakte sortieren
void Controller::sortContacts(vector<Person>& person) {
	// Konsole wird gecleared
	system("clear");

	cout << endl << "\x1B[0;36m" << "  Kontakte sortieren";
	cout << endl << "------------------------------------" << "\x1B[0;37m" << endl;

	int tmp;
	cout << "  0.) Vorname" << endl << "  1.) Nachname" << endl << "  2.) Alter" << endl << "  3.) Wohnort" << endl;

	while (tmp > 3 || tmp < 0){
		cout << endl << "  Gib die Nummer ein, nach der du aufsteigend sortieren moechtest: ";
		cin >> tmp;

		if(tmp > 3 || tmp < 0){
			cout << "\x1B[0;31m" << "  Die eingegebene Nummer war falsch!" << "\x1B[0;37m" << endl;
		}
	}

	switch (tmp) {
		// nach dem Vornamen aufsteigend sortieren
		case 0: sortFirstname(person); break;

		// nach dem Nachnamen aufsteigend sortieren
		case 1: sortLastname(person); break;

		// nach dem Alter aufsteigend sortieren
		case 2: sortAge(person); break;

		// nach dem Wohnort aufsteigend sortieren
		case 3: sortPlace(person); break;

		default: cout << endl << "  Die eingegebene Nummer war falsch!" << endl; break;
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
void Controller::sortFirstname(vector<Person>& person){
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
void Controller::sortLastname(vector<Person>& person){
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
void Controller::sortAge(vector<Person>& person){
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
void Controller::sortPlace(vector<Person>& person){
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

void Controller::exitProgram(vector<Person>& person) {
	// Konsole wird gecleared
	system("clear");

	// Funktion zum Speichern der Kontakte in der CSV-Datei wird ausgeführt
	saveContacts(person);

	cout << endl << "\x1B[0;32m" << "------------------------------------------------------------";
	cout << endl << "-------------- Das Programm wird nun beendet! --------------";
	cout << endl << "------------------------------------------------------------" << "\x1B[0;37m" << endl << endl;
}

vector<Person> Controller::getPersons() {
	return person;
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
			cout << "\x1B[0;31m" << "  Die eingegebene Zahl ist nicht korrekt!" << "\x1B[0;37m" << endl;
			isInt = false;
		}
		i++;
	}

	//Überprüfe auf Leerstring
	if(input.empty()) {
		cout << "\x1B[0;31m" << "  Die eingegebene Zahl ist leer!" << "\x1B[0;37m" << endl;
		isInt = false;
	}

	//Uberprüfe auf Länge der Zahl
	if(input.length() > 12) {
		cout << "\x1B[0;31m" << "  Die eingegebene Zahl ist zu lang!" << "\x1B[0;37m" << endl;
		isInt = false;
	}
	return isInt;
}

bool Controller::checkString(string input){
	bool isString = true;	

	//Jeden Buchstaben überprüfen
	int i = 0;
	while(isString && i < input.length()) {
		if(!isalpha(input[i]) && input[i] != '-'){
			cout << "\x1B[0;31m" << "  Der eingegebene Text ist kein String!" << "\x1B[0;37m" << endl;
			isString = false;
		}
		i++;
	}

	//Überprüfe auf Leerstring
	if(input.empty()) {
		cout << "\x1B[0;31m" << "  Der eingegebene Text ist leer!" << "\x1B[0;37m" << endl;
		isString = false;
	}

	//Überprüfe maximale Länge
	if(input.length() > 30 || input.length() < 2) {
		cout << "\x1B[0;31m" << "  Die Länge des eingegebenen Text ist nicht korrekt!" << "\x1B[0;37m" << endl;
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

