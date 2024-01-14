#include "../headers/analyticModule.hpp" 

Analyzer::Analyzer()
{
    this->flowStartedCount = 0;
    this->flowCompletedCount = 0;
}

void Analyzer::update(int flag)
{
    if (flag == FLOW_STARTED_FLAG) {
        this->flowStartedCount++;
    }
    if (flag == FLOW_COMPLETED_FLAG) {
        this->flowCompletedCount++;
    }
    if (flag == CLEAR) {
        this->screens.clear();
        this->errorCount.clear();
        this->skippedCount.clear();
    }
}

void Analyzer::update(string stepName, int errors, int skips)
{
    this->screens.push_back(stepName);
    this->skippedCount.push_back(skips);
    this->errorCount.push_back(errors);
}

void Analyzer::display()
{
    cout<<"This flow has been started "<<this->flowStartedCount<<" times.\n";
    cout<<"This flow has been copleted "<<this->flowCompletedCount<<" times.\n\n";

    cout<<left<<setw(30)<<"SCREEN"
        << std::setw(15)<<"SKIPS"
        << std::setw(15)<<"ERRORS" << "\n";

    for (int i = 0; i < screens.size(); i++) {
        cout<<left<<setw(30)<<screens[i]
            <<setw(15)<<skippedCount[i]
            <<setw(15)<<errorCount[i] << "\n";
    }

    cout<<"\n\nPress [ENTER] to continue.";
    getchar();
}
