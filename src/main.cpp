#include <iostream>
#include "../headers/stepFactory.hpp"

int main()
{
    StepFactory* factory = new StepFactory;
    Step *step1 = factory->createTitleStep();

    return 0;
}