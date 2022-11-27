#include <string>
#include <map>

bool is_prime(int n) // checks if n is prime
{
    if (n <= 1) // if n is less than or equal to 1
    {
        return false; // return false
    }

    for (int i = 2; i * i <= n; ++i) // iterate through the numbers from 2 to sqrt(n)
    {
        if (n % i == 0) // if n is divisible by i
        {
            return false; // return false
        }
    }

    return true; // return true
}

std::string decompose_factorial_of_n_into_prime_factor(int n) // returns the decomposition of the factorial of n into prime factors
{
    std::map<int, int> number_of_prime_factors; // prime factors of n!
    for (int curr_factor = 2; curr_factor <= n; ++curr_factor) // iterate through the numbers from 2 to n
    {
        int curr_factor_saved = curr_factor; // save the current factor

        // decomposing curr_factor
        for (int possible_div = 1; possible_div * possible_div <= curr_factor; ++possible_div) // iterate through the numbers from 1 to sqrt(curr_factor)
        {
            if (curr_factor % possible_div == 0) // if possible_div is a divisor of curr_factor
            {
                if (is_prime(possible_div)) // and if possible_div is prime
                {
                    // divide while its possible to divide 
                    while (curr_factor % possible_div == 0)
                    {
                        ++number_of_prime_factors[possible_div]; // increment the number of possible_div in number_of_prime_factors
                        curr_factor /= possible_div; // divide curr_factor by possible_div
                    }
                    curr_factor = curr_factor_saved; // restore curr_factor
                }

                // if there are complementary divisors
                if (possible_div * possible_div != curr_factor)
                {
                    int complementary_divisor = curr_factor / possible_div; // complementary divisor
                    if (is_prime(complementary_divisor)) // if complementary_divisor is prime
                    {
                        // divide while its possible to divide
                        while (curr_factor % complementary_divisor == 0)
                        {
                            ++number_of_prime_factors[complementary_divisor]; // increment the number of complementary_divisor in number_of_prime_factors
                            curr_factor /= complementary_divisor; // divide curr_factor by complementary_divisor
                        }
                    }
                }
            }
        }

        curr_factor = curr_factor_saved; // restore curr_factor
    }

    // creating the result
    std::string output = ""; // result
    bool first_was_taken = false; // if the first element was taken
    for (auto now : number_of_prime_factors) // iterate through all the prime factors
    {
        if (first_was_taken)
        {
            output += " * "; // add a space and a star
        }

        if (now.second == 1) // if there's only one of the prime factors
        {
            output += std::to_string(now.first); // add the prime factor to the result
        }

        else
        {
            output += std::to_string(now.first) + '^' + std::to_string(now.second); // add the prime factor and its power to the result
        }

        if (!first_was_taken)
        {
            first_was_taken = true; // the first element was taken
        }
    }

    return output; // return the result
}