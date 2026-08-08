#include <iostream>
#include <exception>
#include "Stack.h"

using namespace std;

/**
 * @brief Displays the program menu and returns the selected option.
 * 
 * @return int User selected option.
 */
int showMenu();

/**
 * @brief Main function that allows interaction with the stack.
 * 
 * The user can push, pop, peek and view the stack elements.
 */
int main(){

    Stack<int> myStack;

    int retrievedData;
    int requestedData;

    while(true){
        try{
            switch(showMenu()){
                
                case 1:
                    cout << "Enter the value to push: ";
                    cin >> requestedData;
                    myStack.push(requestedData);
                    break;

                case 2:
                    retrievedData = myStack.pop();
                    cout << "Popped value: " << retrievedData << endl;
                    break;

                case 3:
                    retrievedData = myStack.peek();
                    cout << "Top value: " << retrievedData << endl;
                    break;

                case 4:
                    return 0;
            }

        }
        catch(exception& e){
            /// Error handling
            cout << "Error: " << e.what() << endl;
        }

        cout << "\nCurrent stack state: ";
        myStack.display();
    }
}

/**
 * @brief Prints the menu options and validates user input.
 * 
 * @return int Selected menu option.
 */
int showMenu(){

    int option;

    do{
        cout << "\n_________________________________________" << endl;
        cout << "                 MENU                    " << endl;
        cout << "_________________________________________" << endl;

        cout << "1. PUSH: Insert value" << endl;
        cout << "2. POP: Remove value" << endl;
        cout << "3. PEEK: View top value" << endl;
        cout << "4. EXIT" << endl;

        cout << "\nSelect a menu option: ";
        cin >> option;
        cout << endl;

    }while(option < 1 || option > 4);

    return option;
}
