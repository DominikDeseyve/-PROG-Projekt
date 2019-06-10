#define _UNITTEST_
#include "person.h"
#include "controller.h"

using namespace ContactManager;

using namespace std;

#define CATCH_CONFIG_FAST_COMPILE
#define CATCH_CONFIG_MAIN

#include "catch.hpp"

// kurzer Test obs laeuft
/* TEST_CASE("Fail test")
{
    CHECK(1 == 0);
}
*/
TEST_CASE("Pass Tests")
{
    CHECK(1 == 1);
}

/*
const int SAMPLES_PERSON_COUNT = {3};

const struct SamplesPerson
{
  string firstname;
  string lastname;
  GenderType gender;
  uint32_t age;
  uint32_t postcode;
  string place;
  string street;
  uint32_t housenumber;
  uint32_t prefix;
  uint32_t phonenumber;

  SamplesPerson(const string firstname, const string lastname, const GenderType gender, const uint32_t age,
    const uint32_t age, const uint32_t postcode, const string place, const string street,
    const uint32_t housenumber, const uint32_t prefix, const uint32_t phonenumber)
  {

  }

};

SamplesPersonn SAMPLES_PERSON[SAMPLES_PERSON_COUNT] =
{
  SamplesPerson(Rachel, Kroesen, 1, 21, 88069, Tettnang, Vogelherdbogen, 67, 07542, 939700);
  SamplesPerson(Clemens, Maier-Schmidt, 0, 18, 79098, Freiburg, Seestraße, 4, 07664, 3902521);
  SamplesPerson(Kasimir, Kalbrecht, 2, 19, 88045, Friedrichshafen, Rosiskeller, 2, 07541, 56402);
}
*/

/*
TEST_CASE("loadContacts")
{
  //pointer auf neues Objekt controller
  Controller *controller = new Controller();
  vector<Person> person = controller->getPersons();
  CHECK(person.size() > 0);


}
*/

// methods in person.cpp
TEST_CASE("intToEnum")
{
    SECTION("maennlich")
    {
      string gender = "0";
      GenderType tmp = Controller::intToEnum(gender);
      CHECK(tmp == GenderType::MAN);
    }

    SECTION("weiblich")
    {
      string gender = "1";
      GenderType tmp = Controller::intToEnum(gender);
      CHECK(tmp == GenderType::WOMAN);
    }

    SECTION("divers")
    {
      string gender = "2";
      GenderType tmp = Controller::intToEnum(gender);
      CHECK(tmp == GenderType::DIVERSE);
    }

    SECTION("other")
    {
      string gender = "5";
      GenderType tmp = Controller::intToEnum(gender);
      CHECK(tmp == GenderType::DIVERSE);
    }

    SECTION("emtpy")
    {
      string gender;
      GenderType tmp = Controller::intToEnum(gender);
      CHECK(tmp == GenderType::DIVERSE);
    }

    SECTION("text")
    {
      string gender = "Ich bin ein Mann";
      GenderType tmp = Controller::intToEnum(gender);
      CHECK(tmp == GenderType::DIVERSE);
    }

}

TEST_CASE("enumToInt")
{
    SECTION("maennlich")
    {
      GenderType gender = MAN;
      string tmp = Controller::enumToInt(gender);
      CHECK(tmp == "maennlich");
    }

    SECTION("weibich")
    {
      GenderType gender = WOMAN;
      string tmp = Controller::enumToInt(gender);
      CHECK(tmp == "weiblich");
    }

    SECTION("divers")
    {
      GenderType gender = DIVERSE;
      string tmp = Controller::enumToInt(gender);
      CHECK(tmp == "divers");
    }

}


// methods in controller.cpp
TEST_CASE("checkString")
{
    // correct input
    SECTION("normal")
    {
      string input = "Anna";
      bool validate = Controller::checkString(input);
      CHECK(validate == true);
    }

    SECTION("hyhpen", "Double Name")
    {
      string input = "Anna-Rosa";
      bool validate = Controller::checkString(input);
      CHECK(validate == true);
    }


    // wrong input
    SECTION("number", "String with numbers")
    {
      string input = "Anna1234567890";
      bool validate = Controller::checkString(input);
      CHECK(validate == false);
    }

    SECTION("empty")
    {
      string input;
      bool validate = Controller::checkString(input);
      CHECK(validate == false);
    }

    SECTION("longInput")
    {
      string input = "Robindominiklukasstefanjoeyjanfelixrobertdanielmatthiaskasimirleonthongkevinronnicojohannes";
      bool validate = Controller::checkString(input);
      CHECK(validate == false);
    }

    SECTION("special", "Input with special characters")
    {
      string input = "Anna#!?$%^&*(hi)+_=";
      bool validate = Controller::checkString(input);
      CHECK(validate == false);
    }

    SECTION("single", "single charakter")
    {
      string input = "P";
      bool validate = Controller::checkString(input);
      CHECK(validate == false);
    }
}

TEST_CASE("checkInt")
{
    // correct input
    SECTION("normal")
    {
      string input = "123";
      bool validate = Controller::checkInt(input);
      CHECK(validate == true);
    }

    // wrong input
    SECTION("character", "input with characters")
    {
      string input = "3abcDEFG";
      bool validate = Controller::checkInt(input);
      CHECK(validate == false);
    }

    SECTION("negative", "negative numbers")
    {
      string input = "-300";
      bool validate = Controller::checkInt(input);
      CHECK(validate == false);
    }

    SECTION("long", "too long number")
    {
      string input = "19487520848123456789009876543211234";
      bool validate = Controller::checkInt(input);
      CHECK(validate == false);
    }

    SECTION("special", "number with special character")
    {
      string input = "13!@#$%^&*()_";
      bool validate = Controller::checkInt(input);
      CHECK(validate == false);
    }

    SECTION("float")
    {
      string input = "82.41";
      bool validate = Controller::checkInt(input);
      CHECK(validate == false);
    }
}
