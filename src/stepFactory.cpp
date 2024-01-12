#include "../headers/stepFactory.hpp"

//  TITLE STEP

TitleStep::TitleStep() 
{
    // Default initializations
    this->title = "Unknown";
    this->subtitle = "Unknown";

    cout<<"Title: ";
    this->setTitle();
    cout<<"Subtitle: ";
    this->setSubtitle();
}

void TitleStep::run(ostream& output)
{
    output<<this->getTitle()<<"\n\n";
    output<<this->getSubtitle()<<"\n\n";

    cout<<"Press [ENTER] to continue.\n";
    getchar();

    system("clear");
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
    // Default initializations
    this->title = "Unknown";
    this->copy = "Unknown";

    cout<<"Title: ";
    this->setTitle();
    cout<<"Copy: ";
    this->setCopy();
}

void TextStep::run(ostream& output)
{
    cout<<this->getTitle()<<"\n\n";
    cout<<this->getCopy()<<"\n\n";

    cout<<"Press [SPACE] to continue.\n";
    getchar();

    system("clear");
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
    // Default initializations
    this->description = "Unknown";
    this->text = "Unknown";

    cout<<"Description: ";
    this->setDescription();
}

void TextInputStep::run(ostream& output)
{
    cout<<this->getDescription()<<"\n\n";
    cout<<"Text: ";
    this->setText();
    cout<<"\n\n";

    cout<<"Press [SPACE] to continue.\n";
    getchar();

    system("clear");
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
    // Default initializations
    this->number = 0;
    this->description = "Unknown";

    cout<<"Description: ";
    this->setDescription();

}

void NumberInputStep::run(ostream& output)
{
    while (this->state) {
        try {
            cout<<this->description<<"\n\n";
            cout<<"Number: ";
            this->setNumber();
            cout<<"\n\n";
            this->state = false;
        }
        catch (string error) {
            cerr<<error<<"\n";
            cout<<"Do you want to skip this step? [Y/N] ";
            
            char answer;
            cin>>answer;
            getchar();

            if (answer == 'y' || answer == 'Y') {
                this->state = false;
            }
        }
    }

    cout<<"Press [SPACE] to continue.\n";
    getchar();

    system("clear");
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
    string input;
    getline(cin, input);
    if (!(istringstream(input) >> this->number)) {
        throw (string)"Invalid input. You have to introduce a number.";
    }  
}

float NumberInputStep::getNumber()
{
    return this->number;
}

//  CALCULUS STEP

CalculusStep::CalculusStep(vector<Step*>* containingFlow)
{
    // Default initializations
    this->setContainingFlow(containingFlow);
    this->step1 = nullptr;
    this->step2 = nullptr;
    this->operation = "Unknown";
    this->result = 0;

    while (this->state) {
        try {
            if (this->step1 == nullptr) {
                cout<<"First step: ";
                this->setStep1();
            }
            if (this->step2 == nullptr) {
                cout<<"Second step: ";
                this->setStep2();
            }
            if (this->operation == "Unknown") {
                cout<<"Operation: ";
                this->setOpearation();
            }
            this->state = false;
        }
        catch (string error) {
            cerr<<error<<"\n";
            cout<<"Do you want to skip this step? [Y/N] ";
            
            char answer;
            cin>>answer;
            getchar();

            if (answer == 'y' || answer == 'Y') {
                this->state = false;
            }
        }
    }
}

void CalculusStep::run(ostream& output)
{
    cout<<"Result: ";

    this->calculate();

    cout<<this->result<<"\n\n";

    cout<<"Press [SPACE] to continue.\n";
    getchar();

    system("clear");
}   

void CalculusStep::setStep1()
{
    string input;
    int stepIndex;
    getline(cin, input);

    istringstream stringStream(input); 

    if (!(stringStream >> stepIndex)) {
        throw (string)"Invalid input. The step must be a number.";
    }
    	
    stepIndex--;

    this->step1 = dynamic_cast<NumberInputStep*>(this->getStep(stepIndex));

    if (this->step1 == nullptr) {
        throw (string)"Invalid input. The step must be a NumberInputStep.";
    }
}

void CalculusStep::setStep2()
{   
    string input;
    int stepIndex;
    getline(cin, input);

    istringstream stringStream(input); 

    if (!(stringStream >> stepIndex)) {
        throw (string)"Invalid input. The step must be a number.";
    }

    stepIndex--;
    	
    this->step2 = dynamic_cast<NumberInputStep*>(this->getStep(stepIndex));

    if (this->step2 == nullptr) {
        throw (string)"Invalid input. The step must be a NumberInputStep.";
    }
}

void CalculusStep::setContainingFlow(vector<Step*>* _containingFlow)
{
    this->containingFlow = _containingFlow;
}

Step* CalculusStep::getStep(int stepIndex)
{
    return this->containingFlow->at(stepIndex);
}

