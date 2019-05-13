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

		list<Person> person;

	public:

		Controller() {

			GenderType gender = GenderType::MAN;
			string firstname = "Max";
			string lastname = "Musterman";
			Person* person1 = new Person(gender, firstname, lastname, 18);

			person.push_front(*person1);

			list<Person>::iterator iter = person.begin();
			while (iter != person.end())
			{

				Person& s = *iter;
				cout << s << endl;
				iter++;
			}
		}

		void printMenu() {
			cout << "++++++ MAIN - MENU ++++++ \n";
			cout << "0 | Show Main Menu \n";
			cout << "1 | Print All Contacts \n";

			cout << "9 | Close Application \n";
		}

		void loadContacts() {

		}

		/// <summary>Speichert alle Kontakte ab</summary>
		/// <param name="value">Noch keinen</param>
		/// <returns>Gibt den Status zurück ob der Speichervorgang erfolgreich abgeschlossen wurde</returns>
		void saveContacts() {

		}


	};
}
#endif