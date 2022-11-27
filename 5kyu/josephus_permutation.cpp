#include <vector>

std::vector<int> josephus_permutation(std::vector<int> items, int k) // returns the josephus' permutation of the items
{
    std::vector<int> result = {}; // the result vector
    int curr_index = 0; // the current index

    while (items.size() > 0) // while there are still items in the vector
    {
        curr_index = (curr_index + k - 1) % items.size(); // getting the index of the item to be removed
        result.push_back(items[curr_index]); // adding the item to the result vector
        items.erase(items.begin() + curr_index); // removing the item from the items vector
    }

    return result; // returning the result vector
}