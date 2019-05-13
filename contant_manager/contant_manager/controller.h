#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <iostream>
#include <string>
#include <list>

#include "person.h"

using namespace std;

namespace ContactManager {

	class Controller {
	
	private:
		int menu_number;
		bool sys_status = true;
		list<Person> person;

	public:

		Controller();

		void printMenu(int& menu_number);
		void actionHandler(bool& sys_status);
		void loadContacts();

		/// <summary>Speichert alle Kontakte ab</summary>
		/// <param name="value">Noch keinen</param>
		/// <returns>Gibt den Status zurück ob der Speichervorgang erfolgreich abgeschlossen wurde</returns>
		void saveContacts();

		void printContacts();
	};
}
#endif