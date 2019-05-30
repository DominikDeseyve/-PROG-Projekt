#define _UNITTEST_
#include <person.h>
#include <controller.h>

using namespace ContactManager;

using namespace std;

#define CATCH_CONFIG_FAST_COMPILE
#include <catch.hpp>


const int SAMPLES_PERSON_COUNT = {3};

const struct SamplesPerson
{

};

SamplesPersonn SAMPLES_PERSON[SAMPLES_PERSON_COUNT] =
{
  SamplesPerson(Rachel, Kroesen, 1, 21, 88069, Tettnang, Vogelherdbogen, 67, 07542, 939700);
  SamplesPerson(Clemens, Maier-Schmidt, 0, 18, 79098, Freiburg, Seestraße, 4, 07664, 3902521);
  SamplesPerson(Kasimir, Romer, 2, 19, 88045, Friedrichshafen, Rosiskeller, 2, 07541, 56402);
}


TEST_CASE("Constructor")
{

}

TEST_CASE("actionHandler", "functions of main menu")
{

}
