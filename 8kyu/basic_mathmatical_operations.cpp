int basic_op(char op, int value1, int value2) // returns the result of the basic mathematical operation op with value1 and value2
{
    switch (op) // switch on op
    {
        case '+': // if op is '+'
            return value1 + value2; // return the sum of value1 and value2
        case '-': // if op is '-'
            return value1 - value2; // return the difference of value1 and value2
        case '*': // if op is '*'
            return value1 * value2; // return the product of value1 and value2
        case '/': // if op is '/'
            return value1 / value2; // return the quotient of value1 and value2
    }
}