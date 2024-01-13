#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <vector>
#include "../headers/flow.hpp"

using namespace std;

enum StepType {
    TITLE_STEP = 1,
    TEXT_STEP = 2,
    TEXT_INPUT_STEP = 3,
    NUMBER_INPUT_STEP = 4,
    CALCULUS_STEP = 5,
    DISPLAY_STEP = 6,
    TEXT_FILE_STEP = 7,
    CSV_FILE_STEP = 8,
    OUTPUT_STEP = 9,
    END_STEP = 10
};

class Menu
{
    private:
        vector<Flow*> flows;
        
    public:
        Menu();
        void createFlowButton();
        void runFlowButton();
        void analyzesButton();
};

#endif