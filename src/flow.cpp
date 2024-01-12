#include "../headers/flow.hpp"

Flow::Flow()
{
    system("clear");
    this->timestamp = chrono::system_clock::now();
    this->setFlowName();
}

Flow::~Flow()
{
    for (Step* step : this->steps) {
        delete step;
        cout<<"DELETED\n";
    }
}

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

void Flow::setFlowName()
{
    cout<<"Flow name: ";
    getline(cin, this->flowName);
}

string Flow::getFlowName()
{
    return this->flowName;
}

string Flow::getTimestamp()
{
    auto time = std::chrono::system_clock::to_time_t(timestamp);
    return std::ctime(&time);
}