void CalculusStep::setOpearation()
{
    getline(cin, this->operation);

    if (operation != "+" && operation != "-" && operation != "*" &&
        operation != "/" && operation != "min" && operation != "max") {
        this->operation = "Unknown";
        throw string("Invalid input. Please enter +, -, *, /, min, or max.");
    }
}

void CalculusStep::calculate()
{
    auto map = operationMap<float>.find(operation);
    if (map != operationMap<float>.end()) {
        this->result = 
        map->second(this->step1->getNumber(), this->step2->getNumber());
    }
    else {
        cerr<<"ERROR";
    }
}

//  DISPLAY STEP

DisplayStep::DisplayStep(vector<Step*>* containingFlow)
{
    // Default initializations
    this->setContainingFlow(containingFlow);
    this->step = nullptr;

    while (this->state) {
        try {
            if (this->step == nullptr) {
                cout<<"Step to display: ";
                this->setStep();
            }
            this->state = false;
        }
        catch (string error) {
            cerr<<error<<"\n";
            cout<<"Do you want to skip this step? [Y/N] ";
            
            char answer;
            cin>>answer;
            getchar();

            if (answer == 'y' || answer == 'Y') {
                this->state = false;
            }
        }
    } 
}

void DisplayStep::run(ostream& output)
{
    TextFileStep* textStep = dynamic_cast<TextFileStep*>(this->step);
    CsvFileStep* csvStep = dynamic_cast<CsvFileStep*>(this->step);

    string path;
    
    if (textStep) {
        path = "../files/" + textStep->getFileName();
    }
    else if (csvStep) {
        path = "../files/" + csvStep->getFileName();
    }

    FileManager::readAndPrint(path, output);

    cout<<"Press [SPACE] to continue.\n";
    getchar();

    system("clear");
}

void DisplayStep::setStep()
{
    string input;
    int stepIndex;
    getline(cin, input);

    istringstream stringStream(input); 

    if (!(stringStream >> stepIndex)) {
        throw (string)"Invalid input. The step must be a number.";
    }

    stepIndex--;
    	
    if (dynamic_cast<TextFileStep*>(this->getStep(stepIndex)) == nullptr &&
        dynamic_cast<CsvFileStep*>(this->getStep(stepIndex)) == nullptr) {
        throw (string)"Invalid input. The step must be a TextFileStep or a CsvFileStep.";
    }

    this->step = this->getStep(stepIndex);
}

void DisplayStep::setContainingFlow(vector<Step*>* _containingFlow)
{
    this->containingFlow = _containingFlow;
}

Step* DisplayStep::getStep(int stepIdx)
{
    return this->containingFlow->at(stepIdx);
}

//  TEXT FILE STEP

TextFileStep::TextFileStep()
{
    // Default initializations
    this->description = "Unknown";
    this->fileName = "Unknown";

    cout<<"Description: ";
    this->setDescription();
}

void TextFileStep::run(ostream& output)
{
    cout<<this->getDescription()<<"\n\n";
    cout<<"File name: ";
    this->setFileName();

    cout<<"Press [SPACE] to continue.\n";
    getchar();

    system("clear");
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
    // Default initializations
    this->description = "Unknown";
    this->fileName = "Unknown";

    cout<<"Description: ";
    this->setDescription();
}

void CsvFileStep::run(ostream& output)
{
    cout<<this->getDescription()<<"\n\n";
    cout<<"File name: ";
    this->setFileName();

    cout<<"Press [SPACE] to continue.\n";
    getchar();

    system("clear");
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
    // Default initializations
    this->step = nullptr;
    this->fileName = "Unknown";
    this->title = "Unknown";
    this->description = "Unknown";
    this->setContainingFlow(containingFlow);

    cout<<"File name: ";
    this->setFileName();
    cout<<"Title: ";
    this->setTitle();
    cout<<"Description: ";
    this->setDescription(); 
    cout<<"Step: ";
    this->setStep();
}

void OutputStep::run(ostream& output)
{   
    ofstream fout(this->getFileName(), ios::out);

    fout<<this->getTitle()<<"\n\n";
    fout<<this->getDescription()<<"\n\n";

    fout<<"==========   STEP OUTPUT    ==========\n\n";

    this->step->run(fout);

    cout<<"The output file with the name "
        <<this->getFileName()<<" was created\n\n";

    cout<<"Press [SPACE] to continue.\n";
    getchar();

    system("clear");
}

void OutputStep::setStep()
{
    string input;
    int stepIndex;
    getline(cin, input);

    istringstream stringStream(input); 

    if (!(stringStream >> stepIndex)) {
        throw (string)"Invalid input. The step must be a number.";
    }

    stepIndex--;
    	
    this->step = this->getStep(stepIndex);
}

void OutputStep::setContainingFlow(vector<Step*>* _containingFlow)
{
    this->containingFlow = _containingFlow;
}

Step *OutputStep::getStep(int stepIndex)
{
    return this->containingFlow->at(stepIndex);
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

    cout<<"Press [SPACE] to continue.\n";
    getchar();

    system("clear");
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


