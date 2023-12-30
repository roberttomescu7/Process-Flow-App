#ifndef STEPFACTORY_HPP
#define STEPFACTORY_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Step
{
    public:
        virtual void run(ostream& output) = 0;
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
        int number;
    
    public:
        NumberInputStep();
        void run(ostream& output) override;
        void setDescription();
        string getDescription();
        void setNumber();
        int getNumber();
        //  TODO: Handle exceptions
};

class CalculusStep : public Step
{
    private:
        int step1;
        int step2;
        int result;
        string operation;
        vector<Step*>* containingFlow;
    
    public:
        CalculusStep(vector<Step*>* containingFlow);
        void run(ostream& output) override;
        void setStep1();
        void setStep2();
        void setContainingFlow(vector<Step*>* container); 
        void setOpearation();
        Step* getStep(int stepNumber);
        void calculate();
        //  TODO: Handle exceptions
};

class DisplayStep : public Step
{
    private:
        string path;
        int step;
        vector<Step*>* containingFlow;
    
    public:
        DisplayStep(vector<Step*>* containingFlow);
        void run(ostream& output) override;
        void setStep();
        void setContainingFlow(vector<Step*>* container);
        Step* getStep();
        void setPath();
        string getPath();
        //  TODO: Handle exceptions
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
        //  TODO: Handle exceptions
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
        //  TODO: Handle exceptions
};

class OutputStep : public Step
{
    private:
        int step;
        string fileName;
        string title;
        string description;
        vector<Step*>* containingFlow;

    public:
        OutputStep(vector<Step*>* containingFlow);
        void run(ostream& output) override;
        void setStep();
        void setContainingFlow(vector<Step*>* container);
        Step* getStep();
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

#endif


