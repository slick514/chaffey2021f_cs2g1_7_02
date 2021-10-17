#include <iostream>
#include <vector>
#include <string>
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
static string APP_NAME = "CopyMachine 7.02"; // NOLINT

// User input options (lower case)
static const char USER = 'U'; // NOLINT
static const char ADMIN = 'A'; // NOLINT
static const char QUIT = 'Q'; // NOLINT
static const char BALANCE = 'B'; // NOLINT
static const char MASTER_ACCT = 'M'; // NOLINT
static const char PROJECT = 'P'; // NOLINT
static const char COPIES = 'C'; // NOLINT
static const char EXIT = 'E'; // NOLINT

static const int NUMBER_OF_USERS = 100;
static const int NUMBER_OF_ACCOUNTS = 10;
static const int BASE_10 = 10;

void enter_control_loop(int**, int*, int);
void do_user_UI(bool&);
void do_admin_UI(bool&);
void display_invalid_input_message(string&);
void display_application_welcome_msg();
void display_exit_message();
void detect_range(const string &int_string, const int &max, bool &is_out_of_range);
void handle_nonint_int_input(string user_input, bool &is_invalid, bool &nav_main_flag, bool &quit_flag);
void detect_int(const string &str, bool &);
void display_out_of_range_err_msg(const int&, const int&);
void display_usernum_prompt();
void display_main_menu_prompt();
void display_usermenu_welcome();
void obtain_int_from_UI(int &int_ref, int, bool&, bool &);
void obtain_usernum(int &num_ref, bool&, bool&);

int main(int argc, char **argv) {
    // initialize user and account arrays
    int *users[NUMBER_OF_USERS];
    int master_account;
    int project_accounts[NUMBER_OF_ACCOUNTS];
    for (auto &user: users) user = &master_account;

    display_application_welcome_msg();
    enter_control_loop(users, project_accounts, master_account);
    display_exit_message();

    return 0;
}


void enter_control_loop(int **users, int *accounts, int master_acct) {
    char choice = QUIT;
    string input_string;
    bool quit_flag = false;

    do{
        display_main_menu_prompt();
        cin >> input_string;
        choice = (char)toupper(input_string[0]);
        switch(choice){
            case USER:
                do_user_UI(quit_flag);
                break;
            case ADMIN:
                do_admin_UI(quit_flag);
                break;
            case QUIT:
                break;
            default:
                display_invalid_input_message(input_string);
        }
    }while(!(choice == QUIT || quit_flag));
}

void display_main_menu_prompt() {
    cout << "Please choose from the following options:" << endl;
    cout << "(" << USER << ") if you are a User" << endl;
    cout << "(" << ADMIN << ") if you are an Administrator" << endl;
    cout << "(" << QUIT << ") to Quit" << endl;
}

void display_application_welcome_msg(){
    cout << "Welcome to " << APP_NAME << endl << endl;
}

void display_exit_message() {
    cout << endl;
    cout << "Thank you for using " << APP_NAME << endl;
    cout << "Goodbye!" << endl;
}

void display_invalid_input_message(string &invalid_input) {
    cout << endl ;
    cout << "'" << invalid_input << "' is not a valid input. Please try again." << endl;
}

// TODO:
void do_admin_UI(bool &quit_flag) {
    char user_choice;
    //cin >> user_choice;
}

// TODO:
void do_user_UI(bool &quit_flag) {
    int user_number;
    bool nav_main_flag;

    display_usermenu_welcome();
    obtain_usernum(user_number, nav_main_flag, quit_flag);
}

void obtain_int_from_UI(int &int_ref, int range, bool &nav_main_flag, bool &quit_flag) {
    bool is_invalid = false;
    do {
        bool is_int;
        string user_input;
        cin >> user_input;
        detect_int(user_input, is_int);

        if (!is_int) { // input is non-integer
            handle_nonint_int_input(user_input, is_invalid, nav_main_flag, quit_flag);
        }
        else if(range > 0) // We now  know it's an integer; check if it is in range
            detect_range(user_input, range, is_invalid);

    }while(is_invalid && !nav_main_flag);
}

void obtain_usernum(int &usernum, bool &nav_main_flag, bool &quit_flag) {;
    display_usernum_prompt();
    obtain_int_from_UI(usernum, NUMBER_OF_USERS, nav_main_flag, quit_flag);

}

void display_usermenu_welcome() {
    cout << "Welcome to the User menu." << endl;
}

void display_usernum_prompt() {

    cout << "Please enter one of the following:" << endl;
    cout << "\tYour user-number:" << endl;
    cout << "\t(" << EXIT << ") to exit to the main menu" << endl;
    cout << "\t(" << QUIT << ") to quit the application." << endl;
}

void display_out_of_range_err_msg(const int &max_range, const int &range) {
    cout << "The number you entered (" << max_range << ") is not within range (1 to "<< range <<"). Please enter an ";
    cout << "appropriate value." << endl;
}

// Detects if the string is an integer.
void detect_int(const string &str, bool &is_int) {
    for (char i : str) {
        if (!isdigit(i)){
            is_int = false;
            return;
        }
    }
    is_int = true;
}

void handle_nonint_int_input(string user_input, bool& is_invalid, bool &nav_main_flag, bool &quit_flag) {
    char uc_input_char = (char) toupper(user_input[0]);
    nav_main_flag = uc_input_char == EXIT;
    quit_flag = uc_input_char == QUIT;
    if(!quit_flag && !nav_main_flag)
        display_invalid_input_message(user_input);
}

void detect_range(const string &int_string, const int &max, bool &is_out_of_range) {
    char *end;
    int user_number = strtol(int_string.c_str(), &end, BASE_10);
    if ((user_number > 0) && (user_number <= max)){
        is_out_of_range = false;
    }else{
        display_out_of_range_err_msg(user_number, max);
    }
}
