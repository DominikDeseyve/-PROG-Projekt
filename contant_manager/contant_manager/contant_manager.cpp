#include <iostream>
#include <string>
#include <list>

#include "person.h"
#include "controller.h"

using namespace std;

int main()
{
    std::cout << "------------ ADRESSBUCH ------------\n"; 

	Controller *controller = new Controller();
	controller->printMenu();
}

