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
}

/********************************************************************/
/************		Kontakte laden und speichern		*************/
/********************************************************************/

// Kontakte aus CSV-Datei laden
void Controller::loadContacts(vector<Person>& person) {
	ifstream file;
	string firstname, lastname, helpPostcode, place, street, helpHousenumber, helpAge, helpPhonenumber, helpPrefix, helpGender;
	uint32_t age, housenumber, prefix, phonenumber, postcode;
	GenderType gender = GenderType::DIVERSE;

	//CSV-Datei �ffnen
	file.open("contacts.csv");

	char token = ';';

	if (file) {
		//jede Zeile auslesen
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

			//Die Daten in richtige Datentypen wandeln
			age = stoi(helpAge);
			postcode = stoi(helpPostcode);
			housenumber = stoi(helpHousenumber);
			phonenumber = stoi(helpPhonenumber);
			prefix = stoi(helpPrefix);
			gender = Person::string_to_enum(helpGender);

			//Person anlegen und Werte �bergeben
			
			Person *person1 = new Person(firstname, lastname, gender, age, postcode, place, street, housenumber, prefix, phonenumber);
			person.push_back(*person1);
		}

		//CSV-Datei wird wieder geschlossen
		file.close();
	} 
	else {
		//CSV-Datei konnte nicht ausgelesen werden
		cout << "  Datei kann nicht geladen werden!" << endl;
	}
}

// Kontakte in CSV-Datei speichern
void Controller::saveContacts(vector<Person>& person) {
	//lokale Variablen
	ofstream file;

	//CSV-Datei �ffnen
	file.open("contacts.csv");

	// jeden Kontakt in eine Zeile schreiben
	for (size_t i = 0; i < person.size(); i++)
	{
		if (i < person.size() - 1) {
			file << person[i].csv_string().str();
		}
		else {
			file << person[i].last_csv_string().str();
		}
	}

	// CSV Datei schlie�en    
	file.close();
}

/********************************************************************/
/************		Actionhandler						*************/
/********************************************************************/

// Handler f�r die einzelnen Funktionen
void Controller::actionHandler(int number) {

	switch (number)
	{
		case 0: system("clear"); 
			printMenu(); 
			break;
		case 1: printContacts(person); 
			printMenu(); 
			break;
		case 2: printSingleContact(person); break;
		case 3: createContact(person); break;
		case 4: editContact(person); break;
		case 5: deleteContact(person); break;
		case 6: sortContacts(person); break;
		case 7: exitProgram(person); break;
		default: cout << endl << "  Die eingegebene Nummer war falsch!" << endl; break;
	}
}

/********************************************************************/
/************		Printfunktionen						*************/
/********************************************************************/

// Menue ausgeben
void Controller::printMenu() {
	//Ausgabe des Menues
	// "\x1B[0;32m" <<
	// "\x1B[0;37m" <<
	// << "\33[0;33m"
	// << "\x1B[0;33m"
	cout << endl << "\x1B[0;36m" << "+++++++     HAUPTMENUE       +++++++";
	cout << endl << "------------------------------------" << "\x1B[0;37m" << endl;
	
	cout << "  | 0 | Main Menue anzeigen" << endl;
	cout << "  | 1 | Alle Kontakte auflisten" << endl;
	cout << "  | 2 | Einen Kontakt auflisten" << endl;
	cout << "  | 3 | Kontakt erstellen" << endl;
	cout << "  | 4 | Kontakt bearbeiten" << endl;
	cout << "  | 5 | Kontakt loeschen" << endl;
	cout << "  | 6 | Kontakte sortieren" << endl;
	cout << "  | 7 | Programm speichern und beenden" << endl;

	//Eingabe der entsprechenden Nummer
	int menu_number;
	cout << endl << "  Gib deine Nummer ein: ";
	cin >> menu_number;

	cout << endl << "------------------------------------------------------------------------------------------------------------" << endl;

	//Actionhandler nach Eingabe ausf�hren
	actionHandler(menu_number);
}

// Alle Kontakte anzeigen
void Controller::printContacts(vector<Person>& person) {
	system("clear");
	
	cout << endl << "\x1B[0;36m" << "  Alle Kontakte: ";
	cout << endl << "------------------------------------" << "\x1B[0;37m" << endl;

	//Ausgabe des Tabellenkopf
	cout << setw(5) << " Nr." << setw(20) << "Vorname" << setw(20) << "Nachname" << setw(10) << "Alter" << setw(15) << "Ort" << endl;
	cout << "------------------------------------------------------------------------" << endl;

	for (uint32_t i = 0; i < person.size(); i++)
	{
		cout << setw(5) << to_string(i+1)+".)" << person[i].printAllPersons().str() << endl;
	}

	cout << endl << "------------------------------------------------------------------------------------------------------------" << endl;
}

// Einzelnen Kontakt anzeigen
void Controller::printSingleContact(vector<Person>& person) {
	system("clear");
	printContacts(person);
	
	cout << endl << "\x1B[0;36m" << "  Einen Kontakt auflisten";
	cout << endl << "------------------------------------" << "\x1B[0;37m" << endl;

	int tmp;
	cout << "  Gib die Nummer des gewuenschten Kontakts ein: ";
	cin >> tmp;

	cout << endl << "\x1B[1;35m" << "  Ausgabe des Kontakt " << tmp;
	cout << endl << "------------------------------" << "\x1B[0;37m";

	cout << person[tmp-1].printPerson().str();
	
	cout << endl << "------------------------------------------------------------------------------------------------------------" << endl;
	printMenu();
}

/********************************************************************************/
/************		Kontakte erstellen, bearbeiten und loeschen		*************/
/********************************************************************************/

