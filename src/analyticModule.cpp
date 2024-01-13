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
    cout<<"SCREEN\t\t\tSkips count\tErrors count\n";

    for (int i = 0; i < this->screens.size(); i++) {
        cout<<this->screens[i]<<"\t\t"
            <<this->skippedCount[i]<<"\t"
            <<this->errorCount[i]<<"\n";
    }

    cout<<"\n\nPress [ENTER] to continue.";
    getchar();
}
