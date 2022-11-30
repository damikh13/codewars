#include <iostream>
#include <cmath>

typedef unsigned long long ull;

ull number_of_ones_of_power_of_2(unsigned char power) // returns number of ones in binary of [1, 2^power]
{
    ull* number_of_ones_of_powers_of_2 = new ull[64]; // 63 is the maximum power of 2 that can be represented by long long
    /*
        2^0:
            00 -> 0
            01 -> 1
            -------------
            total = 0 + 1 = 1
        2^1:
            00 -> 0
            01 -> 1
            10 -> 1
            -------------
            total = 0 + 1 + 1 = 2
    */
    number_of_ones_of_powers_of_2[0] = 1;
    number_of_ones_of_powers_of_2[1] = 2;

    for (int i = 2; i < 64; ++i) // filling the array
    {
        /*
        adding one more bit to existing truth table means:
            1. doubling the number of ones that are already in the table
            2. adding the number of ones that are in the new bit
        */
        number_of_ones_of_powers_of_2[i] = 2 * (number_of_ones_of_powers_of_2[i - 1] - 1) + pow(2, i - 1) + 1;
    }

    return number_of_ones_of_powers_of_2[power]; // returning the number of ones in binary of [1, 2^power]
}

ull count_binary_ones_from_1_to_n_recursive(ull number) // returns number of ones in binary of [1, number]
{
    // recursion base case
    if (number <= 1)
    {
        return number;
    }

    // finding the highest power of 2 that is smaller than number
    unsigned char highest_power_of_2 = (int)log2(number);

    // finding the number of ones in binary of [1, 2^highest_power_of_2)
    ull all_ones_before_highest_power_of_2 = number_of_ones_of_power_of_2(highest_power_of_2) - 1;

    // finding the number of ones of new bit after highest power of 2
    ull ones_of_new_bit = number - pow(2, highest_power_of_2) + 1;

    // finding the number of ones in number that is 1 digit smaller than number (e.g. 11010 -> 1010)
    ull ones_of_smaller_number = count_binary_ones_from_1_to_n_recursive(number - pow(2, highest_power_of_2));

    return all_ones_before_highest_power_of_2 + ones_of_new_bit + ones_of_smaller_number; // returning the number of ones in binary of [1, number]
}

ull count_binary_ones_from_1_to_n_iterative(ull number) // returns number of ones in binary of [1, number]
{
    ull ones = 0; // number of ones in binary of [1, number]

    while (number > 0)
    {
        // finding the highest power of 2 that is smaller than number
        unsigned char highest_power_of_2 = (int)log2(number);

        // finding the number of ones in binary of [1, 2^highest_power_of_2)
        ull all_ones_before_highest_power_of_2 = number_of_ones_of_power_of_2(highest_power_of_2) - 1;

        // finding the number of ones of new bit after highest power of 2
        ull ones_of_new_bit = number - pow(2, highest_power_of_2) + 1;

        ones += all_ones_before_highest_power_of_2 + ones_of_new_bit; // adding the number of ones in binary of [1, number]

        number -= pow(2, highest_power_of_2); // removing the highest power of 2 from number
    }

    return ones; // returning the number of ones in binary of [1, number]
}

int main()
{
    std::cout << "Enter a number: ";
    ull number;
    std::cin >> number;

    std::cout << "Number of ones in binary of [1, " << number << "] is " << count_binary_ones_from_1_to_n_recursive(number) << " (recursive)" << std::endl;
    std::cout << "Number of ones in binary of [1, " << number << "] is " << count_binary_ones_from_1_to_n_iterative(number) << " (iterative)" << std::endl;
}