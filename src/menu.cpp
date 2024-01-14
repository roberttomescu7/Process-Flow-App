#include "../headers/menu.hpp"

// MENU

// Constructor for Menu
Menu::Menu()
{
    // Clear the console screen
    system("clear");

    char answer;

    // Main menu loop
    do {
        cout<<"What do you want to do?\n\n"
            <<"1. Create a flow\n"
            <<"2. Run a flow\n"
            <<"3. Analyzes\n"
            <<"4. Exit\n";

        cout<<"Your answer: ";
        cin>>answer;
        getchar();

        // Process user's choice
        if (answer == '1') {
            this->createFlowButton();
        }
        else if (answer == '2') {
            if (this->flows.size() > 0) {
                this->runFlowButton();
            }
            else {
                cout<<"No flows have been created.\n";
                cout<<"Press [ENTER] to continue.";
                getchar();
            }
        }
        else if (answer == '3') {
            this->analyzesButton();
        }

        // Clear the console screen
        system("clear");

    } while (answer != '4'); 
}

// Create a new flow with user-defined steps
void Menu::createFlowButton()
{
    StepFactory factory;
    Flow* tmpFlow = new Flow;
    int answer;

    // Step creation loop
    do {
        // Clear the console screen
        system("clear");

        Step* tmpStep = nullptr;

        // Display step options to the user
        cout<<"1. Title step\n" 
            <<"2. Text step\n"
            <<"3. Text input step\n"
            <<"4. Number input step\n"
            <<"5. Calculus step\n"
            <<"6. Display step\n"
            <<"7. Text file step\n"
            <<"8. Csv file step\n"
            <<"9. Output step\n"
            <<"10. End step\n\n";

        cout<<"Your answer: ";
        cin>>answer;
        getchar();

        // Create the selected step type
        switch (static_cast<StepType>(answer)) {
            case TITLE_STEP:
                tmpStep = factory.createTitleStep();
                break;
            case TEXT_STEP:
                tmpStep = factory.createTextStep();
                break;
            case TEXT_INPUT_STEP:
                tmpStep = factory.createTextInputStep();
                break;
            case NUMBER_INPUT_STEP:
                tmpStep = factory.createNumberInputStep();
                break;
            case CALCULUS_STEP:
                tmpStep = factory.createCalculusStep(tmpFlow->getSteps());
                break;
            case DISPLAY_STEP:
                tmpStep = factory.createDisplayStep(tmpFlow->getSteps());
                break;
            case TEXT_FILE_STEP:
                tmpStep = factory.createTextFileStep();
                break;
            case CSV_FILE_STEP:
                tmpStep = factory.createCsvFileStep();
                break;
            case OUTPUT_STEP:
                tmpStep = factory.createOutputStep(tmpFlow->getSteps());
                break;
            case END_STEP:
                tmpStep = factory.createEndStep();
                break;
            default:
                cerr<<"Invalid step type. Please try again.\n";
                break;
        }   

        // Add the step to the flow
        if (tmpStep) {
            tmpStep->attach(tmpFlow->getObserver());
            tmpFlow->addStep(tmpStep);
        }
    } while (dynamic_cast<EndStep*>(tmpFlow->getSteps()->back()) == nullptr);

    // Add the created flow to the menu's list of flows
    this->flows.push_back(tmpFlow);
}

// Run a selected flow
void Menu::runFlowButton()
{
    // Clear the console screen
    system("clear");

    // Display available flows to the user
    int count = 1;
    for (Flow* flow : flows) {
        cout<<count<<".\t"<<flow->getTimestamp()<<"\t"<<flow->getFlowName()<<"\n\n";
        count++;
    }

    string input;
    int answer = 0;

    // Prompt user for the flow to run
    while (answer == 0) {
        cout<<"What flow do you want to run? Your answer: ";
        getline(cin, input);
        if (!(istringstream(input) >> answer)) {
            cout<<"Invalid input. You have to introduce a number.\n";
        }
    }  

    // Clear the console screen
    system("clear");

    // Update and run the selected flow
    this->flows[--answer]->getAnalyzer()->update(CLEAR);
    this->flows[answer]->getAnalyzer()->update(FLOW_STARTED_FLAG);
    this->flows[answer]->runFlow();
    this->flows[answer]->getAnalyzer()->update(FLOW_COMPLETED_FLAG);
}

// Analyze a selected flow
void Menu::analyzesButton()
{
    // Clear the console screen
    system("clear");

    // Display available flows to the user
    int count = 1;
    for (Flow* flow : flows) {
        cout<<count<<".\t"<<flow->getTimestamp()<<"\t"<<flow->getFlowName()<<"\n\n";
        count++;
    }

    string input;
    int answer = 0;

    // Prompt user for the flow to analyze
    while (answer == 0) {
        cout<<"What flow do you want to analyze? Your answer: ";
        getline(cin, input);
        if (!(istringstream(input) >> answer)) {
            cout<<"Invalid input. You have to introduce a number.\n";
        }
    }  

    // Clear the console screen
    system("clear");

    // Display analysis for the selected flow
    this->flows[--answer]->getAnalyzer()->display();
}
