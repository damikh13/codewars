#include <string>

bool is_isogram(std::string str) // returns true if str is an isogram, false otherwise
{
    bool used_letters[26]{}; // used_letters[i] is true if the letter i + 'a' has been used, false otherwise

    for (char c : str) // for all c in str
    {
        if (c >= 'A' && c <= 'Z') // if c is uppercase
        {
            c += 'a' - 'A'; // convert c to lowercase
        }
        if ('a' <= c && c <= 'z') // if c is a letter
        {
            if (used_letters[c - 'a']) // if c has been used
            {
                return false; // return false
            }
            used_letters[c - 'a'] = true; // set used_letters[c - 'a'] to true
        }
    }

    return true;
}