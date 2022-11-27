#include <cmath>

int twice_as_old(int dad_years_old, int son_years_old) // returns the difference in years between the father and the son
{
    return abs(dad_years_old - son_years_old * 2);
}