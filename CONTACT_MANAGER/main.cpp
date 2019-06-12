#include <iostream>
#include <string>
#include <cstring>

#include "controller.h"
#include "person.h"

using namespace std;
using namespace ContactManager;


int main(int argc, char *argv[])
{
	// Konsole wird gecleared und der Titel "Adressbuch" wird in entsprechender Farbe ausgegeben
	system("clear");
	cout << endl << "\x1B[1;35m" << "------------------------------------";
	cout << endl << "+++++++     Adressbuch!      +++++++";
	cout << endl << "------------------------------------" << "\x1B[0;37m" << endl << endl;

	// ein Controller wird erstellt
	Controller *controller = new Controller();	

	//Startparamter überprüfen	
	if(argc == 3) {		
		if(strcmp(argv[1],"-csv") == 0) {				
			controller->setCSVPath(argv[2]);		
		}
	}	
	
	controller->loadContacts();
	controller->printMenu();

	return 0;
}

