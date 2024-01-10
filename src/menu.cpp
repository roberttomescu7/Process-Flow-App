#include "../headers/menu.hpp"

enum StepType {
    TITLE_STEP = 1,
    TEXT_STEP = 2,
    TEXT_INPUT_STEP = 3,
    NUMBER_INPUT_STEP = 4,
    CALCULUS_STEP = 5,
    DISPLAY_STEP = 6,
    TEXT_FILE_STEP = 7,
    CSV_FILE_STEP = 8,
    OUTPUT_STEP = 9,
    END_STEP = 10
};

Menu::Menu()
{
    system("clear");

    char answer;

    do {
        cout<<"What do you want to do?\n\n"
            <<"1. Create a flow\n"
            <<"2. Run a flow\n"
            <<"3. Exit\n";

        cout<<"Your answer: ";
        cin>>answer;
        getchar();

        if (answer == '1') {
            this->createFlowButton();
        }
        else if (answer == '2') {
            this->runFlowButton();
        }

    system("clear");

    } while (answer != '3'); 
}

void Menu::createFlowButton()
{
    StepFactory factory;
    Flow* tmpFlow = new Flow;
    int answer;

    do {
        system("clear");

        Step* tmpStep = nullptr;

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

        if (tmpStep) {
            tmpFlow->addStep(tmpStep);
        }
    } while (dynamic_cast<EndStep*>(tmpFlow->getSteps()->back()) == nullptr);

    this->flows.push_back(tmpFlow);
}

void Menu::runFlowButton()
{
    system("clear");

    this->flows[0]->runFlow();
}