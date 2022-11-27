#include <string>

std::string reverse_string(std::string str) // returns str with the characters in reverse order
{
    std::string result = ""; // the reversed string
    for (int i = str.size() - 1; i >= 0; --i) // iterate through str in reverse order
    {
        result += str[i]; // add the current character to result
    } 

    return result; // return result
}

std::string reverse_words(std::string str) // returns str with the words reversed
{
    std::string ans = ""; // the string with the words reversed
    std::string curr_word = ""; // the current word

    for (char c : str) // iterate through str
    {
        if (c == ' ') // if we found a space
        {
            ans += reverse_string(curr_word) + " "; // add the reversed word to ans
            curr_word = ""; // reset curr_word
        }
        else // if we it's not a space
        {
            curr_word += c; // add the current character to curr_word
        }
    }

    ans += reverse_string(curr_word); // add the last word to ans

    return ans;
}