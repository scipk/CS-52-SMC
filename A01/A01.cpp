/*
    I'm using Windows 10 as my operating system. 
    I'll be using Visual Studio Code as my IDE, where I have installed g++ as the C++ code compiler.
*/

// Name : Parham Khodadi
// SSID : 1713519
// Assignment #: 1
// Submission Date : 3/2/22
//
//
// Program Description :
// This program totals deposits and withdrawls
// transations from an opening balance
//

#include <iostream>

using namespace std;

int main()
{
    // Variable balance for total transactions
    double balance = 0.00;
    // Variable transaction as shell for each transaction
    double transaction = 1;

    // Assign balance
    cout << "Please enter a non-zero balance: ";
    cin >> balance;

    // While loop that that receives a transaction then applies it to the balance immediately.
    cout << "Please enter transactions (+ for deposits or - for widrawals), and use 0 to end list.\n";
    while (transaction != 0)
    {
        // Assign a value to transaction until it's 0, then leave while loop
        cin >> transaction;
        balance = balance + transaction;
    };

    // Tell user their final balance after applied transactions
    cout << "Your current balance is: " << balance;

    // Termination
    char KeyToExit;
    cout << "\nEnter any alphanumeric key to exit:\n";
    cin >> KeyToExit;
    return 0;
}// main