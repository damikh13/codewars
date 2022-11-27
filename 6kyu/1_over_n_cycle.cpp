int cycle(int n) // returns the length of the cycle of 1/n fraction
{
    if (!(n % 2) || !(n % 5)) return -1; // if n is divisible by 2 or 5, there's no cycle, return -1

    int length = 0;
    int value = 1;
    while (true) // while true
    {
        value = (value % n) * 10; // get the remainder of value divided by n and multiply it by 10
        length++; // increment length
        if (value == 1) // if value is 1
        {
            return length; // return length
        }
    }
}