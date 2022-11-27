#include <string>

bool isAnagram(std::string test, std::string original) // returns true if test is an anagram of original, false otherwise
{
    unsigned short int letters1[26]{}; // array of letters in test
    unsigned short int letters2[26]{}; // array of letters in original

    for (char c : test) // for all c in test
    {
        letters1[c - 'a']++; // increment the number of c in letters1
    }

    for (char c : original) // for all c in original
    {
        letters2[c - 'a']++; // increment the number of c in letters2
    }

    for (size_t i = 0; i < 26; ++i) // for all i from 0 to 25
    {
        if (letters1[i] != letters2[i]) // if the number of letters in letters1 and letters2 is not equal
        {
            return false; // return false
        }
    }
}