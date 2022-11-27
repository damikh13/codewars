#include <vector>

PeakData pick_peaks(const std::vector<int>& v) // returns the positions and values of the peaks in a vector
{
    PeakData result;

    size_t left_idx = 0;
    size_t v_size = v.size();

    // edge cases
    if (v_size < 3)
    {
        return result;
    }

    for (size_t curr_idx = 1; curr_idx < v_size - 1; ++curr_idx) // iterate through the vector
    {
        // curr_elem is a peak if it is greater than the previous and the next elements
        if (v[left_idx] < v[curr_idx] && v[curr_idx] > v[curr_idx + 1])
        {
            // if the current element is a single-element peak
            if (left_idx == curr_idx - 1)
            {
                result.pos.push_back(curr_idx); // add the position of the peak to the result
            }
            else // if the current element is a peak of a plateau
            {
                result.pos.push_back(left_idx + 1); // add the position of the peak to the result
            }
            result.peaks.push_back(v[curr_idx]); // add the value of the peak to the result
        }
    
        // possible plateau
        if (!(v[left_idx] < v[curr_idx] && v[curr_idx] == v[curr_idx + 1]))
        {
            left_idx = curr_idx; // update the left index
        }
    }

    return result;
}