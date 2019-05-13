#include <iostream>
#include <string>

#include "controller.h"
#include "person.h"

using namespace std;
using namespace ContactManager;

uint32_t Person::countPersons = { 0 };

int main()
{
   cout << "------------ ADRESSBUCH ------------" << endl; 

	Controller *controller = new Controller();

	return 0;
}

template <class T>
inline T Methodenname(const T &a, const T &b) {
	return a * b;
}

