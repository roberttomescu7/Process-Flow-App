#include "../headers/flow.hpp"

// FLOW

// Constructor for Flow
Flow::Flow()
{
    // Clear the console screen
    system("clear");

    // Set the timestamp to the current system time
    this->timestamp = chrono::system_clock::now();

    // Prompt user to set the flow name
    this->setFlowName();
}

// Destructor for Flow
Flow::~Flow()
{
    // Clean up allocated memory for steps
    for (Step* step : this->steps) {
        delete step;
        cout << "DELETED\n";
    }
}

// Run the entire flow
void Flow::runFlow()
{
    // Execute each step in the flow
    for (Step* step : this->steps) {
        step->run(cout);
    }
}

// Add a step to the flow
void Flow::addStep(Step* stepToAdd)
{
    this->steps.push_back(stepToAdd);
}

// Get a pointer to the vector of steps in the flow
vector<Step*>* Flow::getSteps()
{
    return &this->steps;
}

// Set the name of the flow
void Flow::setFlowName()
{
    cout << "Flow name: ";
    getline(cin, this->flowName);
}

// Get the name of the flow
string Flow::getFlowName()
{
    return this->flowName;
}

// Get a string representation of the timestamp
string Flow::getTimestamp()
{
    // Convert the timestamp to a time_t and then to a string
    auto time = std::chrono::system_clock::to_time_t(timestamp);
    return std::ctime(&time);
}

// Get a pointer to the observer associated with the flow
Observer* Flow::getObserver()
{
    return &this->analyzer;
}

// Get a pointer to the analyzer associated with the flow
Analyzer* Flow::getAnalyzer()
{
    return &this->analyzer;
}
