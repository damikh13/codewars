#include <string>

int dontGiveMeFive(int start, int end) // returns the number of integers between start and end (inclusive) that don't contain the digit 5
{
    int cnt = 0; // the number of integers between start and end (inclusive) that don't contain the digit 5

    for (int i = start; i <= end; ++i) // for all i from start to end
    {
        if (std::to_string(i).find('5') == std::string::npos) // if i doesn't contain the digit 5
        {
            ++cnt; // increment result
        }
    }

    return cnt; // return result
}