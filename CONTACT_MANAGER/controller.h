#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <iostream>
#include <string>
#include <vector>

#include "person.h"

using namespace std;

namespace ContactManager {

	class Controller {

	private:
		vector<Person> person;

	public:
		Controller();

		void actionHandler(int number);

		void loadContacts(vector<Person>& person);
		void saveContacts(vector<Person>& person);

		void printMenu();
		void printContacts(vector<Person>& person);
		void printSingleContact(vector<Person>& person);

		void createContact(vector<Person>& person);
		void editContact(vector<Person>& person);
		void deleteContact(vector<Person>& person);
		void sortContacts(vector<Person>& person);

		void exitProgram(vector<Person>& person);

		void getPersons();

	};
}
#endif
