#include <string>
#include <cmath>

bool narcissistic(int value) // returns true if value is narcissistic, false otherwise
{
    int number_of_digits = log10(value) + 1; // get number of digits
    int sum = 0; // sum of digits raised to the power of number_of_digits
    int temp = value; // temporary variable

    for (int i = 0; i < number_of_digits; ++i) // iterate from 0 to number_of_digits
    {
        sum += pow(temp % 10, number_of_digits); // add the last digit of temp raised to the power of number_of_digits to sum
        temp /= 10; // remove the last digit of temp
    }

    return sum == value; // return true if sum is equal to value, false otherwise
}