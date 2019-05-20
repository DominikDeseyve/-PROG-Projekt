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
		uint32_t postcode;
		string place;
		string street;
		uint32_t housenumber;
		uint32_t prefix;
		uint32_t phonenumber;
		
		static uint32_t countPersons;


	public:
		Person(string pLastname, string pFirstname, GenderType pGender, uint32_t pAge, uint32_t pPostcode, string pPlace, string pStreet, uint32_t pHousenumber, uint32_t pPrefix, uint32_t pPhonenumber);

		friend ostream& operator<< (ostream& os, const Person& pPerson);

		stringstream csv_string();
		stringstream last_csv_string();

		stringstream printAllPersons();

		stringstream printPerson();
	};
	
}
#endif