// Kontakt erstellen
void Controller::createContact(vector<Person>& person) {
	system("clear");

	cout << endl << "\x1B[0;36m" << "  Einen Kontakt erstellen";
	cout << endl << "------------------------------------" << "\x1B[0;37m" << endl;

	string firstname, lastname, place, street, gender;
	uint32_t age, housenumber, prefix, phonenumber, postcode;

	cout << "  Gib deinen Vornamen ein: ";
	cin >> firstname;
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


	//Person anlegen und Werte �bergeben
	Person* person1 = new Person(firstname, lastname, Person::string_to_enum(gender), age, postcode, place, street, housenumber, prefix, phonenumber);
	person.push_back(*person1);

	cout << endl << "\x1B[0;32m" << "  Der Kontakt " << firstname + " " + lastname << " wurde erfolgreich erstellt!" << "\x1B[0;37m" << endl;
	cout << endl << "------------------------------------------------------------------------------------------------------------" << endl;
	printMenu();
}

// Kontakt bearbeiten
void Controller::editContact(vector<Person>& person) {
	system("clear");
	printContacts(person);
	
	cout << endl << "\x1B[0;36m" << "  Einen Kontakt bearbeiten";
	cout << endl << "------------------------------------" << "\x1B[0;37m" << endl;

	int tmp;
	cout << "  Gib die Nummer des Kontakts ein, welchen du bearbeiten moechtest: ";
	cin >> tmp;

	int tmp2;
	cout << endl << "  0.) Vorname" << endl << "  1.) Nachname" << endl << "  2.) Geschlecht" << endl << "  3.) Alter" << endl << "  4.) Postleitzahl" << endl << "  5.) Wohnort" << endl << "  6.) Strasse" << endl << "  7.) Hausnummer" << endl << "  8.) Vorwahl" << endl << "  9.) Telefonnummer" << endl;
	cout << endl << "  Gib die Nummer ein, die du bearbeiten moechtest: ";
	cin >> tmp2;

	string tmp3;

	switch (tmp2) {
		case 0: 
			cout << endl << "  Gib den neuen Vorname ein: ";
			cin >> tmp3; 
			break;
		case 1: 
			cout << endl << "  Gib den neuen Nachname ein: ";
			cin >> tmp3;
			break;
		case 2:
			cout << endl << "  Gib das neue Geschlecht ein (Man = 0, Woman = 1, Diverse = 2): ";
			cin >> tmp3;
			break;
		case 3: 
			cout << endl << "  Gib das neue Alter ein: ";
			cin >> tmp3;
			break;
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

	person[tmp - 1].editPerson(tmp2, tmp3);

	cout << endl << "\x1B[0;32m" << "  Der Kontakt " << tmp << " wurde erfolgreich bearbeitet!" << "\x1B[0;37m" << endl;
	cout << endl << "------------------------------------------------------------------------------------------------------------" << endl;
	printMenu();
}

//Kontakt loeschen
void Controller::deleteContact(vector<Person>& person) {
	system("clear");
	printContacts(person);
	
	cout << endl << "\x1B[0;36m" << "  Einen Kontakt loeschen";
	cout << endl << "------------------------------------" << "\x1B[0;37m" << endl;
	
	int tmp;
	cout << "  Gib die Nummer ein, welche du loeschen moechtest: ";
	cin >> tmp;

	person.erase(person.begin() + (tmp-1));

	cout << endl << "\x1B[0;32m" << "  Der Kontakt " << tmp << " wurde erfolgreich geloescht!" << "\x1B[0;37m" << endl;
	cout << endl << "------------------------------------------------------------------------------------------------------------" << endl;
	printMenu();
}

//Kontakte sortieren
void Controller::sortContacts(vector<Person>& person) {
	system("clear");

	cout << endl << "\x1B[0;36m" << "  Kontakte sortieren";
	cout << endl << "------------------------------------" << "\x1B[0;37m" << endl;

	int tmp;
	cout << "  0.) Vorname" << endl << "  1.) Nachname" << endl << "  2.) Alter" << endl << "  3.) Wohnort" << endl;
	cout << endl << "  Gib die Nummer ein, nach der du aufsteigend sortieren moechtest: ";
	cin >> tmp;

	switch (tmp) {
		case 0: //...;
			break;
		case 1: //...;
			break;
		case 2: //...;
			break;
		case 3: //...;
			break;
		default: cout << endl << "  Die eingegebene Nummer war falsch!" << endl; break;
	}

	cout << endl << "\x1B[0;32m" << "  Die Kontaktliste wurde erfolgreich sortiert!" << "\x1B[0;37m" << endl;
	cout << endl << "------------------------------------------------------------------------------------------------------------" << endl;
	printMenu();
}

/********************************************************************************/
/************		Programm beenden und Kontakte speichern			*************/
/********************************************************************************/

void Controller::exitProgram(vector<Person>& person) {
	system("clear");
	saveContacts(person);
	
	cout << endl << "\x1B[0;32m" << "------------------------------------------------------------";
	cout << endl << "-------------- Das Programm wird nun beendet! --------------";
	cout << endl << "------------------------------------------------------------" << "\x1B[0;37m" << endl << endl;
}

/*
//Integers sortieren
void BubbleSort(){
	int tmp;

	for (int i = 1; i < length ; i++)
	{
		for (int a = 0; a < length - i ; a++)
		{
			if (Lottozahlen[a] > Lottozahlen[a+1])
			{
				tmp = Lottozahlen[a];
				Lottozahlen[a] = Lottozahlen[a+1];
				Lottozahlen[a+1] = tmp;
			}
		}
	}
}

//Strings sortieren
void bubblesort(vector <string>& vec)
{
	string tmp;
	int n = vec.size();

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			if (vec[j + 1].compare(vec[j]) < 0) {
				tmp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = tmp;
			}
		}
	}
}
*/