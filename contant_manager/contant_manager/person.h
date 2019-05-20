#ifndef _PERSON_H_
#define _PERSON_H_

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

namespace ContactManager {
	
	typedef enum
	{
		/// <summary>
		/// männlich (0)
		/// </summary>
		MAN,
		/// <summary>
		/// weiblich (1)
		/// </summary>
		WOMAN,
		/// <summary>
		/// diverse (2)
		/// </summary>
		DIVERSE
	} GenderType;


	class Person {
	protected:
		string lastname;
		string firstname;
		GenderType gender;
		uint32_t age;
		uint8_t postcode;
		string place;
		string street;
		uint32_t housenumber;
		uint8_t prefix;
		uint8_t phonenumber;
		
		static uint32_t countPersons;


	public:
		Person(string pLastname, string pFirstname, GenderType pGender, uint32_t pAge, uint8_t pPostcode, string pPlace, string pStreet, uint32_t pHousenumber, uint8_t pPrefix, uint8_t pPhonenumber);

		friend ostream& operator<< (ostream& os, const Person& pPerson);

		stringstream getCSV_string();

		stringstream printAllPersons();
	};
	
}
#endif
