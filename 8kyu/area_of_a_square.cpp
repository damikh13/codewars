#include <cmath>

double square_area(double A) // calculate the area of a square with the length of circular arc A
{
    return pow(A / (2 * M_PI), 2);
}