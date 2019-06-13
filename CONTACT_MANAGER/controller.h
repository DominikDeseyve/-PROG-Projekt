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

		/// <summary>Speicherpfad der CSV-Datei der Kontakte.</summary>
		string csvPath;

	public:
		/// <summary>Konstruktor der Controller-Klasse.</summary>
		Controller();
		
		/// <summary>Entscheidet auf Basis des Parameters, welcher Menüpunkt gedrückt wurde.</summary>
    	/// <param name="number">Vom Benutzer gedrückter Menüpunkt</param>    	
		void actionHandler(int number);

		/// <summary>Lädt Kontakte aus der Standard CSV-Datei.</summary>    	  			
		void loadContacts();

		/// <summary>Speichert Kontakt in die Standard CSV-Datei.</summary>    	/	
		void saveContacts();

		/// <summary>Das Hauptmenü wird in der Konsole ausgegeben.</summary>
		void printMenu();

		/// <summary>ALLE Kontakte werden ausgegeben.</summary>    		
		void printContacts();

		/// <summary>Ein EINZELNER Kontakt wird ausgegeben.</summary>    	 	
		void printSingleContact();

		/// <summary>Neuer Kontakt wird angelegt. Kontaktdaten werden durch einen Benutzerdialog eingegeben.</summary>    	
		void createContact();

		/// <summary>Ein vorhandener Kontakt wird bearbeitet. Dazu wird der Benutzer gefragt, welcher Attribute abgeändert werden sollen. Neue Kontaktdaten werden durch einen Benutzerdialog eingegeben.</summary>
		void editContact();

		/// <summary>Der Benutzer wird gefragt, welcher Kontakt gelöscht werden soll.</summary>    	 
		void deleteContact();

		/// <summary>Sortierfunktion zur Auswahl der Spalte, nach der sortiert werden soll.</summary>  
		void sortContacts();

		/// <summary>Sortiert alle Kontakte dem Vornamen nach innerhalb des Vektors nach dem Bubblesort-Algorithmus.</summary>  
		void sortFirstname();
		
		/// <summary>Sortiert alle Kontakte dem Nachnamen nach innerhalb des Vektors nach dem Bubblesort-Algorithmus.</summary>  
		void sortLastname();

		/// <summary>Sortiert alle Kontakte dem Alter nach innerhalb des Vektors nach dem Bubblesort-Algorithmus.</summary>  
		void sortAge();

		/// <summary>Sortiert alle Kontakte dem Wohnort nach innerhalb des Vektors nach dem Bubblesort-Algorithmus.</summary>  
		void sortPlace();

		/// <summary>Neue Kontaktdaten werden gespeichert und das Programm ordnungsgemäß beendet.</summary>   
		void exitProgram();

		/// <summary>Statische Funktion, welcher auf eine korrekte Eingabe des Benutzers wartet.</summary>
    	/// <param name="coutText">Text, der dem Benutzer anzeigt was er eingeben sollte.</param>  
		/// <param name="type">Definiert welche Art von Eingabe erwartet wird (STRING/INTEGER).</param>  
		/// <returns>Korrekter Text, welchen der Benutzer eingegeben hat. </returns>  
		static string waitForInput(string coutText, string type);

		/// <summary>Statische Funktion, welcher auf eine korrekte Eingabe des Benutzers innerhalb eines Zahlenbereichs wartet.</summary>
    	/// <param name="coutText">Text, der dem Benutzer anzeigt was er eingeben sollte.</param>  
		/// <param name="pMin">Minimaler Wert des Zahlenbereichs.</param>  
		/// <param name="pMax">Maximaler Wert des Zahlenbereichs.</param>  
		/// <returns>Korrekter Text, welchen der Benutzer eingegeben hat. </returns>  
		static string waitForInput(string coutText, int pMin, int pMax);

		/// <summary>Funktion zur Überprüfung, ob es sich bei dem übergebenen String um einen korrekten Integer handelt.</summary>
    	/// <param name="input">Die zu überprüfende Benutzereingabe.</param>    
		static bool checkInt(string input);

		/// <summary>Überladene Funktion, zur zusätzlichen Überprüfung ob es sich um einen korrekten Integer handelt, der zusätzlich im parametrisierten Zahlenbereich ist.</summary>
    	/// <param name="input">Die zu überprüfende Benutzereingabe.</param>    
		/// <param name="pMin">Minimum-Wert des Zahlenbereichs der überprüft werden soll.</param>   
		/// <param name="pMax">Maximum-Wert des Zahlenbereichs der überprüft werden soll.</param>   
		static bool checkInt(string input,int pMin,int pMax);

		/// <summary>Funktion zur Überprüfung, ob es sich bei dem übergebenen String um einen korrekten String handelt.</summary>
    	/// <param name="input">Die zu überprüfende Benutzereingabe.</param>    
		static bool checkString(string input);

		/// <summary>Die übergebene Benutzereingabe des Geschlechts wird zu einem Aufzählungstyp konvertiert.</summary>
    	/// <param name="tmp">Benutzereingabe des Geschlechts.</param>  
		static GenderType intToEnum(string tmp);

		/// <summary>Das gespeicherte Geschlecht wird für die Ausgabe in einen String konvertiert.</summary>
    	/// <param name="tmp">Gespeicherter Geschlechtstyp.</param>  
		static string enumToInt(GenderType tmp);

		/// <summary>Gibt Vektor mit allen vorhandenen Personen zurück.</summary>
		/// <returns>Vektor mit Personen </returns>
		vector<Person> getPersons();

		/// <summary>Der beim Start übergebene CSV-Pfad der Kontaktdaten wird übernommen. Sollte kein Startparameter vorhanden sein, bleibt der default Wert bestehen.</summary>
    	/// <param name="path">Neuer Speicherpfad der CSV-Datei</param>  
		void setCSVPath(string path);
	};
}
#endif
