int persistence(int n) // returns the persistence of n
{
    int result = 0; // the result

    if (n < 10) // if n is less than 10
    {
        return result; // return the result = 0
    }

    while (n > 9) // while n is greater than 9
    {
        int temp = 1; // the temporary variable
        while (n) // while n is not 0
        {
            temp *= n % 10; // multiply temp by the last digit of n
            n /= 10; // divide n by 10
        }
        n = temp; // set n to temp
        ++result; // increment result
    }

    return result; // return result
}