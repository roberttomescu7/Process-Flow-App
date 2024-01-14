// Include the header file for the StepFactory
#include "../headers/stepFactory.hpp"

// TITLE STEP

// Constructor for TitleStep
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

// Run method for TitleStep
void TitleStep::run(ostream& output)
{
    output<<this->getTitle()<<"\n\n";
    output<<this->getSubtitle()<<"\n\n";

    cout<<"Press [ENTER] to continue.\n";
    getchar();
    // Notify observers about the TitleStep completion
    this->notify("Title step", this->errorsCount, this->skips);

    system("clear");
}

// Set title for TitleStep
void TitleStep::setTitle()
{
    getline(cin, this->title);
}

// Get title for TitleStep
string TitleStep::getTitle()
{
    return this->title;
}

// Set subtitle for TitleStep
void TitleStep::setSubtitle()
{
    getline(cin, this->subtitle);
}

// Get subtitle for TitleStep
string TitleStep::getSubtitle()
{
    return this->subtitle;
}

// TEXT STEP

// Constructor for TextStep
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

// Run method for TextStep
void TextStep::run(ostream& output)
{
    output<<this->getTitle()<<"\n\n";
    output<<this->getCopy()<<"\n\n";

    cout<<"Press [ENTER] to continue.\n";
    getchar();
    // Notify observers about the TextStep completion
    this->notify("Text step", this->errorsCount, this->skips);

    system("clear");
}

// Set title for TextStep
void TextStep::setTitle()
{
    getline(cin, this->title);
}

// Get title for TextStep
string TextStep::getTitle()
{
    return this->title;
}

// Set copy for TextStep
void TextStep::setCopy()
{
    getline(cin, this->copy);
}

// Get copy for TextStep
string TextStep::getCopy()
{
    return this->copy;
}

// TEXT INPUT STEP

// Constructor for TextInputStep
TextInputStep::TextInputStep()
{
    // Default initializations
    this->description = "Unknown";
    this->text = "Unknown";

    cout<<"Description: ";
    this->setDescription();
}

// Run method for TextInputStep
void TextInputStep::run(ostream& output)
{
    output<<this->getDescription()<<"\n\n";
    output<<"Text: ";
    this->setText();
    output<<"\n\n";

    cout<<"Press [ENTER] to continue.\n";
    getchar();
    // Notify observers about the TextInputStep completion
    this->notify("Text input step", this->errorsCount, this->skips);

    system("clear");
}

// Set description for TextInputStep
void TextInputStep::setDescription()
{
    getline(cin, this->description);
}

// Get description for TextInputStep
string TextInputStep::getDescription()
{
    return this->description;
}

// Set text for TextInputStep
void TextInputStep::setText()
{
    getline(cin, this->text);
}

// Get text for TextInputStep
string TextInputStep::getText()
{
    return this->text;
}

// NUMBER INPUT STEP

// Constructor for NumberInputStep
NumberInputStep::NumberInputStep()
{
    // Default initializations
    this->number = 0;
    this->description = "Unknown";

    cout<<"Description: ";
    this->setDescription();

}

// Run method for NumberInputStep
void NumberInputStep::run(ostream& output)
{
    this->state = true;

    while (this->state) {
        try {
            cout<<this->description<<"\n\n";
            cout<<"Number: ";
            this->setNumber();
            cout<<"\n\n";
            this->state = false;
        }
        catch (string error) {
            this->errorsCount++;
            cerr<<error<<"\n";
            cout<<"Do you want to skip this step? [Y/N] ";
            
            char answer;
            cin>>answer;
            getchar();

            if (answer == 'y' || answer == 'Y') {
                this->state = false;
                this->skips++;
            }
        }
    }

    cout<<"Press [ENTER] to continue.\n";
    getchar();
    // Notify observers about the NumberInputStep completion
    this->notify("Number input step", this->errorsCount, this->skips);

    system("clear");
}

// Set description for NumberInputStep
void NumberInputStep::setDescription()
{
    getline(cin, this->description);
}

// Get description for NumberInputStep
string NumberInputStep::getDescription()
{
    return this->description;
}

// Set number for NumberInputStep
void NumberInputStep::setNumber()
{
    string input;
    getline(cin, input);
    if (!(istringstream(input) >> this->number)) {
        throw (string)"Invalid input. You have to introduce a number.";
    }  
}

// Get number for NumberInputStep
float NumberInputStep::getNumber()
{
    return this->number;
}

// CALCULUS STEP

