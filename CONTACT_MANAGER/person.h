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
		/// m�nnlich (0)
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
		string firstname;
		string lastname;
		GenderType gender;
		uint32_t age;
		uint32_t postcode;
		string place;
		string street;
		uint32_t housenumber;
		uint32_t prefix;
		uint32_t phonenumber;


	public:
		Person(string pFirstname, string pLastname, GenderType pGender, uint32_t pAge, uint32_t pPostcode, string pPlace, string pStreet, uint32_t pHousenumber, uint32_t pPrefix, uint32_t pPhonenumber);


		//GETTER UND SETTER
		uint32_t& getAge() {
			return age;
		}

		void setAge(uint32_t& age) {
			this->age = age;
		}


		stringstream csv_string();
		stringstream last_csv_string();

		void editPerson(int ind, string input);

		stringstream printAllPersons();

		stringstream printPerson();

		static GenderType string_to_enum(string tmp);
		static string enum_to_string(GenderType tmp);
	};

}
#endif