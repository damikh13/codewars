#include <vector>

int max_subarray_sum(const std::vector<int>& arr) // returns the maximum sum of a subarray
{
    size_t array_size = arr.size(); // size of the array
    int max_sum = 0; // maximum sum of a subarray
    int curr_sum = 0; // current sum of a subarray
    for (int i = 0; i < array_size; ++i) // iterate through the array
    {
        curr_sum += arr[i]; // add the current element to the current sum
        if (curr_sum < 0) // if the current sum is less than 0, then there's no point in continuing the current subarray
        {
            curr_sum = 0; // reset the current sum
        }
        else if (curr_sum > max_sum) // if the current sum is greater than the maximum sum
        {
            max_sum = curr_sum; // update the maximum sum
        }
    }

    return max_sum; // return the maximum sum
}