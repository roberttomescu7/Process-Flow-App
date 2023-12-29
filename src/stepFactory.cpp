#include "../headers/stepFactory.hpp"

//  TITLE STEP

TitleStep::TitleStep() 
{
    cout<<"Title: ";
    this->setTitle();
    cout<<"Subtitle: ";
    this->setSubtitle();
}

void TitleStep::display()
{
    cout<<this->getTitle()<<"\n\n";
    cout<<this->getSubtitle()<<"\n\n";
}

void TitleStep::setTitle()
{
    cin>>this->title;
}

string TitleStep::getTitle()
{
    return this->title;
}

void TitleStep::setSubtitle()
{
    cin>>this->subtitle;
}

string TitleStep::getSubtitle()
{
    return this->subtitle;
}

//  TEXT STEP

TextStep::TextStep()
{
    cout<<"Title: ";
    this->setTitle();
    cout<<"Copy: ";
    this->setCopy();
}

void TextStep::display()
{
    cout<<this->getTitle()<<"\n\n";
    cout<<this->getCopy()<<"\n\n";
}

void TextStep::setTitle()
{
    cin>>this->title;
}

string TextStep::getTitle()
{
    return this->title;
}

void TextStep::setCopy()
{
    cin>>this->copy;
}

string TextStep::getCopy()
{
    return this->copy;
}

//  TEXT INPUT STEP

TextInputStep::TextInputStep()
{
    cout<<"Description: ";
    this->setDescription();
}

void TextInputStep::display()
{
    cout<<this->getDescription()<<"\n\n";
    cout<<"Text: ";
    this->setText();
    cout<<"\n\n";
}

void TextInputStep::setDescription()
{
    cin>>this->description;
}

string TextInputStep::getDescription()
{
    return this->description;
}

void TextInputStep::setText()
{
    cin>>this->text;
}

string TextInputStep::getText()
{
    return this->text;
}

//  NUMBER INPUT STEP

NumberInputStep::NumberInputStep()
{
    cout<<"Description: ";
    this->setDescription();
}

void NumberInputStep::display()
{
    cout<<this->description<<"\n\n";
    cout<<"Number: ";
    this->setNumber();
    cout<<"\n\n";
}

string NumberInputStep::getDescription()
{
    return this->description;
}

void NumberInputStep::setNumber()
{
    cin>>this->number;
}

int NumberInputStep::getNumber()
{
    return this->number;
}

//  CALCULUS STEP

CalculusStep::CalculusStep()
{
    cout<<"First step: ";
    this->setStep1();
    cout<<"Second step: ";
    this->setStep2();
    cout<<"Operation: ";
    this->setOpearation();
}

void CalculusStep::display()
{  
    cout<<"Result of step "<<this->step1<<" "
        <<this->operation<<" step "<<this->step2<<": ";

        this->calculate();

        cout<<this->result<<"\n\n";
}   

void CalculusStep::setStep1()
{
    cin>>this->step1;
}

Step *CalculusStep::getStep1(vector<Step*> flow)
{
    //  TODO: Implement after the class FLOW has been created
}

void CalculusStep::setStep2()
{
    cin>>this->step2;
}

Step *CalculusStep::getStep2(vector<Step*> flow)
{
    //  TODO: Implement after the class FLOW has been created
}

void CalculusStep::setOpearation()
{
    cin>>this->operation;
}

void CalculusStep::calculate()
{
    //  TODO: Implement after the class FLOW has been created
}

//  DISPLAY STEP

DisplayStep::DisplayStep()
{
    cout<<"Step to display: ";
    this->setStep();
}

void DisplayStep::display()
{
    //  TODO: Implement after the class FLOW has been created
}

void DisplayStep::setStep()
{
    cin>>this->step;
}

Step DisplayStep::*getStep(vector<Step*> flow)
{
    //  TODO: Implement after the class FLOW has been created
}

void DisplayStep::setPath(string _path)
{
    this->path = _path;
}

string DisplayStep::getPath()
{
    return this->path;
}

//  TEXT FILE STEP

TextFileStep::TextFileStep()
{
    cout<<"Description: ";
    this->setDescription();
}

void TextFileStep::display()
{
    cout<<this->getDescription()<<"\n\n";
    cout<<"File name: ";
    this->setFileName();
}

void TextFileStep::setDescription()
{
    cin>>this->description;
}

string TextFileStep::getDescription()
{
    return this->description;
}

void TextFileStep::setFileName()
{
    cin>>this->fileName;
}

string TextFileStep::getFileName()
{
    return this->fileName;
}

//  CSV FILE STEP

CsvFileStep::CsvFileStep()
{
    cout<<"Description: ";
    this->setDescription();
}

void CsvFileStep::display()
{
    cout<<this->getDescription()<<"\n\n";
    cout<<"File name: ";
    this->setFileName();
}

void CsvFileStep::setDescription()
{
    cin>>this->description;
}

string CsvFileStep::getDescription()
{
    return this->description;
}

void CsvFileStep::setFileName()
{
    cin>>this->fileName;
}

string CsvFileStep::getFileName()
{
    return this->fileName;
}

//  OUTPUT STEP

OutputStep::OutputStep()
{
    cout<<"File name: ";
    this->setFileName();
    cout<<"Title: ";
    this->setTitle();
    cout<<"Description: ";
    this->setDescription(); 
    cout<<"Step: ";
    this->setStep();
}

void OutputStep::display()
{   
    cout<<"The output file with the name "
        <<this->getFileName()<<" was created\n\n";
}

void OutputStep::setStep()
{
    cin>>this->step;
}

Step *OutputStep::getStep(vector<Step*> flow)
{
    //  TODO: Implement after the class FLOW has been created
}

void OutputStep::setFileName()
{
    cin>>this->fileName;
}

string OutputStep::getFileName()
{
    return this->fileName;
}

void OutputStep::setTitle()
{
    cin>>this->title;
}

string OutputStep::getTitle()
{
    return this->title;
}

void OutputStep::setDescription()
{
    cin>>this->description;
}

string OutputStep::getDescription()
{
    return this->description;
}

//  END STEP

void EndStep::display()
{
    cout<<"End\n\n";
}

//  STEP FACTORY

Step* StepFactory::createTitleStep()
{
    return new TitleStep;
}

Step* StepFactory::createTextStep()
{
    return new TextStep;
}

Step* StepFactory::createTextInputStep()
{
    return new TextInputStep;
}

Step* StepFactory::createNumberInputStep()
{
    return new NumberInputStep;
}

Step* StepFactory::createCalculusStep()
{
    return new CalculusStep;
}

Step* StepFactory::createDisplayStep()
{
    return new DisplayStep;
}

Step* StepFactory::createTextFileStep()
{
    return new TextFileStep;
}

Step* StepFactory::createCsvFileStep()
{
    return new CsvFileStep;
}

Step* StepFactory::createOutputStep()
{
    return new OutputStep;
}

Step* StepFactory::createEndStep()
{
    return new EndStep;
}


