#include <string>
#include <vector>

int last_digit(const std::string& str1, const std::string& str2) // returns the last digit of str1^str2
{
    if (str2 == "0") // if we are raising str1 to the power of 0
    {
        return 1; // last digit is 1
    }

    int last_digit_of_str1 = str1[str1.size() - 1] - '0'; // last digit of str1
    std::vector<int> possible_forms_of_last_digit = {last_digit_of_str1}; // possible forms of the last digit of str1^str2
    int curr_possible_form_of_last_digit = (last_digit_of_str1 * last_digit_of_str1) % 10; // current possible form of last digit of str1
    // find all possible forms of the last digit of str1^str2
    while (curr_possible_form_of_last_digit != last_digit_of_str1)
    {
        possible_forms_of_last_digit.push_back(curr_possible_form_of_last_digit);
        curr_possible_form_of_last_digit = (curr_possible_form_of_last_digit * last_digit_of_str1) % 10;
    }

    int number_of_multiplications; // how many times last digit of str1 will change its form
    if (str2.size() >= 2)
    {
        number_of_multiplications = std::stoi(str2.substr(str2.size() - 2, 2)); // last two digits of str2
    }
    else
    {
        number_of_multiplications = std::stoi(str2);
    }

    return possible_forms_of_last_digit[--number_of_multiplications % possible_forms_of_last_digit.size()]; // return the apt form of the last digit of str1^str2 accordingn to the number of multiplications
}