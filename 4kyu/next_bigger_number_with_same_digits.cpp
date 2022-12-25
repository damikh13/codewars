#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>

inline long long next_bigger_number_with_the_same_digits_using_inbuilt_capabilities(long long number)
{
    std::string str = std::to_string(number); // convert number to string
    
    // find the next permutation of the string if it exists
    if (std::next_permutation(str.begin(), str.end()))
    {
        return std::stoll(str); // convert string to number and return it
    }

    return -1; // return -1 if no next permutation exists
}

inline long long next_bigger_number_with_the_same_digits_custom(long long number)
{
    std::string number_str = std::to_string(number); // convert number to string

    // check if number contains only one digit
    if (number_str.size() == 1)
    {
        return -1;
    }

    // finding two adjacent digits that are in descending order
    int i = number_str.size() - 1; // index of the first digit
    int j = number_str.size() - 2; // index of the second digit
    while (j >= 0 && number_str[j] >= number_str[i])
    {
        --i;
        --j;
    }

    // if there is no such pair, return -1
    if (j < 0)
    {
        return -1;
    }

    std::cout << "i = " << i << std::endl;
    std::cout << "j = " << j << std::endl;
    
    // find the smallest digit that is greater than number_str[j]
    int k = number_str.size() - 1;
    while (number_str[k] <= number_str[j])
    {
        --k;
    }

    // swap number_str[j] and number_str[k]
    std::swap(number_str[j], number_str[k]);

    // sort the rest of the digits
    std::sort(number_str.begin() + j + 1, number_str.end());

    return std::stoll(number_str); // convert string to long long and return it
}

int main()
{
    long long number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    // estimate the time of execution of the function
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << next_bigger_number_with_the_same_digits_using_inbuilt_capabilities(number) << std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Time of execution of the function next_bigger_number_with_the_same_digits_using_inbuilt_capabilities: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds" << std::endl;

    // estimate the time of execution of the function
    start = std::chrono::high_resolution_clock::now();
    std::cout << next_bigger_number_with_the_same_digits_custom(number) << std::endl;
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Time of execution of the function next_bigger_number_with_the_same_digits_custom: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds" << std::endl;
}