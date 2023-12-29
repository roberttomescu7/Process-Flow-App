#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Step
{
    public:
        virtual void display() = 0;
};

class TitleStep : public Step
{
    private:
        string title;
        string subtitle;

    public: 
        TitleStep();
        void display() override;
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
        void display() override;
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
        void display() override;
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
        void display() override;
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
        vector<Step*> *container;
    
    public:
        CalculusStep();
        void display() override;
        void setStep1();
        Step* getStep1(vector<Step*> flow);
        void setStep2();
        Step* getStep2(vector<Step*> flow);
        void setOpearation();
        void calculate();
        //  TODO: Handle exceptions
};

class DisplayStep : public Step
{
    private:
        string path;
        int step;
    
    public:
        DisplayStep();
        void display() override;
        void setStep();
        Step* getStep(vector<Step*> flow);
        void setPath(string _path);
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
        void display() override;
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
        void display() override;
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

    public:
        OutputStep();
        void display() override;
        void setStep();
        Step* getStep(vector<Step*> flow);
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
        void display() override;
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
        Step* createCalculusStep();
        Step* createDisplayStep();
        Step* createTextFileStep();
        Step* createCsvFileStep();
        Step* createOutputStep();
        Step* createEndStep();
};




