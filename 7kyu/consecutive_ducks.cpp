#include <cmath>
using namespace std; 

bool consecutiveDucks(unsigned int num) // returns true if num is a power of 2, false otherwise
{
    return (num & (num - 1)) != 0; // if num is a power of 2, num - 1 will be a number with all the bits of num set to 1, except for the least significant bit, which will be 0. If num is not a power of 2, num & (num - 1) will be 0
}