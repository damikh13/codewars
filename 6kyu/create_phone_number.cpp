#include <string>

std::string createPhoneNumber(const int arr [10]) // returns a string with the phone number from the array arr
{
    std::string result = "("; // the result string

    for (size_t i = 0; i < 10; ++i) // for all i from 0 to 9
    {
        result += std::to_string(arr[i]); // add arr[i] to the result string
        if (i == 2) // if i is 2
        {
            result += ") "; // add ") " to the result string
        }
        else if (i == 5) // if i is 5
        {
            result += "-"; // add "-" to the result string
        }
    }
    
    return result; // return the result string
}