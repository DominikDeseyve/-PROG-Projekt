#include <iostream>
#include <string>

#include "controller.h"
#include "person.h"


using namespace std;
using namespace ContactManager;


int main()
{
	cout << endl << "\x1B[1;35m" << "------------------------------------";
	cout << endl << "+++++++     Adressbuch!      +++++++";
	cout << endl << "------------------------------------" << "\x1B[0;37m" << endl << endl;

	Controller *controller = new Controller();
	return 0;
}
