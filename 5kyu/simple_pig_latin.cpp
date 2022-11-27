#include <string>

std::string make_latin_word_of(std::string& word) // makes a latin word from a word
{
    return word.substr(1) + word[0] + "ay";
}

std::string pig_it(std::string str) // moves the first letter of each word to the end of it, then adds "ay" to the end of the word
{
    std::string result = "";
    std::string curr_word = "";

    for (int i = 0; i < str.length(); i++) // iterating through the string
    {
        if (str[i] == ' ') // if the current character is a space
        {
            result += make_latin_word_of(curr_word) + " "; // adding the latin word to the result string
            curr_word = ""; // resetting the current word
        }
        else // if the current character is not a space
        {
            curr_word += str[i]; // adding the current character to the current word
        }
    }

    return result + make_latin_word_of(curr_word); // adding the last latin word to the result string
}