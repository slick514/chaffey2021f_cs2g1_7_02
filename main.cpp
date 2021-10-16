#include <iostream>
#include <vector>
using namespace std;

/*
 * Course: Chaffey College 2021-Fall CS2
 * Prof: Dr. Tracy Kocher
 * Date: 2021-10-15
 * Project: 7.02
 * Coder: Justin Gries
 * Tester(s):
 *
 * Prompt: Complete the copier simulation of How To 7.1. Your program should
 * first show the main menu:
    U)ser A)dministrator Q)uit
    For a user, prompt for the ID and the number of copies, increment the
    appropriate account, and return to the main menu.

    For an administrator, show this menu:
    B)alance M)aster P)roject
    In the balance option, show the balances of the master account and the
    ten project accounts. In the master option, prompt for a user ID and link
    it to the master account. In the project option, prompt for user and
    project IDs. Afterward, return to the main menu.
 */

// Program welcome message
const string APP_NAME = "CopyMachine 7.02";

// User input options (lower case)
const char USER = 'u';
const char ADMIN = 'a';
const char QUIT = 'q';
const char BALANCE = 'b';
const char MASTER_ACCT = 'm';
const char PROJECT = 'p';
const char COPIES = 'c';

const int NUMBER_OF_USERS = 100;
const int NUMBER_OF_ACCOUNTS = 10;

void enter_control_loop(int **users, int *accounts, int master_acct);
void do_user_UI();
void do_admin_UI();
void display_invalid_input_message(char);
void do_greeting();
void do_exit_message();

int main(int argc, char **argv) {
    // initialize user and account arrays
    int *users[NUMBER_OF_USERS];
    int master_account;
    int project_accounts[NUMBER_OF_ACCOUNTS];
    for (auto &user: users) user = &master_account;

    do_greeting();
    enter_control_loop(users, project_accounts, master_account);
    do_exit_message();
    return 0;
}


void enter_control_loop(int **users, int *accounts, int master_acct) {
    char choice = QUIT;
    do{
        cout << "Please choose from the following options:" << endl;
        cout << "'" << (char)toupper(USER) << "' if you are a User" << endl;
        cout << "'" << (char)toupper(ADMIN) << "' if you are an Administrator" << endl;
        cout << "'" << (char)toupper(QUIT) << "' to Quit" << endl;
        cin >> choice;
        choice = (char) tolower(choice);
        switch(choice){
            case USER:
                do_user_UI();
                break;
            case ADMIN:
                do_admin_UI();
                break;
            case QUIT:
                break;
            default:
                display_invalid_input_message(choice);
        }
    }while(choice != QUIT);
}


void do_greeting(){
    cout << "Welcome to " << APP_NAME << endl << endl;
}


void do_exit_message() {
    cout << endl << "Thank you for using " << APP_NAME << endl << "Goodbye!" <<
    endl;
}


void display_invalid_input_message(char invalid_input) {
    cout << endl << "'" << invalid_input << "' is not a valid input. ";
    cout << "Please try again." << endl;
}

// TODO:
void do_admin_UI() {
    char user_choice;
    //cin >> user_choice;
}

// TODO:
void do_user_UI() {
    char user_choice;
    cout << "Welcome to the User menu." << endl;
    cout << "Please enter your user number: ";
    cin >> user_choice;
    //cin >> user_choice;
}