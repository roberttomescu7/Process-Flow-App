#include "../headers/flow.hpp"

void Flow::runFlow()
{
    for (Step* step : this->steps) {
        step->run(cout);
    }
}

void Flow::addStep(Step* stepToAdd)
{
    this->steps.push_back(stepToAdd);
}

vector<Step*>* Flow::getSteps()
{
    return &this->steps;
}
