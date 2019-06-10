#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

/** \mainpage
* Die Klasse Temperature verwaltet Temperaturen unabhängig von der
* physikalischen Einheit und formatiert je nach Einstellung
* den Wert in die passende physikalische Einheit um.
* Basistemperatur ist °K (Kelvin).
* \author Robin Fricker, Anna Kroesen, Dominik Deseyve
* \date 14. Mai 2019
*/

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

		/// <summary>Entscheidet auf Basis des Parameters, welcher Menüpunkt gedrückt wurde.</summary>
    	/// <param name="number">Vom Benutzer gedrückter Menüpunkt</param>    	
		void actionHandler(int number);

		/// <summary>Lädt Kontakte aus der Standard CSV-Datei.</summary>
    	/// <param name="person">Alle Personen im Vector gespeichert.</param>    			
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

		// CheckFunktionen
		static bool checkInt(string input);
		static bool checkString(string input);

		vector<Person> getPersons();
	};
}
#endif
