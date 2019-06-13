#ifndef _PERSON_H_
#define _PERSON_H_

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

namespace ContactManager {
	/// <summary>Aufzählungstyp zur Bestimmung des Geschlechts.</summary>
	typedef enum
	{
		/// <summary>männlich (0)</summary>
		MAN,
		/// <summary>weiblich (1)</summary>
		WOMAN,
		/// <summary>diverse (2)</summary>
		DIVERSE
	} GenderType;


	class Person {

	private:
		// Attribute
		/// <summary>Vorname der Person</summary>
		string firstname;

		/// <summary>Nachname der Person</summary>
		string lastname;

		/// <summary>Geschlechtstyp der Person</summary>
		GenderType gender;

		/// <summary>Alter der Person</summary>
		uint32_t age;

		/// <summary>Postleitzahl der Person</summary>
		uint32_t postcode;

		/// <summary>Wohnort der Person</summary>
		string place;

		/// <summary>Straße der Person</summary>
		string street;

		/// <summary>Hausnummer der Person</summary>
		uint32_t housenumber;

		/// <summary>Prefix der Telefonnummer der Person</summary>
		uint32_t prefix;

		/// <summary>Suffix der Telefonnummer der Person</summary>
		uint32_t phonenumber;

	public:
		/// <summary>Kostruktor zur Erstellung eines Personen-Objektes</summary>
		/// <param name="pFirstname">Vorname der zu erstellenden Person</param>    	
		/// <param name="pLastname">Nachname der zu erstellenden Person</param>  
		/// <param name="pGender">Geschlecht der zu erstellenden Person</param>  
		/// <param name="pAge">Alter der zu erstellenden Person</param>  
		/// <param name="pPostcode">Postleitzahl der zu erstellenden Person</param>  
		/// <param name="pPlace">Wohnort der zu erstellenden Person</param>  
		/// <param name="pStreet">Wohnstraße der zu erstellenden Person</param>  
		/// <param name="pHousenumber">Hausnummer der Anschrift der zu erstellenden Person</param>  
		/// <param name="pPrefix">Prefix der Telefonnummer der zu erstellenden Person</param>  
		/// <param name="pPhonenumber">Telefonnummer der zu erstellenden Person</param>  
		Person(string pFirstname, string pLastname, GenderType pGender, uint32_t pAge, uint32_t pPostcode, string pPlace, string pStreet, uint32_t pHousenumber, uint32_t pPrefix, uint32_t pPhonenumber);


		/*************************************/
		/********** GET - METHODEN ********** /
		/*************************************/
		/// <summary>GET-Methode für den Vornamen des Kontaktes.</summary>
		/// <returns>Vorname des Kontaktes als String</returns>
		const string& getFirstname() {
			return firstname;
		}
		/// <summary>GET-Methode für den Nachnamen des Kontaktes.</summary>
		/// <returns>Nachname des Kontaktes als String</returns>
		const string& getLastname() {
			return lastname;
		}

		/// <summary>GET-Methode für das Alter des Kontaktes.</summary>
		/// <returns>Alter des Kontaktes als Integer</returns>
		const uint32_t& getAge() {
			return age;
		}
		
		/// <summary>GET-Methode für den Wohnort des Kontaktes.</summary>
		/// <returns>Wohnort des Kontaktes als String</returns>
		const string& getPlace() {
			return place;
		}

		/*************************************/
		/********** HILFSMETHODEN ************/
		/*************************************/
		/// <summary>Bereit die Ausgabe in die Speicherdatei eines einzelnen Kontaktes vor.</summary>
		/// <returns>Stringstream, welcher als Zeile in der CSV-Datei platziert werden kann</returns>
		stringstream csv_string();

		/// <summary>Ändert die vom Benutzer eingegeben Kontaktdaten aufgrund der Parameter ab</summary>
		/// <param name="ind">Index der Eigenschaft des Kontaktes, welche geändert werden soll.</param>  
		/// <param name="input">Neuert Wert der Kontakteigenschaft</param>  
		void editPerson(int ind, string input);

		/// <summary>Bereitet die Ausgabe ALLER Kontakte vor.</summary>
		/// <returns>Stringstream, mit allen Kontaktdaten</returns>
		stringstream printAllPersons();

		/// <summary>Bereitet die Ausgabe eines EINZELNEN Kontaktes vor.</summary>
		/// <returns>Stringstream, mit einem Kontaktdatensatz</returns>
		stringstream printPerson();
	};
}
#endif
