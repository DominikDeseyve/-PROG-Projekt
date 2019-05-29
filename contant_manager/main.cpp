#include <iostream>
#include <string>

#include "controller.h"
#include "person.h"


using namespace std;
using namespace ContactManager;


int main()
{
	system("CLEAR");
	cout << endl << "\x1B[1;35m" << "------------------------------------";
	cout << endl << "+++++++     Adressbuch!      +++++++";
	cout << endl << "------------------------------------" << "\x1B[0;37m" << endl << endl;

	Controller *controller = new Controller();
	return 0;
}

/*
#include "temperatur.h"

/// <summary>Erzeugt ein Element von einem Initialisierungselement.</summary>
/// <param name="other">Initialisierungselement</param>
Temperature::Temperature(const Temperature& other)
{
	kelvin = other.kelvin;
	temperaturtype = other.temperaturtype;
}

/// <summary>Erzeugt ein Element das die Temperatur °K als Basis hat.</summary>
/// <param name="value">Initialtemperatur in °K</param>
/// <returns>Objekt vom Typ Temperature</returns>
static Temperature::Temperature Temperature::inKelvin(const float value)
{
	temperaturtype = 0;
	kelvin = dynamic_cast<uint32_t>(value * 100);
}
/// <summary>Erzeugt ein Element das die Temperatur °C als Basis hat.</summary>
/// <param name="value">Initialtemperatur in °C</param>
/// <returns>Objekt vom Typ Temperature</returns>
static Temperature::Temperature Temperature::inCelsius(const float value)
{
	temperaturtype = 1;
	kelvin = dynamic_cast<uint32_t>(value * 100 + 27315);
}
/// <summary>Erzeugt ein Element das die Temperatur °F als Basis hat.</summary>
/// <param name="value">Initialtemperatur in °F</param>
/// <returns>Objekt vom Typ Temperature</returns>
static Temperature::Temperature Temperature::inFahrenheit(const float value)
{
	temperaturtype = 2;
	kelvin = dynamic_cast<uint32_t>((value - 32) * 5 / 9 * 100 + 27315);
}

/// <summary>Ändert den physikalischen Typ der Einheit.</summary>
/// <param name="temperaturtype">Physikalischer Type der Einheit</param>
void Temperature::changePhysicalUnit(const ETemperaturType temperaturtype)
{
	temperaturtype = temperaturtype;
}

/// <summary>Weist der Instanz einen neuen Wert zu. Dieser wird in die gültige physikalische Einheit abgebildet.</summary>
/// <param name="value">Neuer Wert</param>
/// <returns>Referenz auf Instanz</returns>
Temperature& operator= (const float value)
{
	switch (temperaturtype) {
	case 0: kelvin = dynamic_cast<uint32_t>(value * 100);
		break;
	case 1: kelvin = dynamic_cast<uint32_t>(value * 100 + 27315);
		break;
	case 2: kelvin = dynamic_cast<uint32_t>((value - 32) * 5 / 9 * 100 + 27315);
		break;
	}
}
/// <summary>Kopiert aus einer bestehenden Instanz den Inhalt in diese Instanz.</summary>
/// <param name="value">Neuer Wert</param>
/// <returns>Referenz auf Instanz</returns>
Temperature& operator= (const Temperature& value)
{
	kelvin = *value.kelvin;
	temperaturtype = *value.temperaturtype;
}

/// <summary>Addiert zu einer bestehenden Instanz eine Temperatur dazu. Die Temperatur muss die gleich physikalische Einheit haben.</summary>
/// <param name="value">Addent</param>
/// <returns>Referenz auf Instanz</returns>
Temperature& operator+= (const float value)
{
	switch (temperaturtype) {
	case 0: kelvin += dynamic_cast<uint32_t>(value * 100);
		break;
	case 1: kelvin += dynamic_cast<uint32_t>(value * 100 + 27315);
		break;
	case 2: kelvin += dynamic_cast<uint32_t>((value - 32) * 5 / 9 * 100 + 27315);
		break;
	}
}
/// <summary>Addiert zu einer bestehenden Instanz eine Temperatur dazu. Die physikalische Einheit wird berücksichtigt.</summary>
/// <param name="value">Addent</param>
/// <returns>Referenz auf Instanz</returns>
Temperature& operator+= (const Temperature& value)
{
	kelvin += value.kelvin;
}

/// <summary>Subtrahiert zu einer bestehenden Instanz eine Temperatur ab. Die Temperatur muss die gleich physikalische Einheit haben.</summary>
/// <param name="value">Subtrahend</param>
/// <returns>Referenz auf Instanz</returns>
Temperature& operator-= (const float value)
{
	kelvin -= value;
}
/// <summary>Subtrahiert zu einer bestehenden Instanz eine Temperatur ab. Die physikalische Einheit wird berücksichtigt.</summary>
/// <param name="value">Subtrahend</param>
/// <returns>Referenz auf Instanz</returns>
Temperature& operator-= (const Temperature& value)
{
	kelvin -= value.kelvin;
}

/// <summary>
/// Erhöht die Temperatur um 1° der jeweilig eingestellten physikalischen Einheit (Prefix).
/// </summary>
Temperature& operator++()
{
	switch (temperaturtype) {
	case 0: kelvin += dynamic_cast<uint32_t>(1 * 100);
		break;
	case 1: kelvin += dynamic_cast<uint32_t>(1 * 100 + 27315);
		break;
	case 2: kelvin += dynamic_cast<uint32_t>((1 - 32) * 5 / 9 * 100 + 27315);
		break;
	}
}
/// <summary>
/// Erhöht die Temperatur um 1° der jeweilig eingestellten physikalischen Einheit (Postfix).
/// </summary>
Temperature& operator++(int)
{
	switch (temperaturtype) {
	case 0: kelvin += dynamic_cast<uint32_t>(1 * 100);
		break;
	case 1: kelvin += dynamic_cast<uint32_t>(1 * 100 + 27315);
		break;
	case 2: kelvin += dynamic_cast<uint32_t>((1 - 32) * 5 / 9 * 100 + 27315);
		break;
	}
}

/// <summary>
/// Erniedrigt die Temperatur um 1° der jeweilig eingestellten physikalischen Einheit (Prefix).
/// </summary>
Temperature& operator--()
{
	switch (temperaturtype) {
	case 0: kelvin -= dynamic_cast<uint32_t>(1 * 100);
		break;
	case 1: kelvin -= dynamic_cast<uint32_t>(1 * 100 + 27315);
		break;
	case 2: kelvin -= dynamic_cast<uint32_t>((1 - 32) * 5 / 9 * 100 + 27315);
		break;
	}
}
/// <summary>
/// Erniedrigt die Temperatur um 1° der jeweilig eingestellten physikalischen Einheit (Postfix).
/// </summary>
Temperature& operator--(int)
{
	switch (temperaturtype) {
	case 0: kelvin -= dynamic_cast<uint32_t>(1 * 100);
		break;
	case 1: kelvin -= dynamic_cast<uint32_t>(1 * 100 + 27315);
		break;
	case 2: kelvin -= dynamic_cast<uint32_t>((1 - 32) * 5 / 9 * 100 + 27315);
		break;
	}
}

/// <summary>
/// Ausgabeoperator für iostream darf auf interne/private Daten zugreifen
/// </summary>
friend ostream& operator<< (ostream& os, const Temperature& temperature)
{
	switch (temperaturtype) {
	case 0: os << dynamic_cast<float>(kelvin / 100.0);
		break;
	case 1: os << dynamic_cast<float>(kelvin / 100.0 - 273, 15);
		break;
	case 2: os << dynamic_cast<float>((kelvin / 100.0 - 273, 15) * 9 / 5 + 32);
		break;
	}

	return os;
}

/// <summary>
/// Wandelt das Object in eine Fliesskommazahl
/// </summary>
operator float() const
{
	return this->to();
}

/// <summary>Erzeugt ein Element von einem Temperaturwert.</summary>
/// <param name="value">Initialer Temperaturwert</param>
/// <param name="temperaturtype">Physikalischer Type der Einheit</param>
Temperature::Temperature(const float value, const ETemperaturType temperaturtype = ETemperaturType::KELVIN)
{
	this->temperaturtype = temperaturtype;
	switch (this->temperaturtype) :
        case 0: kelvin = dynamic_cast<uint32_t>(value * 100);
	break;
		case 1: kelvin = dynamic_cast<uint32_t>(value * 100 + 27315);
			break;
		case 2: kelvin = dynamic_cast<uint32_t>((value - 32) * 5 / 9 * 100 + 27315);
			break;
}

/// <summary>Rechnet den internen Kelvin Wert in °K um</summary>
/// <returns>Temperatur normiert in °K</returns>
float Temperature::toKelvin() const
{
	return dynamic_cast<float>(kelvin / 100.0);
}
/// <summary>Rechnet den internen Kelvin Wert in °C um.</summary>
/// <returns>Temperatur normiert in °C</returns>
float Temperature::toCelsius() const
{
	return dynamic_cast<float>(kelvin / 100.0 - 273, 15);
}
/// <summary>Rechnet den internen Kelvin Wert in °F um.</summary>
/// <returns>Temperatur normiert in °F</returns>
float Temperature::toFahrenheit() const
{
	return dynamic_cast<float>((kelvin / 100.0 - 273, 15) * 9 / 5 + 32);
}
/// <summary>Rechnet den internen Kelvin Wert in die aktuelle phsikalische Einheit um</summary>
/// <returns>Temperatur normiert auf aktuelle phsikalische Einheit</returns>
float Temperature::to() const
{
	float returnValue;
	switch (temperaturtype) {
	case 0: returnValue = dynamic_cast<float>(kelvin / 100.0);
		break;
	case 1: returnValue = dynamic_cast<float>(kelvin / 100.0 - 273, 15);
		break;
	case 2: returnValue = dynamic_cast<float>((kelvin / 100.0 - 273, 15) * 9 / 5 + 32);
		break;
	}

	return returnValue;
}
/// <summary>Ändert den internen Temperaturwert auf Basis °K</summary>
/// <param name="value">Neuer Temperaturwert</param>
void Temperature::fromKelvin(const float value)
{
	kelvin = dynamic_cast<uint32_t>(value * 100);
}
/// <summary>Ändert den internen Temperaturwert auf Basis °C</summary>
/// <param name="value">Neuer Temperaturwert</param>
void Temperature::fromCelsius(const float value)
{
	kelvin = dynamic_cast<uint32_t>(value * 100 + 27315);
}
/// <summary>Ändert den internen Temperaturwert auf Basis °F</summary>
/// <param name="value">Neuer Temperaturwert</param>
void Temperature::fromFahrenheit(const float value)
{
	kelvin = dynamic_cast<uint32_t>((value - 32) * 5 / 9 * 100 + 27315);
}
/// <summary>Ändert den internen Temperaturwert auf Basis der aktuelle eingestellten phsikalischen Einheit</summary>
/// <param name="value">Neuer Temperaturwert</param>
void Temperature::from(const float value)
{
	switch (temperaturtype) {
	case 0: kelvin = dynamic_cast<uint32_t>(value * 100);
		break;
	case 1: kelvin = dynamic_cast<uint32_t>(value * 100 + 27315);
		break;
	case 2: kelvin = dynamic_cast<uint32_t>((value - 32) * 5 / 9 * 100 + 27315);
		break;
	}
}
*/