// Constructor for CalculusStep
CalculusStep::CalculusStep(vector<Step*>* containingFlow)
{
    // Default initializations
    this->setContainingFlow(containingFlow);
    this->step1 = nullptr;
    this->step2 = nullptr;
    this->operation = "Unknown";
    this->result = 0;
    this->state = true;

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

// Run method for CalculusStep
void CalculusStep::run(ostream& output)
{
    output<<"Result: ";

    this->calculate();

    output<<this->result<<"\n\n";

    cout<<"Press [ENTER] to continue.\n";
    getchar();
    // Notify observers about the CalculusStep completion
    this->notify("Calculus step", this->errorsCount, this->skips);

    system("clear");
}   

// Set first step for CalculusStep
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

// Set second step for CalculusStep
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

// Set containing flow for CalculusStep
void CalculusStep::setContainingFlow(vector<Step*>* _containingFlow)
{
    this->containingFlow = _containingFlow;
}

// Get step from the containing flow for CalculusStep
Step* CalculusStep::getStep(int stepIndex)
{
    return this->containingFlow->at(stepIndex);
}

// Set operation for CalculusStep
void CalculusStep::setOpearation()
{
    getline(cin, this->operation);

    if (operation != "+" && operation != "-" && operation != "*" &&
        operation != "/" && operation != "min" && operation != "max") {
        this->operation = "Unknown";
        throw string("Invalid input. Please enter +, -, *, /, min, or max.");
    }
}

// Perform calculation for CalculusStep
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

// DISPLAY STEP

// Constructor for DisplayStep
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

// DISPLAY STEP

// Run method for DisplayStep
void DisplayStep::run(ostream& output)
{
    // Determine if the step is a TextFileStep or CsvFileStep
    TextFileStep* textStep = dynamic_cast<TextFileStep*>(this->step);
    CsvFileStep* csvStep = dynamic_cast<CsvFileStep*>(this->step);

    string path;
    
    // Construct the file path based on the step type
    if (textStep) {
        path = "../files/" + textStep->getFileName();
    }
    else if (csvStep) {
        path = "../files/" + csvStep->getFileName();
    }

    // Read and print the contents of the file
    FileManager::readAndPrint(path, output);

    // Prompt for user to continue
    cout<<"Press [ENTER] to continue.\n";
    getchar();
    // Notify observers about the completion of DisplayStep
    this->notify("Display step", this->errorsCount, this->skips);

    // Clear the console screen
    system("clear");
}

// Set the step for DisplayStep
void DisplayStep::setStep()
{
    string input;
    int stepIndex;
    getline(cin, input);

    istringstream stringStream(input); 

    // Validate and set the step index
    if (!(stringStream >> stepIndex)) {
        throw (string)"Invalid input. The step must be a number.";
    }

    stepIndex--;

    // Validate that the step is either a TextFileStep or CsvFileStep
    if (dynamic_cast<TextFileStep*>(this->getStep(stepIndex)) == nullptr &&
        dynamic_cast<CsvFileStep*>(this->getStep(stepIndex)) == nullptr) {
        throw (string)"Invalid input. The step must be a TextFileStep or a CsvFileStep.";
    }

    // Set the step for DisplayStep
    this->step = this->getStep(stepIndex);
}

// Set the flow of steps for DisplayStep
void DisplayStep::setContainingFlow(vector<Step*>* _containingFlow)
{
    this->containingFlow = _containingFlow;
}

// Get a step at a given index for DisplayStep
Step* DisplayStep::getStep(int stepIdx)
{
    return this->containingFlow->at(stepIdx);
}

// TEXT FILE STEP

// Constructor for TextFileStep
TextFileStep::TextFileStep()
{
    // Default initializations
    this->description = "Unknown";
    this->fileName = "Unknown";

    // Prompt user for input
    cout<<"Description: ";
    this->setDescription();
}

// Run method for TextFileStep
void TextFileStep::run(ostream& output)
{
    // Display description and prompt for file name
    cout<<this->getDescription()<<"\n\n";
    cout<<"File name: ";
    this->setFileName();

    // Prompt for user to continue
    cout<<"Press [ENTER] to continue.\n";
    getchar();
    // Notify observers about the completion of TextFileStep
    this->notify("Text file step", this->errorsCount, this->skips);

    // Clear the console screen
    system("clear");
}

// Set the description for TextFileStep
void TextFileStep::setDescription()
{
    getline(cin, this->description);
}

// Get the description for TextFileStep
string TextFileStep::getDescription()
{
    return this->description;
}

// Set the file name for TextFileStep
void TextFileStep::setFileName()
{
    getline(cin, this->fileName);
}

// Get the file name for TextFileStep
string TextFileStep::getFileName()
{
    return this->fileName;
}

// CSV FILE STEP

// Constructor for CsvFileStep
CsvFileStep::CsvFileStep()
{
    // Default initializations
    this->description = "Unknown";
    this->fileName = "Unknown";

    // Prompt user for input
    cout<<"Description: ";
    this->setDescription();
}

// Run method for CsvFileStep
void CsvFileStep::run(ostream& output)
{
    // Display description and prompt for file name
    cout<<this->getDescription()<<"\n\n";
    cout<<"File name: ";
    this->setFileName();

    // Prompt for user to continue
    cout<<"Press [ENTER] to continue.\n";
    getchar();
    // Notify observers about the completion of CsvFileStep
    this->notify("Csv file step", this->errorsCount, this->skips);

    // Clear the console screen
    system("clear");
}

// Set the description for CsvFileStep
void CsvFileStep::setDescription()
{
    getline(cin, this->description);
}

// Get the description for CsvFileStep
string CsvFileStep::getDescription()
{
    return this->description;
}

// Set the file name for CsvFileStep
void CsvFileStep::setFileName()
{
    getline(cin, this->fileName);
}

// Get the file name for CsvFileStep
string CsvFileStep::getFileName()
{
    return this->fileName;
}

// OUTPUT STEP

// Constructor for OutputStep
OutputStep::OutputStep(vector<Step*>* containingFlow)
{
    // Default initializations
    this->step = nullptr;
    this->fileName = "Unknown";
    this->title = "Unknown";
    this->description = "Unknown";
    this->setContainingFlow(containingFlow);

    // Prompt user for input
    cout<<"File name: ";
    this->setFileName();
    cout<<"Title: ";
    this->setTitle();
    cout<<"Description: ";
    this->setDescription(); 
    cout<<"Step: ";
    this->setStep();
}

// Run method for OutputStep
void OutputStep::run(ostream& output)
{   
    // Open the output file
    ofstream fout(this->getFileName(), ios::out);

    // Write title and description to the output file
    fout<<this->getTitle()<<"\n\n";
    fout<<this->getDescription()<<"\n\n";

    fout<<"==========   STEP OUTPUT    ==========\n\n";

    // Run the step and write its output to the file
    this->step->run(fout);

    // Inform the user about the created output file
    cout<<"The output file with the name "
        <<this->getFileName()<<" was created\n\n";

    // Prompt for user to continue
    cout<<"Press [ENTER] to continue.\n";
    getchar();
    // Notify observers about the completion of OutputStep
    this->notify("Output step", this->errorsCount, this->skips);

    // Clear the console screen
    system("clear");
}

// Set the step for OutputStep
void OutputStep::setStep()
{
    string input;
    int stepIndex;
    getline(cin, input);

    istringstream stringStream(input); 

    // Validate and set the step index
    if (!(stringStream >> stepIndex)) {
        throw (string)"Invalid input. The step must be a number.";
    }

    stepIndex--;

    // Set the step for OutputStep
    this->step = this->getStep(stepIndex);
}

// Set the flow of steps for OutputStep
void OutputStep::setContainingFlow(vector<Step*>* _containingFlow)
{
    this->containingFlow = _containingFlow;
}

// Get a step at a given index for OutputStep
Step *OutputStep::getStep(int stepIndex)
{
    return this->containingFlow->at(stepIndex);
}

// Set the file name for OutputStep
void OutputStep::setFileName()
{
    getline(cin, this->fileName);
}

// Get the complete file path for OutputStep
string OutputStep::getFileName()
{
    return "../files/" + this->fileName;
}

// Set the title for OutputStep
void OutputStep::setTitle()
{
    getline(cin, this->title);
}

// Get the title for OutputStep
string OutputStep::getTitle()
{
    return this->title;
}

// Set the description for OutputStep
void OutputStep::setDescription()
{
    getline(cin, this->description);
}

// Get the description for OutputStep
string OutputStep::getDescription()
{
    return this->description;
}

// END STEP

// Run method for EndStep
void EndStep::run(ostream& output)
{
    cout<<"End\n\n";

    // Prompt for user to continue
    cout<<"Press [ENTER] to continue.\n";
    getchar();

    // Clear the console screen
    system("clear");
}

// STEP FACTORY

// Create a TitleStep instance
Step* StepFactory::createTitleStep()
{
    return new TitleStep;
}

// Create a TextStep instance
Step* StepFactory::createTextStep()
{
    return new TextStep;
}

// Create a TextInputStep instance
Step* StepFactory::createTextInputStep()
{
    return new TextInputStep;
}

// Create a NumberInputStep instance
Step* StepFactory::createNumberInputStep()
{
    return new NumberInputStep;
}

// Create a CalculusStep instance
Step* StepFactory::createCalculusStep(vector<Step*>* containingFlow)
{
    return new CalculusStep(containingFlow);
}

// Create a DisplayStep instance
Step* StepFactory::createDisplayStep(vector<Step*>* containingFlow)
{
    return new DisplayStep(containingFlow);
}

// Create a TextFileStep instance
Step* StepFactory::createTextFileStep()
{
    return new TextFileStep;
}

// Create a CsvFileStep instance
Step* StepFactory::createCsvFileStep()
{
    return new CsvFileStep;
}

// Create an OutputStep instance
Step* StepFactory::createOutputStep(vector<Step*>* containingFlow)
{
    return new OutputStep(containingFlow);
}

// Create an EndStep instance
Step* StepFactory::createEndStep()
{
    return new EndStep;
}



