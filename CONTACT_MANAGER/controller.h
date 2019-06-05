#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <iostream>
#include <string>
#include <vector>

#include "person.h"

using namespace std;

namespace ContactManager {

	class Controller {
	
	private:
		// Vector für die Liste der Personen
		vector<Person> person;

	public:
		// Konstruktor
		Controller();

		void actionHandler(int number);

		// Laden und Speichern der Kontakte (aus/in CSV-Datei)
		void loadContacts(vector<Person>& person);
		void saveContacts(vector<Person>& person);

		// Menue ausgeben
		void printMenu();

		// Alle Kontakte und einzelnen Kontakt ausgeben
		void printContacts(vector<Person>& person);
		void printSingleContact(vector<Person>& person);

		// Kontakt erstellen, bearbeiten, loeschen und sortieren
		void createContact(vector<Person>& person);
		void editContact(vector<Person>& person);
		void deleteContact(vector<Person>& person);
		void sortContacts(vector<Person>& person);

		// sortFirstname, sortLastname, sortAge und sortPlace
		void sortFirstname(vector<Person>& person);
		void sortLastname(vector<Person>& person);
		void sortAge(vector<Person>& person);
		void sortPlace(vector<Person>& person);

		// Programm beenden
		void exitProgram(vector<Person>& person);

		vector<Person> getPersons(vector<Person>& person);
	};
}
#endif
