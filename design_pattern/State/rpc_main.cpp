#include "rpc_state.h"
#include "rpc_context.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    Context* context = new Context();
    context->state = new RestingState();

    char command = ' ';
    cout << "Welcome to \"The State Game\"!" << endl;
    cout << "You are standing here looking relaxed!" << endl;
    while (command != 'e')
    {
        cout << "\nWhat would you like to do now?" << endl;
        cout << "Move    Attack    Stop    Run    Panic    CalmDown    Exit the game: ==>";    
        string choice = "";
        do 
            cin >> choice;
        while (choice == "");
        command = choice[0];
        context->request(command);
    }

    delete context->state;
    delete context;
    return 0;
}
