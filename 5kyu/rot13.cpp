#include <string>

std::string rot13(std::string msg) // returns the ROT13 encryption of msg
{
    for (char& c : msg) // iterate through msg
    {
        if (c >= 'a' && c <= 'z') // if c is a lowercase letter
        {
            c = (c - 'a' + 13) % 26 + 'a'; // encrypt c
        }
        else if (c >= 'A' && c <= 'Z') // if c is an uppercase letter
        {
            c = (c - 'A' + 13) % 26 + 'A'; // encrypt c
        }
    }
    
    return msg; // return the encrypted message
}