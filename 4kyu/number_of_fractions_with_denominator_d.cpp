#include <iostream>
#include <algorithm>

long euler(long d) // Euler's totient function
{
    long result = d; // initialize result as d
    for (long i = 2; i * i <= d; ++i) // for all i from 2 to sqrt(d)
    {
        if (d % i == 0) // if i is a divisor of d
        {
            while (d % i == 0) // while i is a divisor of d
            {
                d /= i; // divide d by i
            }
            result -= result / i; // subtract result / i from result
        }
    }

    if (d > 1) // if d is greater than 1
    {
        result -= result / d; // subtract result / d from result
    }

    return result; // return the result
}

long count_proper_fractions_with_denominator_d(long denominator)
{
    return (denominator == 1) ? 0 : euler(denominator); // if denominator is 1, return 0, otherwise return the result of the Euler's totient function
}