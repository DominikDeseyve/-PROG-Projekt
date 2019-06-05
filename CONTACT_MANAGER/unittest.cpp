#define _UNITTEST_
#include "person.h"
#include "controller.h"

using namespace ContactManager;

using namespace std;

#define CATCH_CONFIG_FAST_COMPILE
#define CATCH_CONFIG_MAIN

#include "catch.hpp"

// kurzer Test obs laeuft
TEST_CASE("Fail test")
{
    CHECK(1 == 0);
}

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

TEST_CASE("LoadContacts")
{
  //pointer auf neues Objekt controller
  //Controller *controller = new Controller();
  //vector<Person> person = controller->getPersons();
  //CHECK(person.size() > 0);


}


TEST_CASE("actionHandler", "functions of main menu")
{

}
