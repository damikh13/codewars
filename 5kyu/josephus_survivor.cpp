#include <iostream>

int josephus_survivor(int n, int k) // returns the survivor of the Josephus problem with n people and k-th person being killed
{
    int curr_survivor = 0; // current survivor
    for (int i = 1; i <= n; ++i) // iterate through the people
    {
        curr_survivor = (curr_survivor + k) % i; // calculate the current survivor
    }

    return curr_survivor + 1; // return the current survivor's number
}