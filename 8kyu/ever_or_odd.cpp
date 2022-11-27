#include <string>

std::string even_or_odd(int number) // returns "Even" if number is even, "Odd" otherwise
{
    return number % 2 == 0 ? "Even" : "Odd";
}