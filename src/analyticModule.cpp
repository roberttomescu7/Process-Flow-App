#include "../headers/analyticModule.hpp"

// ANALYZER

// Constructor for Analyzer
Analyzer::Analyzer()
{
    // Initialize counters
    this->flowStartedCount = 0;
    this->flowCompletedCount = 0;
}

// Update the analyzer based on the provided flag
void Analyzer::update(int flag)
{
    if (flag == FLOW_STARTED_FLAG) {
        this->flowStartedCount++;
    }
    if (flag == FLOW_COMPLETED_FLAG) {
        this->flowCompletedCount++;
    }
    if (flag == CLEAR) {
        // Clear stored data when the CLEAR flag is received
        this->screens.clear();
        this->errorCount.clear();
        this->skippedCount.clear();
    }
}

// Update the analyzer with information about a step
void Analyzer::update(string stepName, int errors, int skips)
{
    // Store information about a step
    this->screens.push_back(stepName);
    this->skippedCount.push_back(skips);
    this->errorCount.push_back(errors);
}

// Display the analysis results
void Analyzer::display()
{
    cout << "This flow has been started " << this->flowStartedCount << " times.\n";
    cout << "This flow has been completed " << this->flowCompletedCount << " times.\n\n";

    // Display a table of step analysis
    cout << left << setw(30) << "SCREEN"
         << std::setw(15) << "SKIPS"
         << std::setw(15) << "ERRORS" << "\n";

    for (int i = 0; i < screens.size(); i++) {
        cout << left << setw(30) << screens[i]
             << setw(15) << skippedCount[i]
             << setw(15) << errorCount[i] << "\n";
    }

    cout << "\n\nPress [ENTER] to continue.";
    getchar();
}
