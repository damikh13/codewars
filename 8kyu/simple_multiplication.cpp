int simple_multiplication(int number) // returns the result of multiplying the number given by 8 if the number given is even, or by 9 if the number given is odd
{
    return number * (number % 2 == 0 ? 8 : 9);
}