int divisors(int n) // returns the number of divisors of n
{  
    int cnt = 0; // the number of divisors of n

    for (int i = 1; i * i <= n; ++i) // all the divisors are less than sqrt(n)
    {
        if (n % i == 0) // i is a divisor
        {
            if (i * i == n) // i is a square root of n
            {
                ++cnt; // count only once
            }
            else // i is not a square root of n
            {
                cnt += 2; // i and (n / i) are divisors
            }
        }
    }

    return cnt; // return the number of divisors of n
}