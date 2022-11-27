#include <cmath>

unsigned int countBits(unsigned long long n) // returns the number of bits set to 1 in n
{
    int sz = log2(n) + 1; // get number of bits
    int cnt = 0; // counter

    for (int i = 0; i < sz; ++i) // iterate from 0 to sz
    {
        cnt += (n & 1); // check if last bit is 1
        n = n >> 1; // shift n to the right
    }

    return cnt;
}