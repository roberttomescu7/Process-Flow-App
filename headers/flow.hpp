#ifndef FLOW_HPP
#define FLOW_HPP

#include "stepFactory.hpp"

class Flow
{
    private:
        vector<Step*> steps;
    
    public:
        Flow() {}
        void runFlow();
        void addStep(Step* stepToAdd);
        vector<Step*>* getSteps();
};

#endif