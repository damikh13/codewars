#include <string>

long long filter_string(const std::string &value) // returns the number in value
{
    long long ans = 0; // the number in value
    long long curr_scaling = 1; // the current scaling factor

    for (int i = value.size() - 1; i >= 0; --i) // for all i from value.size() - 1 to 0
    {
        char curr_char = value[i]; // the current character

        if (curr_char >= '0' && curr_char <= '9') // if current character is a digit
        {
            ans += (curr_char - '0') * curr_scaling; // add the digit to ans
            curr_scaling *= 10; // multiply curr_scaling by 10
        }
    }

    return ans; // return answer
}