#include <vector>

int find_even_index(const std::vector<int> numbers) // returns the index of the element in numbers such that the sum of the elements to the left of it is equal to the sum of the elements to the right of it
{
    for (size_t i = 0; i < numbers.size(); ++i) // for all i from 0 to numbers.size() - 1 get the left and rights sums, then compare them
    {
        int sum_of_left = 0; // sum of the elements to the left of i
        int sum_of_right = 0; // sum of the elements to the right of i
        for (size_t j = 0; j < i; ++j) // for all j from 0 to i - 1
        {
            sum_of_left += numbers[j]; // add numbers[j] to the sum of the elements to the left of i
        }
        for (size_t j = i + 1; j < numbers.size(); ++j) // for all j from i + 1 to numbers.size() - 1
        {
            sum_of_right += numbers[j]; // add numbers[j] to the sum of the elements to the right of i
        }
        if (sum_of_left == sum_of_right) // if the sum of the elements to the left of i is equal to the sum of the elements to the right of i
        {
            return i; // return i
        }
    }
    
    return -1; // if no such index exists, return -1
}