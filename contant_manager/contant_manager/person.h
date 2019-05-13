#ifndef _PERSON_H_
#define _PERSON_H_

using namespace std;

namespace ContactManager {
	
	typedef enum
	{
		/// <summary>
		/// männlich
		/// </summary>
		MAN,
		/// <summary>
		/// weiblich
		/// </summary>
		WOMAN,
		/// <summary>
		/// diverse
		/// </summary>
		DIVERSE
	} GenderType;


	class Person {
	protected:
		GenderType gender;
		string firstname;
		string lastname;

		string mail;
		string telNr;
		uint8_t age;

		static uint32_t countPersons;


	public:
		Person(GenderType pGender, string pFirstname, string pLastname, uint8_t pAge);
		//Copy-Constructor
		Person(Person& pPerson);
		//Destruktor
		~Person();

		const void changeValues() {

		}

	};
	extern ostream& operator<< (ostream& os, const Person& pPerson);
	
}
#endif
