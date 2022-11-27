#include <iostream>

unsigned long long count_partions(unsigned int n)
{
    unsigned long long *p = new unsigned long long[n + 1]{}; // p[i] is the number of partitions of i
    p[0] = 1; // 0 can be partitioned in 1 way: 0
    
    for (unsigned int i = 1; i <= n; ++i) // i is the number of the partition
    {
        for (unsigned int j = i; j <= n; ++j) // j is the number of the summand
        {
            p[j] += p[j - i]; // p[j] is the number of partitions of j, p[j - i] is the number of partitions of j - i
        }
    }

    unsigned long long result = p[n]; // the number of partitions of n
    delete[] p; // free the memory
    return result; // return the number of partitions of n
}