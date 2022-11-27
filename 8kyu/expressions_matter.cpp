#include <algorithm>

unsigned short int expression_matter(unsigned short int a, unsigned short int b, unsigned short int c) // returns the maximum value of the expression that it's possible to get from a, b, and c using the operators +, *, and ()
{
    return std::max({a + b + c, a * b * c, (a + b) * c, a * (b + c)});
}