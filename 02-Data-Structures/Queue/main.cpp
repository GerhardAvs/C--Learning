#include "Queue.h"
#include <iostream>
#include <exception>

using namespace std;

/**
 * @brief Displays the menu and returns the selected option.
 * 
 * @return int Selected menu option.
 */
int showMenu();

/**
 * @brief Main function that runs the queue program.
 * 
 * Allows the user to interact with the queue through a menu.
 */
int main(){

    Queue<int> myQueue;

    int retrievedData;
    int requestedData;

    while(true){
        try{
            switch(showMenu()){

                case 1:
                    cout << "Enter the value to enqueue: ";
                    cin >> requestedData;
                    myQueue.enqueue(requestedData);
                    break;

                case 2:
                    retrievedData = myQueue.dequeue();
                    cout << "Dequeued value: " << retrievedData << endl;
                    break;

                case 3:
                    retrievedData = myQueue.peek();
                    cout << "First value in queue: " << retrievedData << endl;
                    break;

                case 4:
                    myQueue.display();
                    break;

                case 5:
                    return 0;
            }
        }
        catch(exception& e){
            /// Error handling
            cout << "Error: " << e.what() << endl;
        }
    }
}

/**
 * @brief Prints the menu options and validates user input.
 * 
 * @return int Valid menu option selected by the user.
 */
int showMenu(){

    int option;

    do{
        cout << "\n_________________________________________" << endl;
        cout << "                 MENU                    " << endl;
        cout << "_________________________________________" << endl;

        cout << "1. ENQUEUE: Insert value" << endl;
        cout << "2. DEQUEUE: Remove value" << endl;
        cout << "3. PEEK: View first value" << endl;
        cout << "4. DISPLAY: Show queue" << endl;
        cout << "5. EXIT" << endl;

        cout << "\nSelect an option: ";
        cin >> option;
        cout << endl;

    }while(option < 1 || option > 5);

    return option;
}
