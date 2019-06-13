
#include "person.h"
#include "controller.h"

using namespace ContactManager;

using namespace std;

#define CATCH_CONFIG_FAST_COMPILE
#define CATCH_CONFIG_MAIN

#include "catch.hpp"

// methods in controller.cpp
TEST_CASE("loadContacts")
{
  //pointer auf neues Objekt controller
  Controller *controller = new Controller();
  controller->loadContacts();
  vector<Person> person = controller->getPersons();
  CHECK(person.size() > 0);
}


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

    SECTION("weiblich")
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

// Funktionenüberladung von checkInt
TEST_CASE("checkRange", "check if int between min and max")
{
    SECTION("middle")
    {
      string input = "5";
      int min = 1;
      int max = 10;
      bool validate = Controller::checkInt(input, min, max);
      CHECK(validate == true);
    }

    SECTION("under")
    {
      string input = "0";
      int min = 1;
      int max = 10;
      bool validate = Controller::checkInt(input, min, max);
      CHECK(validate == false);
    }

    SECTION("over")
    {
      string input = "11";
      int min = 1;
      int max = 10;
      bool validate = Controller::checkInt(input, min, max);
      CHECK(validate == false);
    }
}
