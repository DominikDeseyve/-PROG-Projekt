#include <iostream>
#include <string>

#include "controller.h"
#include "person.h"


using namespace std;
using namespace ContactManager;


int main()
{
	// Konsole wird gecleared und der Titel "Adressbuch" wird in entsprechender Farbe ausgegeben
	system("clear");
	cout << endl << "\x1B[1;35m" << "------------------------------------";
	cout << endl << "+++++++     Adressbuch!      +++++++";
	cout << endl << "------------------------------------" << "\x1B[0;37m" << endl << endl;

	// ein Controller wird erstellt
	Controller *controller = new Controller();
	
	return 0;
}
