#include "Container.h"
 
int main () {
    // Test overloaded - operator
    CS52::Container m(5, 3);
    CS52::Container n(3, 0);
    n[0] = 55; n[1] = 100; n[2] = 500;

    CS52::Container o = n - m;

        std::cout << "Test overloaded - operator \n";
        std::cout << "m = [3, 3, 3, 3, 3], n = [55, 100, 500]\n";
        std::cout << "o = n - m = [" << o << "]\n";

    const int SIZE = 2;
    CS52::Sequence* sequence[SIZE];

        sequence[0] = new CS52::Container(5, 11);
        sequence[1] = new CS52::Container(3, 7);

    // Print out the type and length of each Sequence element
    std::cout << "\nTest polymorphism \n";

    for (int i = 0; i < SIZE ; i++){
        std::cout << "Sequence [" << i << "]" << " is a "
                  << sequence[i]->type() << ": "
                  << *(dynamic_cast<CS52::Container*> (sequence [i]))
                  << "\n";}

    for (int i = 0; i < 2; i++)
        delete sequence [i];
    char stopper; std::cin >> stopper;
}
