/*
        Name:       John Glatts
        Date:       9/11/20
        Course:     CIS 2107
        Lab:        Lab 3 ATM
        Statement:
                   This is an ATM program. It prompts the user
                   to enter their pin. If the pin is entered incorrectly
                   3 times, the program will terminate. If the users
                   succesfully logs in, the ATM will print the main menu.
                   There are 4 menu options that are implemented in helper functions.
*/
#include <stdio.h>
#include <stdlib.h>

/* Nana's PIN */
#define PIN 3014

/* Function Prototypes */
int get_user_pin();
int get_user_option();
int check_withdrawl_amount(int);
void get_withdrawl_amount(int*, int*);
void get_depoist_amount(int*, int*, int*);
void check_for_receipt();
void print_user_balance(int);
void print_main_menu();
void print_exit_message();
void print_login_error_message(int);
void quit_and_print(int);

/* Main Function */
int main(int argc, char *argv[]) {
        int option;
        int amount_deposited = 0;
        int balance = 5000;
        unsigned int transactions = 0;
        unsigned int login_attempts = 0;
        printf("\nWelcome to the \"ATM\"\n");
        // only allow 3 login attempts
        while (login_attempts < 3) {
                if (get_user_pin() != PIN) {
                        login_attempts++;
                        // check if there is an attempt left
                        // if so print a help message
                        if (login_attempts != 3)
                                printf("\nInvalid PIN. Please Try Again.\n");
                }
                else break;
        }
        // end the program if there are 3 unsuccesfull login attempts
        if (login_attempts == 3) {
                print_exit_message();
                exit(0);
        }
        // main ATM loop
        while (1) {
                print_main_menu();
                option = get_user_option();
                switch (option) {
                        case 1:
                                print_user_balance(balance);
                                break;
                        case 2:
                                get_withdrawl_amount(&balance, &transactions);
                                break;
                        case 3:
                                get_depoist_amount(&balance, &amount_deposited, &transactions);
                                break;
                        case 4:
                                quit_and_print(transactions);
                                break;
                        default:
                                print_login_error_message(option);
                                break;
                }
        }
        exit(0);
}

/* Scan the user's pin */
int get_user_pin() {
        int p;
        printf("Please enter your PIN: ");
        scanf("%d", &p);
        return p;
}

/* Scan the user's ATM menu option */
int get_user_option() {
        int opt;
        printf("\tEnter option : ");
        scanf("%d", &opt);
        return opt;
}

/* Scan the user's withdrawl amount */
void get_withdrawl_amount(int* balance_ptr, int* transactions) {
        int amount;
        unsigned int attempts = 0;

        // only allow 3 withdrawl attempts
        while (attempts < 3) {
                printf("\n\tPlease enter withdrawl amount (in mutlitiples in 20 of only please): ");
                scanf("%d", &amount);
                if (amount == 0) {
                        printf("\tAmount cannot be 0. Please try again\n");
                        attempts++;
                }
                else if (amount < 0) {
                        printf("\tAmount cannot be negative. Please try again\n");
                        attempts++;
                }
                else if ((amount % 20) != 0) {
                        printf("\tAmount must be a multipile of 20. Please try again\n");
                        attempts++;
                }
                else break;
        }

        if (attempts < 3) {
                *balance_ptr -= amount;
                *transactions += 1;     // pointers don't like the ++ operator :(
                check_for_receipt();
        }
        else {
                printf("\n\tThe withdrawl attempt limit has been reached\n");
                printf("\tThe program will now terminate\n");
                exit(0);
        }
}

/* Scan the user's depoist amount */
void get_depoist_amount(int* balance_ptr, int* amount_deposited, int* transactions) {
        int amount;
        unsigned int attempts = 0;
        unsigned int limit = 10000;

        // only allow 3 depoists
        while (attempts < 3) {
                printf("\n\tPlease enter depoist amount (Limit of $10,000 a day): ");
                scanf("%d", &amount);
                if (amount == 0) {
                        printf("\tAmount cannot be 0. Please try again\n");
                        attempts++;
                }
                else if (amount < 0) {
                        printf("\tAmount cannot be negative. Please try again\n");
                        attempts++;
                }
                else break;
        }

        if (attempts < 3 && *amount_deposited < limit) {
                *balance_ptr += amount;
                *amount_deposited += amount;
                *transactions += 1;     // pointers don't like the ++ operator :(
                check_for_receipt();
        }
        else {
                printf("\n\tYou're deposit attempt limit has been reached\n");
                printf("\tPlease depoist tommorow\n");
                exit(0);
        }
}

/* Check if the user would like a virtual receipt */
void check_for_receipt() {
        int receipt;
        printf("\n\tWould you like a receipt Nana?\n");
        printf("\tEnter 1 for yes, 2 for no: ");
        scanf("%d", &receipt);
}

/* Print the Main ATM Menu */
void print_main_menu() {
        printf("\n\tWelcome Nana, please choose an \"ATM\" option\n");
        printf("\t\t1. Balance\n");
        printf("\t\t2. Cash withdrawl\n");
        printf("\t\t3. Cash deposition\n");
        printf("\t\t4. Quit\n");
}

/* Print the user's current balance */
void print_user_balance(int b) {
        printf("\n\tNana's Balance is: $%d\n", b);
}

/* Print a thank you message and end the program */
void quit_and_print(int transactions) {
        printf("\nThank you for using the \"ATM\" Program\n");
        printf("Number of Transactions: %d\n", transactions);
        printf("The program will now terminate\n");
        exit(0);
}

/* Print an exit message message when the login attempt is reached */
void print_exit_message() {
        printf("\n\nInvalid PIN number limit has been reached (3 failed attempts)\n");
        printf("The \"ATM\" Program will terminate.\n\n");
}

/* Print the error from the menu option input */
void print_login_error_message(int opt) {
        printf("\n\t%d is not a valid option\n", opt);
        printf("\tPlease try again\n");
}
