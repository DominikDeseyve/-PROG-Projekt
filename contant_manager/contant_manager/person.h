#ifndef _TEMPERATUR_H_
#define _TEMPERATUR_H_
#include <string>

using namespace std;

typedef enum
{
	/// <summary>
	/// SI Basiseinheit, nach Lord Kelvin
	/// </summary>
	KELVIN,
	/// <summary>
	/// Nach Anders Celsius
	/// </summary>
	CELSIUS,
	/// <summary>
	/// SAE, nach Daniel Gabriel Fahrenheit
	/// </summary>
	FAHRENHEIT
} ETemperaturType;


class Person {
private:
	bool isMan;
	string firstname;

	string lastname;

	string mail;
	string telNr;
	uint8_t age;


public:
	Person(bool pIsMan, string pFirstname, string pLastname, uint8_t pAge) {
		this->isMan = pIsMan;
		this->firstname = pFirstname;
		this->lastname = pLastname;
		this->age = pAge;
	}
	//Copy-Constructor
	Person() {

	}

	string print() {
		return this->firstname + " " + this->lastname + " | m | " + to_string(this->age);
	}




};
#endif
