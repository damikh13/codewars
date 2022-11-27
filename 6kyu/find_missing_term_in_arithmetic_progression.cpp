#include <vector>
#include <cmath>

static long findMissing(std::vector<long> list) // returns the missing term in the arithmetic progression
{
    size_t list_size = list.size(); // size of list
    int difference = (list[2] - list[1]) / 2; // the difference between the terms in the arithmetic progression
    for (size_t i = 1; i < list_size; ++i) // for all i from 1 to list.size() - 1
    {
        if (list[i] - list[i - 1] != difference) // if the difference between the terms at i and i - 1 is not equal to the difference between the terms in the arithmetic progression
        {
            return list[i] - difference; // return the missing term
        }
    }
    
    return 0; // if no such term exists, return 0
}