#include <iostream>
//#include "../headers/stepFactory.hpp"
#include "../headers/flow.hpp"

int main()
{
    StepFactory factory;
    Flow flow1;

    Step* step1 = factory.createTitleStep();
    flow1.addStep(step1);
    Step* step2 = factory.createOutputStep(flow1.getSteps());
    flow1.addStep(step2);   


    cout<<"=========================\n";

    flow1.runFlow();

    return 0;
}