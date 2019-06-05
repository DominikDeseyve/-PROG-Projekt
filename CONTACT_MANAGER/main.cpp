#include <iostream>
#include <string>

#include "controller.h"
#include "person.h"

/*
#include "easylogging++.h"
INITIALIZE_EASYLOGGINGPP
*/

using namespace std;
using namespace ContactManager;


int main()
{
	/*
	//Laedt das Konfigurationsfile und konfiguriert die Logger
	el::Configurations conf("logging.ini");
	//Schaltet Mechanismus aus der das Programm bei fatalem Error beendet
	el::Loggers::addFlag(el::LoggingFlag::DisableApplicationAbortOnFatalLog);
	//Bei Systemcrash wird der Crashgrund in der Log Datei noch hinterlegt
	el::Loggers::addFlag(el::LoggingFlag::LogDetailedCrashReason);
	//Falls Bildschirmausgabe, dann farbig
	el::Loggers::addFlag(el::LoggingFlag::ColoredTerminalOutput);
	//Uebertraegt die Einstellungen an die Logger die laufen
	el::Loggers::reconfigureLogger("default", conf);
	el::Loggers::reconfigureAllLoggers(conf);

	LOG(INFO) << "A message with infos";
    LOG(DEBUG) << "A message with debugging information";
    LOG(WARNING) << "A message with warning information";
    LOG(ERROR) << "A message with errors";
    LOG(FATAL) << "A message with fatal errors";
	*/

	// Konsole wird gecleared und der Titel "Adressbuch" wird in entsprechender Farbe ausgegeben
	system("clear");
	cout << endl << "\x1B[1;35m" << "------------------------------------";
	cout << endl << "+++++++     Adressbuch!      +++++++";
	cout << endl << "------------------------------------" << "\x1B[0;37m" << endl << endl;

	// ein Controller wird erstellt
	Controller *controller = new Controller();
	controller->printMenu();

	return 0;
}
