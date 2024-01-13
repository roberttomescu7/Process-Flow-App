#ifndef FLOW_HPP
#define FLOW_HPP

#include <chrono>
#include <ctime>
#include "stepFactory.hpp"
#include "analyticModule.hpp"

class Flow
{
    private:
        vector<Step*> steps;
        string flowName;
        chrono::time_point<chrono::system_clock> timestamp;
        Analyzer analyzer;
    
    public:
        Flow();
        ~Flow();
        void runFlow();
        void addStep(Step* stepToAdd);
        vector<Step*>* getSteps();
        void setFlowName();
        string getFlowName();
        string getTimestamp();
        Analyzer* getAnalyzer();
        Observer* getObserver();
};

#endif