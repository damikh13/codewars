#include <string>

using namespace std;

int find_short(std::string str) // returns the length of the shortest word in str
{
    int shortest_word_length = INT_MAX; // the length of the shortest word in str
    int curr_word_length = 0; // the length of the current word

    for (char c : str) // iterate through str
    {
        if (c == ' ') // if we found a space
        {
            shortest_word_length = min(shortest_word_length, curr_word_length); // update shortest_word_length
            curr_word_length = 0; // reset curr_word_length
        }
        else // if we it's not a space
        {
            ++curr_word_length; // increment curr_word_length
        }
    }
    shortest_word_length = min(shortest_word_length, curr_word_length); // update shortest_word_length one last time

    return shortest_word_length;
}