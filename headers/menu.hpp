#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <vector>
#include "../headers/flow.hpp"

using namespace std;

class Menu
{
    private:
        vector<Flow*> flows;
        
    public:
        Menu();
        void createFlowButton();
        void runFlowButton();
};

#endif