#ifndef _PERSON_H_
#define _PERSON_H_

#include <iostream>
#include <string>

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
		string place;
		string street;
		uint32_t housenumber;
		uint8_t prefix;
		uint8_t phonenumber;
		
		static uint32_t countPersons;


	public:
		Person(string pLastname, string pFirstname, GenderType pGender, uint32_t age, string place, string street, uint32_t housenumber, uint8_t prefix, uint8_t phonenumber);

		friend ostream& operator<< (ostream& os, const Person& pPerson);

		const void changeValues();

	};
	
}
#endif
