#include <iostream>
#include <cmath>

long long how_many_dots_in_a_rotated_rectangle_with_sides(int a, int b)
{
    long long count = 0;

    long long dots_in_first_rectange = 0;
    long double half_of_first_rectangle_right_bisect = a / (2 * sqrt(2));
    long double half_of_first_rectangle_left_bisect = b / (2 * sqrt(2));
    dots_in_first_rectange += (floor(half_of_first_rectangle_right_bisect) * 2 + 1) * (floor(half_of_first_rectangle_left_bisect) * 2 + 1);

    count += dots_in_first_rectange;

    long long dots_in_second_rectange = 0;
    long long second_rectangle_right_bisect = (half_of_first_rectangle_right_bisect - floor(half_of_first_rectangle_right_bisect) > 0.5) ? ((floor(half_of_first_rectangle_right_bisect) + 1) * 2) : ((floor(half_of_first_rectangle_right_bisect)) * 2);
    long long second_rectangle_left_bisect = (half_of_first_rectangle_left_bisect - floor(half_of_first_rectangle_left_bisect) > 0.5) ? ((floor(half_of_first_rectangle_left_bisect) + 1) * 2) : ((floor(half_of_first_rectangle_left_bisect)) * 2);
    dots_in_second_rectange += second_rectangle_right_bisect * second_rectangle_left_bisect;

    count += dots_in_second_rectange;

    return count;
}