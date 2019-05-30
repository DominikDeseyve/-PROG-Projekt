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
  SamplesPerson();
  SamplesPerson();
  SamplesPerson();
}


TEST_CASE("Constructor")
{

}
