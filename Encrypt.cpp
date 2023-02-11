// Encrypt.cpp
// Encrypt member-function definitions. This file contains
// implementations of the member functions prototyped in Encrypt.h.

#include <iostream>
#include <string> // Include string library for string manipulation functions to be used later
#include "Encrypt.h"

Encrypt::Encrypt( int userNum )
    // Empty constructor initialization for array
    // because we set the values individually later on
    // in storeData function
    : digits()
{
    // Storing data, encrypting it, and displaying 
    storeData(userNum); 
    displayOriginalData();
    displayEncryptedData();
}

// Displays original digits in array elements 1-4
void Encrypt::displayOriginalData() 
{
    std::cout << "\n     The original data is ";

    for (int i = 0; i < 4; i++) {
        std::cout << ' ' << digits[i] << ' ';
    }
}

// Function that takes in userNum as param and encrypts data, storing it in digits private member data array
void Encrypt::storeData( int userNum ) {
    std::cout << "\n\n** The default constructor is called\n"
              << "   and the passed in number is " << userNum << ".**"
              << std::endl;

    if (userNum <= 0) {
        std::cout << "\n XXX The inputed number is less than or equal to 0\n"
                  << "     The number is reset to 9436. XXX"
                  << std::endl;

        // If userNum is less than or equal to 0, we set first 4 digits to 9436
        digits[0] = 9;
        digits[1] = 4;
        digits[2] = 3;
        digits[3] = 6;
    } else {
        // Stringifying userNum so we can iterate through it digit by digit
        std::string stringifiedUserInput = std::to_string(userNum);
        const int inputLength = stringifiedUserInput.length();

        // Index to start to store future integer input into digits array
        int j = 3;
        // Starting at the last index, we iterate up to 4 elements
        for (int i = inputLength - 1; i >= (inputLength - 4); i--)
        {
            // Reconverting to integer
            // Getting ascii of single character and subtracting 48 (starting value of ascii)
            // to get integer of the user input
            int integerUserInput = stringifiedUserInput[i] - 48;
            
            // Check to see if integerUserInput logs the correct values with addition of 2
            // std::cout << integerUserInput + 2 << std::endl;

            // Setting the first 4 elements in digits as integerUserInput
            if (integerUserInput == -48) {
                // If the digits of user input was less than 4 and that we're on that missing value
                // within the array on the current iteration, we set the digit to be 0, instead of -48
                digits[j] = 0;
            } else {
                // Otherwise we set the current iterations integerUserInput as the digit 
                // to be encrypted later on.
                digits[j] = integerUserInput;
            }
            j--;
        };
    };

    // The value we increment by to get last 4 elements of digits array
    int j = 4;

    // We get the first 4 elements in digits array, encrypt them,
    // and store them in the last 4 elements of digits[8] array.
    for (int i = 0; i < 4; i++)
    {
        int encryptedDigit = (digits[i] + 7) % 10;
        
        digits[j] = encryptedDigit;

        j++;
    }

    // Performing the swaps
    std::swap(digits[4], digits[6]);
    std::swap(digits[5], digits[7]);
}

// Displays encrypted digits in array elements 5-8
void Encrypt::displayEncryptedData()
{
    std::cout << "\n     The encrypted data is ";

    for (int i = 4; i < 8; i++) {
        std::cout << ' ' << digits[i] << ' ';
    }
    
    std::cout << std::endl;
}

