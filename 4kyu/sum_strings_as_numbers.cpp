#include <string>

std::string sum_strings_as_two_numbers(const std::string& a, const std::string& b) // returns the sum of two numbers that are given as strings
{
    // edge cases
    if (a == "0")
    {
        return b;
    }
    else if (b == "0")
    {
        return a;
    }

    std::string result = ""; // the result of the sum
    size_t a_size = a.size(); // the size of the first number so that it doesn't have to be calculated every time
    size_t b_size = b.size(); // the size of the second number so that it doesn't have to be calculated every time
    size_t i = 0; // the index of the first number
    size_t j = 0; // the index of the second number
    int carry = 0; // the carry

    while (i < a_size || j < b_size) // while the index of the first number is less than the size of the first number or the index of the second number is less than the size of the second number
    {
        int curr_sum = carry; // the current sum

        if (i < a_size) // if the index of the first number is less than the size of the first number
        {
            curr_sum += a[a_size - i - 1] - '0'; // add the current digit of the first number to the current sum
            ++i; // increment the index of the first number
        }

        if (j < b_size) // if the index of the second number is less than the size of the second number
        {
            curr_sum += b[b_size - j - 1] - '0'; // add the current digit of the second number to the current sum
            ++j; // increment the index of the second number
        }

        result += curr_sum % 10 + '0'; // add the current digit to the result
        carry = curr_sum / 10; // set the carry
    }

    if (carry != 0) // if the carry is not 0
    {
        result += carry + '0'; // add the carry to the result
    }

    return std::string(result.rbegin(), result.rend()); // return the result
}