#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <istream>

#include "controller.h"
#include "person.h"

using namespace std;
using namespace ContactManager;

Controller::Controller(){
	loadContacts();

	while (sys_status) {
		printMenu(menu_number);
		actionHandler(sys_status);
	}
	
	//printContacts();
}

void Controller::printMenu(int &menu_number) {
	cout << "++++++ MAIN - MENU ++++++" << endl;
	cout << "0 | Show main menu" << endl;
	cout << "1 | Print all contacts" << endl;
	cout << "2 | Print single contact" << endl;
	cout << "3 | Create new contact" << endl;
	cout << "4 | Edit contact" << endl;
	cout << "5 | Delete single contact" << endl;
	cout << "6 | Close Application" << endl;

	cout << endl << "Enter your number: ";
	cin >> menu_number;
}

void actionHandler(bool &sys_status) {
	int i = 0;
	switch (i)
	{
	case 0: cout << "Test";break;
	default: cout << endl << "Your number was wrong!"; break;
	}
}

void Controller::printContacts() {
	list<Person>::iterator iter = person.begin();
	while (iter != person.end())
	{
		Person& s = *iter;
		cout << s << endl;
		iter++;
	}
}

void Controller::loadContacts() {
	ifstream file;
	file.open("contacts.csv");

	string line;
	char token = ';';

	if (file.is_open()) {
		while (getline(file, line)) {
			cout << endl;

			stringstream sStream(line);
			string tmp;
			vector<string> tmp_vector;

			while (getline(sStream, tmp, token)) {
				tmp_vector.push_back(tmp);
			}
			
			GenderType gender;
			switch (stoi(tmp_vector[2]))
			{
			case 0: gender = GenderType::MAN; break;
			case 1: gender = GenderType::WOMAN; break;
			case 2: gender = GenderType::DIVERSE; break;
			}
			Person* person1 = new Person(tmp_vector[0], tmp_vector[1], gender, stoi(tmp_vector[3]), tmp_vector[4], tmp_vector[5], stoi(tmp_vector[6]), stoi(tmp_vector[7]), stoi(tmp_vector[8]));
			person.push_front(*person1);
		}
		file.close();
	}
	else {
		cout << "Unable to open file" << endl;
	}	
}

void Controller::saveContacts() {

}
