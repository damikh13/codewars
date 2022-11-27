#include <string>
using namespace std;

string balancedNum(unsigned long long int number) // returns "Balanced" if number is balanced, "Not Balanced" otherwise
{
    string number_string = to_string(number); // string representation of number
    size_t number_of_digits = number_string.size(); // number of digits in number
    int left_sum = 0; // sum of the first half of the digits of number
    int right_sum = 0; // sum of the second half of the digits of number

    for (size_t i = 0; i < number_of_digits / 2; ++i) // for all i from 0 to number_of_digits / 2 - 1
    {
        left_sum += number_string[i] - '0'; // add the digit at number_string[i] to left_sum
    }

    for (size_t i = number_of_digits / 2 + 1; i < number_of_digits; ++i) // for all i from number_of_digits / 2 + 1 to number_of_digits - 1
    {
        right_sum += number_string[i] - '0'; // add the digit at number_string[i] to right_sum
    }

    return right_sum == left_sum ? "Balanced" : "Not Balanced";
}