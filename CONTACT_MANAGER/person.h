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

	protected:
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
		// Konstruktor
		Person(string pFirstname, string pLastname, GenderType pGender, uint32_t pAge, uint32_t pPostcode, string pPlace, string pStreet, uint32_t pHousenumber, uint32_t pPrefix, uint32_t pPhonenumber);


		// Getter
		string& getFirstname() {
			return firstname;
		}

		string& getLastname() {
			return lastname;
		}

		uint32_t& getAge() {
			return age;
		}

		string& getPlace() {
			return place;
		}

		// sonstige Methoden
		stringstream csv_string();

		void editPerson(int ind, string input);

		stringstream printAllPersons();

		stringstream printPerson();

	
	};

}
#endif
