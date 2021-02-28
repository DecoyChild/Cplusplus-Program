/*
 * Shayne Greene
 * Airgead Investment Banking/ 1.1
 * Member functions for Investment Class
 */


#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "Investment.h"

using namespace std;

Investment::Investment() {
}

// Overloaded constructor.
Investment::Investment(double initialAmount, double deposit, double interest, int year ) {
    
    this->initialAmount = initialAmount;
    this->deposit       = deposit;
    this->interest      = interest;
    this->year          = year;
    
}

// This will calculate and display the investment totals with 
// a deposit factored in.
void Investment::InvestmentTable(bool depositMade) {

    // Helper variables
    total = 0;
    currInterest = 0;
    closingBalance = initialAmount;

    PrintTableTitle(depositMade);

    // Outer loop iterates for the amount of years the used enters
    for (int i = 0; i < year; i++) {
        
        // Resets the interest total after each year.
        interestTotal = 0;
        
        // Loops through each month calculating compounded interest
        for (int j = 0; j < 12; j++) {
            
            // Will add the deposit if 'depositMade' is set to true.
            if(depositMade){
                total = deposit + closingBalance;
            }
            else{ // Will skip the deposit if 'depositMade' is false.
                total = closingBalance;
            }

            // Calculates the monthly balance 
            currInterest = (total * ((interest/100.00)/12.00));
            closingBalance = total + currInterest;
            
            // Keeps a running total of the interest accumulated
            interestTotal = interestTotal + currInterest;    
        }
        
        // Prints the calculates for each year.
        cout << setfill(' ');
        cout << fixed << setprecision(2);
        cout << setw(5) << "Year " << setw(3) << left << (i + 1);
        cout << right << setw(15) << "$"  << setw(10) << closingBalance;
        cout << setw(30) << "$"  << setw(10) << interestTotal << endl;

    }
    
    // Prints the bottom border.
    cout << setw(80) << setfill(borderChar) << "" << endl;
    cout << setw(80) << setfill('=') << "" << endl << endl << endl << endl;
} 

// Will Pring the table header
void Investment::PrintTableTitle(bool depositMade){
    
    cout << setw(80) << setfill('=') << "" << endl;

        // Branches depending on deposit status / true / false.
    if (depositMade){

        // Prints the top portion of the data table.
        cout << "  I n v e s t m e n t  C a l c u l a t i o n s   W i t h   D e p o s i t s " << endl;
        cout << setw(80) << setfill('=') << "" << endl;
        
        // Will show the user the data the as entered.
        cout << fixed << setprecision(2);
        cout  << "  Init Amt: $"       << initialAmount 
              << "   |    Deposit: $"  << deposit
              << "   |    Rate: "      << interest
              << "   |    Years: "     << year << endl;
    }
    else{
        
        cout << "I n v e s t m e n t  C a l c u l a t i o n s   W i t h o u t   D e p o s i t s" << endl;
        cout << setw(80) << setfill('=') << "" << endl;
        
        cout  << "\t Init Amt: $"  << initialAmount 
              << "\t|    Rate: "  << interest
              << "\t|    Years: " << year << endl;
    }
    
       // Displays the table field title.
    cout << setw(80) << setfill(borderChar) << "" << endl;
    cout << setfill(' ');
    cout << setw(35) << "Year End Balance"  << setw(40) << "Year End Interest" << endl;
    cout << setw(80) << setfill(borderChar) << "" << endl;
    // End display top portion of the table****************************************
}