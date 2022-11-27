#include <string>
#include <map>

std::string duplicate_encoder(const std::string& word) // returns a string with the duplicate encoder of word
{
    std::map<char, int> frequency_of_char; // frequency of each character in word
    std::string result; // the result string

    for (size_t i = 0; i < word.size(); ++i) // for all i from 0 to word.size() - 1
    {
        frequency_of_char[tolower(word[i])]++; // increment the value of the character at word[i]
    }

    for (size_t i = 0; i < word.size(); ++i) // for all i from 0 to word.size() - 1
    {
        if (frequency_of_char[tolower(word[i])] == 1) // if the character at word[i] appears only once
        {
            result += '('; // add "(" to the result string
        }
        else // if the character at word[i] appears more than once
        {
            result += ')'; // add ")" to the result string
        }
    }

    return result; // return the result string
}