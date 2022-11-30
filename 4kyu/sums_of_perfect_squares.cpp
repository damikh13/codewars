#include <iostream>
#include <cmath>
#include <chrono>

int min_num_of_perfect_squares_recursive(int number) // returns min number of perfect squares the number can be represented as
{
    // base of recursion
    if (number <= 3)
    {
        return number;
    }

    // if number is a perfect square
    int sqrt = (int)std::sqrt(number);
    if (sqrt * sqrt == number)
    {
        return 1;
    }


    int result = number; // worst case: number = 1 + 1 + ... + 1

    for (int current_root = 2; current_root * current_root <= number; ++current_root) // iterate over all possible roots
    {
        // for each root, find best possible representation of the number
        int current_square = current_root * current_root;
        int current_num_of_perfect_squares = 1 + min_num_of_perfect_squares_recursive(number - current_square);

        result = std::min(result, current_num_of_perfect_squares); // update result if a better representation was found
    }

    return result; // return best possible representation
}

int min_num_of_perfect_squares_iterative(int number) // returns min number of perfect squares the number can be represented as
{
    int* dp = new int[number + 1]; // dp[i] = min number of perfect squares the number i can be represented as

    // base cases
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for (int i = 4; i <= number; ++i) // iterate over all numbers
    {
        // if number is a perfect square
        int sqrt = (int)std::sqrt(i);
        if (sqrt * sqrt == i)
        {
            dp[i] = 1;
            continue;
        }

        dp[i] = i; // worst case: number = 1 + 1 + ... + 1

        for (int current_root = 2; current_root * current_root <= i; ++current_root) // iterate over all possible roots
        {
            // for each root, find best possible representation of the number
            int current_square = current_root * current_root;
            int current_num_of_perfect_squares = 1 + dp[i - current_square];

            dp[i] = std::min(dp[i], current_num_of_perfect_squares); // update result if a better representation was found
        }
    }

    int result = dp[number];
    delete[] dp;
    return result; // return best possible representation
}

int min_num_of_perfect_squares_mathematical(int number) // returns min number of perfect squares the number can be represented as
{
    // if number is a perfect square itself
    int sqrt = (int)std::sqrt(number);
    if (sqrt * sqrt == number)
    {
        return 1;
    }

    // if number can be represented as sum of two squares
    for (int i = 1; i * i <= number; ++i)
    {
        int sqrt = (int)std::sqrt(number - i * i);
        if (sqrt * sqrt == number - i * i)
        {
            return 2;
        }
    }

    // if number can be represented as 4^k * (8m + 7)
    while (number % 4 == 0)
    {
        number /= 4;
    }
    if (number % 8 == 7)
    {
        return 4;
    }

    // otherwise number can be represented as sum of 3 squares
    return 3;
}

int main()
{
    int number;
    std::cin >> number;

    // estimate time of execution of the iterative function
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "Iterative: " << min_num_of_perfect_squares_iterative(number) << std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    // estimate time of execution of the mathematical function
    start = std::chrono::high_resolution_clock::now();
    std::cout << "Mathematical: " << min_num_of_perfect_squares_mathematical(number) << std::endl;
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;
    
    return 0;
}