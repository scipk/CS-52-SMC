#include <iostream>

using namespace std;

// Welcome to 3N+1 calculator.

int main() {
    int n;
    int i;

    // Welcome
    cout << "Welcome to the 3N+1 calculator!\n\nThis is the Collatz Conjecture, also known as\n'The Simplest Math Problem No One Can Solve' according to Veritasium."
         << "\n==============================" << endl;
    
    // Enter starting number
    cout << "Please enter the starting number: ";
    cin >> n;

    // Run until it reaches 1
    while (n != 1) {
        // test for even
        if (n % 2 == 0) {
            n = n / 2;
            cout << endl << "Even: " << n;
            i++;
        } else {
            n = (3 * n) + 1;
            cout << endl << "Odd: " << n;
            i++;
        } // else it's odd
    }

    // End
    cout << endl << "It tooks us " << i << " iterations to reach 1. Have a pleasant day!";

    char closer; cin >> closer;
}