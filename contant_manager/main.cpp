#include <iostream>
#include <string>
#include <Windows.h>

#include "controller.h"
#include "person.h"


using namespace std;
using namespace ContactManager;

//uint32_t Person::countPersons = { 0 };

int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	cout << endl << "------------------------------------";
	cout << endl << "+++++++     Adressbuch!      +++++++";
	cout << endl << "------------------------------------" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	Controller *controller = new Controller();
	return 0;
}
