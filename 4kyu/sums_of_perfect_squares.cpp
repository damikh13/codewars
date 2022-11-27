#include <iostream>

int count_perfect_squares(int number)
{
    int count = 0;
    int max_root = 1;
    for (max_root; max_root * max_root <= number; ++max_root)
    {
    }
    --max_root;

    while (max_root > 0)
    {
        if (number >= max_root * max_root)
        {
            number -= max_root * max_root;
            ++count;
        }
        else
        {
            --max_root;
        }
    }

    return count;
}

int main()
{
    int number;
    std::cin >> number;
    std::cout << count_perfect_squares(number) << std::endl;
    return 0;
}