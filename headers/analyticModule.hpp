#ifndef ANALYTIC_MODULE_HPP
#define ANALYTIC_MODULE_HPP

// Define flags
#define FLOW_STARTED_FLAG 1
#define FLOW_COMPLETED_FLAG 2
#define CLEAR 3

#include <iostream>
#include <vector>
#include "observer.hpp"

using namespace std;

class Analyzer : public Observer
{
    private:
        int flowStartedCount;
        int flowCompletedCount;
        vector<string> screens;
        vector<int> skippedCount;
        vector<int> errorCount;
        
    public:
        Analyzer();
        ~Analyzer() = default;
        void update(int flag) override;
        void update(string stepName, int errors, int skips) override;
        void display();
};

#endif