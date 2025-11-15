// Name : Parham Khodadi
// SSID : 1713519
// Assignment #: 2
// Submission Date : 3/21/2022
//
// Description : A program to encrypt and decrypt a message using a shift cipher
// The plaintext message must only contain the codebook characters
//
// command line arguments
// -p ThePla?Nt]xTM]ss2ge1? - the plaintext (p) message to be encrypted
// -C pC9lG1VjOwSpiwNNXB9xV - the cipher (C) text to be decrypted
// -k 9 - the key (k) shift value
// -E - the option to encrypt (E)
// -D - the option to decrypt (D)
//

#include <iostream> //std::cout, std::cin, etc.
#include <cstdlib> //C++ version of stdlib.h
#include <cstring> //C++ version of string.h
#include <string>

#define CBL 64 // Codebook length

char codebook[] = {'Z','z','Y','y','X','x','W','w','V','v','U','u','T','t','S','s','R','r','Q','q','P','p','O','o','N','n','M','m','L','l','K','k','J','j','I','i','H','h','G','g','F','f','E','e','D','d','C','c','B','b','A','a','9','8','7','6','5','4','3','2','1','0',']','?'};
// Todo A2: encrypt using std::string
void encrypt(std::string& plaintext, int k);

// Todo A2: decrypt using std::string
void decrypt(std::string& ciphertext, int k);

int main(int argc, char *argv[])
{
    // Example variables for A02
    int k = 0; // k shift
    int msg_index = 0; // msg_index of plaintext or ciphertext in argv
    std::string msg; // string to hold the plaintext or ciphertext
    bool do_encrypt = false; // True for encrypt or False for decrypt

    // Todo A2: process the command line arguments
    for (int i = 1; i < argc; ++i)
    {
        // use strcmp to compare command line switches to argv[i]
        if (strcmp(argv[i], "-p") == 0)
        {
            msg_index = i+1; // record the array index of the plaintext
            msg = argv[msg_index]; // assign the string 'msg' to the plaintext
        }
        if (strcmp(argv[i], "-C") == 0)
        {
            msg_index = i+1; // record the array index of the ciphertext
            msg = argv[msg_index]; // assign the string 'msg' to the ciphertext
        }
        if (strcmp(argv[i], "-k") == 0)
        {
            k = *argv[++i] - '0'; // assign the value of k to the ASCII converted value of the array index after "-k"
        }
        if (strcmp(argv[i], "-E") == 0)
        {
            do_encrypt = true; // make program encrypt the plaintext
        }
        if (strcmp(argv[i], "-D") == 0)
        {
            do_encrypt = false; // make program decipher the ciphertext
        }
    }

    //
    // Todo A2: call encrypt or decrypt functions
    //
    if (do_encrypt) // encrypt plaintext
        encrypt(msg, k);
    else
        decrypt(msg, k); // decrypt ciphertext

    //
    // Todo A2: print the original message and the plaintext | ciphertext
    //
    if (do_encrypt) // Plaintext input, Ciphertext output
    {
        std::cout << "The plaintext was: " << argv[msg_index];
        std::cout << "\nThe ciphertext is: " << msg << "\n";
    }
    else // Ciphertext input, Plaintext output
    {
        std::cout << "The ciphertext was: " << argv[msg_index];
        std::cout << "\nThe plaintext is: " << msg << "\n";
    }

    system("pause");
    return 0;
} // main

// Todo A2: function definitions go here
void encrypt(std::string& plaintext, int k)
{
    for (int i = 0; i < plaintext.length(); ++i)
    {
        int codebook_index; // Index position of the symbol in the codebook.
        for (int j = 0; j < CBL; ++j) // For loop to find the index of symbol in codebook.
        {
            if (plaintext[i] == codebook[j])
            {
                codebook_index = j;
            }
        }
        plaintext[i] = codebook[(codebook_index + k) % CBL]; // Replace the plaintext character with its codebook equivalent ciphertext using the formula
    }
}

void decrypt(std::string& ciphertext, int k)
{

    for (int i = 0; i < ciphertext.length(); i++)
    {
        int codebook_index; // Index position of the symbol in the codebook.
        for (int j = 0; j < CBL; ++j) // For loop to find the index of symbol in codebook.
        {
            if (ciphertext[i] == codebook[j])
            {
                codebook_index = j;
            }
        }
        if ((codebook_index - k) < 0) // Replace the ciphertext with its codebook equivalent plaintext using the formula
        {
            ciphertext[i] = codebook[(((codebook_index - k) % CBL) + CBL) % CBL];
        }
        else
        {
            ciphertext[i] = codebook[(codebook_index - k) % CBL];
        }
    }
}