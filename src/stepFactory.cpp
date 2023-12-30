#include "../headers/stepFactory.hpp"

//  TITLE STEP

TitleStep::TitleStep() 
{
    cout<<"Title: ";
    this->setTitle();
    cout<<"Subtitle: ";
    this->setSubtitle();
}

void TitleStep::run(ostream& output)
{
    
    output<<this->getTitle()<<"\n\n";
    output<<this->getSubtitle()<<"\n\n";
}

void TitleStep::setTitle()
{
    getline(cin, this->title);
}

string TitleStep::getTitle()
{
    return this->title;
}

void TitleStep::setSubtitle()
{
    getline(cin, this->subtitle);
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

void TextStep::run(ostream& output)
{
    cout<<this->getTitle()<<"\n\n";
    cout<<this->getCopy()<<"\n\n";
}

void TextStep::setTitle()
{
    getline(cin, this->title);
}

string TextStep::getTitle()
{
    return this->title;
}

void TextStep::setCopy()
{
    getline(cin, this->copy);
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

void TextInputStep::run(ostream& output)
{
    cout<<this->getDescription()<<"\n\n";
    cout<<"Text: ";
    this->setText();
    cout<<"\n\n";
}

void TextInputStep::setDescription()
{
    getline(cin, this->description);
}

string TextInputStep::getDescription()
{
    return this->description;
}

void TextInputStep::setText()
{
    getline(cin, this->text);
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

void NumberInputStep::run(ostream& output)
{
    cout<<this->description<<"\n\n";
    cout<<"Number: ";
    this->setNumber();
    cout<<"\n\n";
}

void NumberInputStep::setDescription()
{
    getline(cin, this->description);
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

CalculusStep::CalculusStep(vector<Step*>* containingFlow)
{
    cout<<"First step: ";
    this->setStep1();
    cout<<"Second step: ";
    this->setStep2();
    cout<<"Operation: ";
    this->setOpearation();
    this->setContainingFlow(containingFlow);
}

void CalculusStep::run(ostream& output)
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

void CalculusStep::setStep2()
{
    cin>>this->step2;
}

void CalculusStep::setContainingFlow(vector<Step*>* _containingFlow)
{
    this->containingFlow = _containingFlow;
}

Step* CalculusStep::getStep(int stepNumber)
{
    return this->containingFlow->at(stepNumber);
}

void CalculusStep::setOpearation()
{
    cin>>this->operation;
}

void CalculusStep::calculate()
{
    NumberInputStep* s1 = dynamic_cast<NumberInputStep*>(this->getStep(this->step1));
    NumberInputStep* s2 = dynamic_cast<NumberInputStep*>(this->getStep(this->step2));

    if (this->operation == "+") {
        this->result = s1->getNumber() + s2->getNumber();
    }
    else if (this->operation == "-") {
        this->result = s1->getNumber() - s2->getNumber();
    }
    else if (this->operation == "*") {
        this->result = s1->getNumber() * s2->getNumber();
    }
    else if (this->operation == "/") {
        this->result = s1->getNumber() / s2->getNumber();
    }
    else if (this->operation == "min") {
        this->result = min(s1->getNumber(), s2->getNumber());
    }
    else if (this->operation == "max") {
        this->result = max(s1->getNumber(), s2->getNumber());
    }
    else {
        cout<<"ERROR";
    }
}

//  DISPLAY STEP

DisplayStep::DisplayStep(vector<Step*>* containingFlow)
{
    cout<<"Step to:run:istream& output ";
    this->setStep();
    this->setContainingFlow(containingFlow);
}

void DisplayStep::run(ostream& output)
{
    //  FIXME: The:run istream& outputmethod depends on the file format
    this->setPath();

    ifstream fin(this->getPath(), ios::in);
    string line;
    while (getline(fin, line)) {
        cout<<line<<"\n";
    }

    fin.close();
}

void DisplayStep::setStep()
{
    cin>>this->step;
    getchar();
}

void DisplayStep::setContainingFlow(vector<Step*>* _containingFlow)
{
    this->containingFlow = _containingFlow;
}

Step* DisplayStep::getStep()
{
    return this->containingFlow->at(this->step);
}

void DisplayStep::setPath()
{   
    //  FIXME: Only works for TextFileStep. It must also works for CsvFIleStep
    TextFileStep* s1 = dynamic_cast<TextFileStep*>(this->getStep());
    this->path = "../files/" + s1->getFileName();
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

void TextFileStep::run(ostream& output)
{
    cout<<this->getDescription()<<"\n\n";
    cout<<"File name: ";
    this->setFileName();
}

void TextFileStep::setDescription()
{
    getline(cin, this->description);
}

string TextFileStep::getDescription()
{
    return this->description;
}

void TextFileStep::setFileName()
{
    getline(cin, this->fileName);
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

void CsvFileStep::run(ostream& output)
{
    cout<<this->getDescription()<<"\n\n";
    cout<<"File name: ";
    this->setFileName();
}

void CsvFileStep::setDescription()
{
    getline(cin, this->description);
}

string CsvFileStep::getDescription()
{
    return this->description;
}

void CsvFileStep::setFileName()
{
    getline(cin, this->fileName);
}

string CsvFileStep::getFileName()
{
    return this->fileName;
}

//  OUTPUT STEP

OutputStep::OutputStep(vector<Step*>* containingFlow)
{
    cout<<"File name: ";
    this->setFileName();
    cout<<"Title: ";
    this->setTitle();
    cout<<"Description: ";
    this->setDescription(); 
    cout<<"Step: ";
    this->setStep();
    this->setContainingFlow(containingFlow);
}

void OutputStep::run(ostream& output)
{   
    ofstream fout(this->getFileName(), ios::out);

    Step* step = this->getStep();

    fout<<this->getTitle()<<"\n\n";
    fout<<this->getDescription()<<"\n\n";

    fout<<"==========   STEP "<<this->step<<" OUTPUT    ==========\n\n";

    step->run(fout);

    cout<<"The output file with the name "
        <<this->getFileName()<<" was created\n\n";
}

void OutputStep::setStep()
{
    cin>>this->step;
    getchar();
}

void OutputStep::setContainingFlow(vector<Step*>* _containingFlow)
{
    this->containingFlow = _containingFlow;
}

Step *OutputStep::getStep()
{
    return this->containingFlow->at(this->step);
}

void OutputStep::setFileName()
{
    getline(cin, this->fileName);
}

string OutputStep::getFileName()
{
    return "../files/" + this->fileName;
}

void OutputStep::setTitle()
{
    getline(cin, this->title);
}

string OutputStep::getTitle()
{
    return this->title;
}

void OutputStep::setDescription()
{
    getline(cin, this->description);
}

string OutputStep::getDescription()
{
    return this->description;
}

//  END STEP

void EndStep::run(ostream& output)
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

Step* StepFactory::createCalculusStep(vector<Step*>* containingFlow)
{
    return new CalculusStep(containingFlow);
}

Step* StepFactory::createDisplayStep(vector<Step*>* containingFlow)
{
    return new DisplayStep(containingFlow);
}

Step* StepFactory::createTextFileStep()
{
    return new TextFileStep;
}

Step* StepFactory::createCsvFileStep()
{
    return new CsvFileStep;
}

Step* StepFactory::createOutputStep(vector<Step*>* containingFlow)
{
    return new OutputStep(containingFlow);
}

Step* StepFactory::createEndStep()
{
    return new EndStep;
}


