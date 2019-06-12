#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

/** \mainpage
* Unser Contact - Manager hilft Ihnen eine übersichtliche
* Verwaltung ihrer Kontakte zu haben.
* Durch drücken der jeweiligen Menütaste
* können sie u. a. neue Kontakte erstellen oder vorhandene Kontakte bearbeiten.
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
		/// <summary>Vektor für die Liste ALLER Personen.</summary>
		vector<Person> person;

		string csvPath;

	public:
		// Konstruktor
		Controller();
		
		/// <summary>Entscheidet auf Basis des Parameters, welcher Menüpunkt gedrückt wurde.</summary>
    	/// <param name="number">Vom Benutzer gedrückter Menüpunkt</param>    	
		void actionHandler(int number);

		/// <summary>Lädt Kontakte aus der Standard CSV-Datei.</summary>
    	/// <param name="person">Alle Personen im Vector gespeichert.</param>    			
		void loadContacts();

		/// <summary>Speichert Kontakt in die Standard CSV-Datei.</summary>
    	/// <param name="person">Alle Personen im Vector gespeichert.</param>    	
		void saveContacts(vector<Person>& person);

		/// <summary>Das Hauptmenü wird in der Konsole ausgegeben.</summary>
		void printMenu();

		/// <summary>ALLE Kontakte werden ausgegeben.</summary>
    	/// <param name="person">Alle Personen im Vector gespeichert.</param>    	
		void printContacts(vector<Person>& person);

		/// <summary>Ein EINZELNER Kontakt wird ausgegeben.</summary>
    	/// <param name="person">Alle Personen im Vector gespeichert.</param>    	
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
		static bool checkInt(string input,int pMin,int pMax);

		static bool checkString(string input);

		//Convert Funktionen
		static GenderType intToEnum(string tmp);
		static string enumToInt(GenderType tmp);

		vector<Person> getPersons();
		void setCSVPath(string path);
	};
}
#endif
