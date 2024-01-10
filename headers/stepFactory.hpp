#ifndef STEP_FACTORY_HPP
#define STEP_FACTORY_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <stdlib.h>
#include "fileManager.hpp"

using namespace std;

class Step
{
    protected:
        bool state = true;

    public:
        virtual void run(ostream& output) = 0;
        void skip()
        {
            cout<<"Step skiped!";
        }
};

class TitleStep : public Step
{
    private:
        string title;
        string subtitle;

    public: 
        TitleStep();
        void run(ostream& output) override;
        void setTitle();
        string getTitle();
        void setSubtitle();
        string getSubtitle();
};

class TextStep : public Step
{
    private:
        string title;
        string copy;
    
    public:
        TextStep();
        void run(ostream& output) override;
        void setTitle();
        string getTitle();
        void setCopy();
        string getCopy();
};

class TextInputStep : public Step
{
    private:
        string description;
        string text;
    
    public:
        TextInputStep();
        void run(ostream& output) override;
        void setDescription();
        string getDescription();
        void setText();
        string getText();
};

class NumberInputStep : public Step
{
    private:
        string description;
        float number;
    
    public:
        NumberInputStep();
        void run(ostream& output) override;
        void setDescription();
        string getDescription();
        void setNumber();
        float getNumber();
};

class CalculusStep : public Step
{
    private:
        NumberInputStep* step1;
        NumberInputStep* step2;
        float result;
        string operation;
        vector<Step*>* containingFlow;
    
    public:
        CalculusStep(vector<Step*>* containingFlow);
        void run(ostream& output) override;
        void setStep1();
        void setStep2();
        void setContainingFlow(vector<Step*>* container); 
        void setOpearation();
        Step* getStep(int stepIndex);
        void calculate();
};

class DisplayStep : public Step
{
    private:
        Step* step;
        vector<Step*>* containingFlow;
    
    public:
        DisplayStep(vector<Step*>* containingFlow);
        void run(ostream& output) override;
        void setStep();
        void setContainingFlow(vector<Step*>* container);
        Step* getStep(int stepIdx);
};

class TextFileStep : public Step
{
    private:
        string description;
        string fileName;

    public:
        TextFileStep();
        void run(ostream& output) override;
        void setDescription();
        string getDescription();
        void setFileName();
        string getFileName();
};

class CsvFileStep : public Step
{
    private:
        string description;
        string fileName;

    public:
        CsvFileStep();
        void run(ostream& output) override;
        void setDescription();
        string getDescription();
        void setFileName();
        string getFileName();
};

class OutputStep : public Step
{
    private:
        Step* step;
        string fileName;
        string title;
        string description;
        vector<Step*>* containingFlow;

    public:
        OutputStep(vector<Step*>* containingFlow);
        void run(ostream& output) override;
        void setStep();
        void setContainingFlow(vector<Step*>* container);
        Step* getStep(int stepIndex);
        void setFileName();
        string getFileName();
        void setTitle();
        string getTitle();
        void setDescription();
        string getDescription();
};

class EndStep : public Step
{
    public:
        void run(ostream& output) override;
        // NOTE: More complex functionality can be added later
};

class StepFactory
{
    public:
        ~StepFactory() = default;
        Step* createTitleStep();
        Step* createTextStep();
        Step* createTextInputStep();
        Step* createNumberInputStep();
        Step* createCalculusStep(vector<Step*>* containingFlow);
        Step* createDisplayStep(vector<Step*>* containingFlow);
        Step* createTextFileStep();
        Step* createCsvFileStep();
        Step* createOutputStep(vector<Step*>* containingFlow);
        Step* createEndStep();
};

template <typename T>
T add(T operand1, T operand2) {
    return operand1 + operand2;
}

template <typename T>
T subtract(T operand1, T operand2) {
    return operand1 - operand2;
}

template <typename T>
T multiply(T operand1, T operand2) {
    return operand1 * operand2;
}

template <typename T>
T divide(T operand1, T operand2) {
    return operand1 / operand2;
}

template <typename T>
T minimum(T operand1, T operand2) {
    return std::min(operand1, operand2);
}

template <typename T>
T maximum(T operand1, T operand2) {
    return std::max(operand1, operand2);
}

template <typename T>
map<string, function<T(T, T)>> operationMap = {
    {"+", add<float>},
    {"-", subtract<float>},
    {"*", multiply<float>},
    {"/", divide<float>},
    {"min", minimum<float>},
    {"max", maximum<float>} 
};


#endif


