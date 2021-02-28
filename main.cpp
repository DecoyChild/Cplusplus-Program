/*
 * Shayne Greene
 * 2/4/21
 * Airgead Investment Banking/ 1.1
 * 
 * Program will allow a user to set up investment calculations based on input. 
 * WIll prompt for, an initial investment amount, a deposit amount, interest rate
 * and the amount of years. A table will b e displayed showing yearly totals
 * with a monthly deposit and one without a deposit. 
 * 
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>

#include "Investment.h"

using namespace std;

void Welcome();
void InputMenu(Investment&);
void PrintBorder();
void ClearInput();
bool DataValidation(auto);
char Selection();

int main(int argc, char** argv) {
    
    char selection;
    bool depositMade = true;
        
    // Will display the welcome "splash' screen
    Welcome();
    
    // Initiating a new instance of an Investment Class
    Investment newInvestment;
    
    do {
        // Gathering the data for the investment calculations
        InputMenu(newInvestment);

        // Calculates the investment totals 
        newInvestment.InvestmentTable(depositMade);
        newInvestment.InvestmentTable(!depositMade);

        // Allows the user to run the program again
        selection = Selection();
        
    } while (selection == 'Y');
    
    return 0;
}

//##############################################################################
// Displays the welcome splash screen
void Welcome() {

        cout << ""  << endl << ""
    "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"    << endl << ""
    "  $$$$$$$$$$$         WELCOME TO           $$$$$$$$$$"    << endl << ""
    "   $$$$$$$$$       AIRGEAD   BANKING        $$$$$$$$"    << endl << ""
    "  $$$$$$$$       INVESTMENTS MADE EASY        $$$$$$$"   << endl << ""
    " $$$$$$$              (TOO  EASY)               $$$$$$"  << endl << ""
    "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl << endl << "";

}

// Clears cin buffer if a char is entered in InputMenu.
// Used for input validation.
void ClearInputOnError() {
    // Clears the buffer and ignores input.
    cin.clear();            
    cin.ignore(100, '\n');
    cout << "** Invalid input, please try again: ";
}

// Checks to see if input is negative number
// returns true for positive numbers, otherwise return false
bool DataValidation(auto data) {
    if (data >= 0) {
        return true;
    }
    else {
        cout << "Please enter a non negative number!!" << endl;
        return false;
    }
}

// Gather the info from the user for the investment input.
void InputMenu(Investment& newInvestment) {
    
    // place holder variables for user input
    double initialAmount = 0;
    double interest = 0;
    double deposit = 0;
    int year = 0;
        
    cout << "First, let's get some information from you...";
    
    // Menu portion. 
    PrintBorder();
    cout << right << setw(30) << "Investment Info";
    PrintBorder();
    // End menu portion.

    // User input section .*****************************************************
    // Each input will prompt until a positive input is taken
    do {
        cout << right << setw(45) << "What will be the initial Investment Amount: $";
        while (!(cin >> initialAmount)){
            ClearInputOnError();
        }
    } while (!DataValidation(initialAmount));
    
    do {
        cout<< right << setw(45) << "What is the monthly deposit Amount: $";
        while(!(cin >> deposit)){
            ClearInputOnError();
        }
    } while (!DataValidation(deposit));

    do {
        cout << right << setw(45) << "What interest rate are you thinking?: %";
        while(!(cin >> interest)){
            ClearInputOnError();
        }
    } while (!DataValidation(interest));

    do{
        cout << right << setw(45) << "and finally, for how many years:  ";
        while(!(cin >> year)){
            ClearInputOnError();
        }

        // Preventing long tables by limiting years to 99
        if (year >= 100){
            cout << "Too many years. Years should be less than 100" << endl;
            cout << "        Try again, I have all day" << endl; 
        }
    } while ((year >= 100) || (!DataValidation(year)) );
    // End user input section.**************************************************

    cin.ignore(); // Needed for cin.get() to pause awaiiting enter
    cout << setw(30) <<  "Press any key to continue...." << endl;;
    cin.get();

    // Setting data into newInvestment class.
    newInvestment.SetInitialAmount(initialAmount);
    newInvestment.SetDeposit(deposit);
    newInvestment.SetInterest(interest);
    newInvestment.SetYear(year);
    
}

// Used to print the borders
void PrintBorder(){
    cout << endl << setw(50) << setfill('_') << "" << endl;
    cout << setfill(' ');
}


// Takes the input as a string and parse into a char for selection input
// Gives the user to repeat and change data to calculate
char Selection(){
    
    string selTemp;
    char selection;
    
    cout << "To run again with new numbers enter \"Y\" " << endl;
    cout << " Or any other key to exit" << endl;
        
    getline(cin, selTemp);
    
    if ( selTemp.empty()) {
        selTemp = "1";
    }
    else {
        selection = toupper(selTemp.at(0));
    }
    

    if ( selection != 'Y' || selection != 'N'){
        cout << "Thank you for playing..." << "Goodbye";
    }

    return selection;

}