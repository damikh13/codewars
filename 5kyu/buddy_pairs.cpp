#include <iostream>
#include <string>

inline long long sum_of_proper_divs(long long x) // sum of proper divisors of x
{
    int result = 1; // 1 is a proper divisor of every number
    for (int i = 2; i * i <= x; ++i) // for all i from 2 to sqrt(x)
    {
        if (x % i == 0) // if i is a divisor of x
        {
            result += i; // add i to the result
            if (i * i != x) // if i is not a square root of x
            {
                result += x / i; // add x / i to the result
            }
        }
    }
    
    return result; // return the result
}

std::string buddy(long long start, long long limit) // returns a string with the smallest pair of buddy numbers in the range [start, limit]
{
    for (long long i = start; i <= limit; ++i) // iterate through the range [start, limit]
    {
        long long sum_of_proper_divs_of_i = sum_of_proper_divs(i); // sum of proper divisors of i
        if (sum_of_proper_divs_of_i > i && sum_of_proper_divs(sum_of_proper_divs_of_i) == i) // if i is a buddy number
        {
            return "(" + std::to_string(i) + " " + std::to_string(sum_of_proper_divs_of_i) + ")"; // return the pair of buddy numbers
        }
    }
    
    return "Nothing"; // if no buddy numbers were found, return "Nothing"
}