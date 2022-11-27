int sum_of_digits(int n) // returns the sum of the digits of n
{
    int sum = 0; // sum of the digits of n

    while (n > 0) // while n is greater than 0
    {
        sum += n % 10; // add the last digit of n to sum
        n /= 10; // remove the last digit of n
    }

    return sum; // return sum
}

int digital_root(int n) // returns the digital root of n
{
    while (n > 9) // while n is greater than 9
    {
        n = sum_of_digits(n); // set n to the sum of the digits of n
    }

    return n; // return n
}