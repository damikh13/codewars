#include <string>
using namespace std; 

int factorial(int x) // returns x!
{
    int result = 1; // the result of x!
    for (int i = 1; i <= x; ++i) // iterate from 1 to x
    {
        result *= i; // multiply result by i
    }
    return result; // return result
}

string strong_num(int number) // returns "STRONG!!!!" if number is a strong number, "Not Strong !!"" otherwise
{
    int sum = 0; // the sum of the factorials of the digits of number
    int saved_number = number; // a copy of number
    while (number > 0) // while number is greater than 0
    {
        sum += factorial(number % 10); // add the factorial of the last digit of number to sum
        number /= 10; // divide number by 10
    }
    return saved_number == sum ? "STRONG!!!!" : "Not Strong !!"; // return "STRONG!!!!" if saved_number is equal to sum, "Not Strong !!" otherwise
}