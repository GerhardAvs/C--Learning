#include "SimpleList.h"
#include <iostream>
#include <exception>

using namespace std;

/**
 * @brief Displays the menu and returns a valid user option.
 * 
 * Ensures the selected option is within the allowed range.
 * 
 * @return int Valid menu option selected by the user.
 */
int showMenu();

/**
 * @brief Entry point of the program.
 * 
 * Provides a menu-driven interface to interact with a simple linked list.
 * 
 * @return int Program termination status.
 */
int main(){

    SimpleList<int> list;          ///< Linked list instance
    int value;                     ///< Stores user input value
    int option;                    ///< Stores selected menu option

    while(true){
        try{
            option = showMenu();

            switch(option){

                case 1:
                    cout << "Enter the value to initialize the list: ";
                    cin >> value;
                    list.crearlista(value);
                    break;

                case 2:
                    cout << "Enter the value to insert (ascending): ";
                    cin >> value;
                    list.AgregarAscendente(value);
                    break;

                case 3:
                    cout << "Enter the value to delete: ";
                    cin >> value;
                    list.EliminarNumero(value);
                    break;

                case 4:
                    cout << "Enter the value to search: ";
                    cin >> value;
                    list.BuscarNumero(value);
                    break;

                case 5:
                    list.Desplegar();
                    break;

                case 6:
                    list.Salir();
                    cout << "Program terminated successfully.\n";
                    return 0;
            }
        }
        catch(const exception& e){
            /// Handles runtime errors safely
            cout << "Error: " << e.what() << endl;
        }
    }
}

/**
 * @brief Prints menu options and validates user input.
 * 
 * Repeats until a valid option (1–6) is selected.
 * 
 * @return int Validated menu option.
 */
int showMenu(){

    int option;

    do{
        cout << "\n=========================================\n";
        cout << "                 MENU                    \n";
        cout << "=========================================\n";

        cout << "1. Create List (First Element)\n";
        cout << "2. Insert Element (Ascending Order)\n";
        cout << "3. Delete Element\n";
        cout << "4. Search Element\n";
        cout << "5. Display List\n";
        cout << "6. Exit\n";

        cout << "\nSelect an option: ";
        cin >> option;

        if(option < 1 || option > 6){
            cout << "Invalid option. Please try again.\n";
        }

    }while(option < 1 || option > 6);

    return option;
}