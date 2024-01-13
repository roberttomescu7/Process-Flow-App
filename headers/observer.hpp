#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <iostream>

using namespace std;

class Observer
{
    public:
        virtual ~Observer() = default;
        virtual void update(int flag) = 0;
        virtual void update(string stepName, int errors, int skipes) = 0;
};

class Subject 
{
    protected:
        Observer* observer;

    public:
        virtual ~Subject() = default;
        virtual void attach(Observer* observer) = 0;
        virtual void notify(string stepName, int errors, int skips) = 0;
};


#endif