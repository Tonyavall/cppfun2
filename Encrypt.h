// Tony Vallescas
// CISP 400 | CISP400V10A2

// Encrypt.h
// Encrypt class definition. This file presents Encrypt's public 
// interface without revealing the implementations of Encrypt's member
// functions, which are defined in Encrypt.cpp.

// Encrypt class definition
class Encrypt
{
public:
    explicit Encrypt( int ); // constructor initialize digits
    void getDigits();
    void displayOriginalData();
    void storeData( int );
    void displayEncryptedData();
private:
    int digits[8];
};


