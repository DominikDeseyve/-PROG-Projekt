using namespace std;

class Controller {
private:

	list<Person> person;

public:

	Controller() {
		bool isMan = true;
		string firstname = "Max";
		string lastname = "Musterman";
		Person* person1 = new Person(isMan, firstname, lastname, 18);

		person.push_front(*person1);

		list<Person>::iterator iter = person.begin();		
		while (iter != person.end())
		{
		
			Person& s = *iter;
			cout << s.print() << endl;			
			iter++;
		}
	}

	void printMenu() {
		cout << "++++++ MAIN - MENU ++++++ \n";
		cout << "0 | Show Main Menu \n";
		cout << "1 | Print All Contacts \n";
	}

	void loadContacts() {

	}

	/// <summary>Speichert alle Kontakte ab</summary>
    /// <param name="value">Noch keinen</param>
    /// <returns>Gibt den Status zurück ob der Speichervorgang erfolgreich abgeschlossen wurde</returns>
	void saveContacts() {

	}


};