#include <iostream>
#include <vector>
#include <string>

std::string multiply_strings_as_two_numbers(std::string& a, std::string& b) // returns the product of two numbers that are given as strings
{
    // edge cases
    if (a == "0" || b == "0")
    {
        return "0";
    }

    std::vector<int> result(a.size() + b.size(), 0); // the result of the multiplication
    size_t a_size = a.size(); // the size of the first number so that it doesn't have to be calculated every time
    size_t b_size = b.size(); // the size of the second number so that it doesn't have to be calculated every time

    for (size_t i = 0; i < a_size; ++i) // iterate through the first number
    {
        for (size_t j = 0; j < b_size; ++j) // iterate through the second number
        {
            int curr_product = (a[a_size - i - 1] - '0') * (b[b_size - j - 1] - '0'); // the current product
            int curr_sum = result[i + j] + curr_product; // the current sum
            result[i + j] = curr_sum % 10; // the current digit
            result[i + j + 1] += curr_sum / 10; // the carry
        }
    }

    std::string result_str = ""; // the result of the multiplication as a string
    size_t result_size = result.size();

    for (size_t i = 0; i < result_size; ++i) // iterate through the result
    {
        if (result[result_size - i - 1] != 0 || result_str != "") // if the current digit is not 0 or if the result is not empty
        {
            result_str += result[result_size - i - 1] + '0'; // add the current digit to the result
        }
    }

    return result_str; // return the result
}