#include <vector>
#include <string>
#include <unordered_map>

bool is_a_number(std::string str) // checks if str is a number
{
    if (str[0] == '-') // if str is negative
    {
        str.erase(0, 1); // erase the minus sign
    }

    for (char& c : str) // iterate through str
    {
        if (!isdigit(c)) // if c is not a digit
        {
            return false; // return false
        }
    }

    return true; // return true
}

static int& getReg(std::unordered_map<std::string, int>& regs, std::string name) // returns the value of the register with the given name
{
    if (is_a_number(name)) // if name is a number
    {
        int* num = new int(std::stoi(name)); // create a new int with the value of name
        return *num; // return the value of num
    }
    else // if name is not a number
    {
        return regs[name]; // return the value of the register with the given name
    }
}

std::unordered_map<std::string, int> assembler(const std::vector<std::string>& program) // returns the registers after executing the given program
{
    std::unordered_map<std::string, int> regs; // registers
    int curr_instruction_idx = 0; // current line

    while (curr_instruction_idx < program.size()) // while curr_instruction_idx is less than the size of program
    {
        std::string curr_instruction = program[curr_instruction_idx]; // current instruction
        std::string curr_instruction_name = curr_instruction.substr(0, curr_instruction.find(' ')); // current instruction's name
        std::string curr_instruction_args = curr_instruction.substr(curr_instruction.find(' ') + 1); // current instruction's arguments
        std::string curr_instruction_arg1 = curr_instruction_args.substr(0, curr_instruction_args.find(' ')); // current instruction's first argument
        std::string curr_instruction_arg2 = curr_instruction_args.substr(curr_instruction_args.find(' ') + 1); // current instruction's second argument

        if (curr_instruction_name == "mov") // if current instruction is mov
        {
            getReg(regs, curr_instruction_arg1) = getReg(regs, curr_instruction_arg2); // move the value of the second argument to the first argument
        }
        else if (curr_instruction_name == "inc") // if current instruction is inc
        {
            getReg(regs, curr_instruction_arg1)++; // increment the value of the first argument
        }
        else if (curr_instruction_name == "dec") // if current instruction is dec
        {
            getReg(regs, curr_instruction_arg1)--; // decrement the value of the first argument
        }
        else if (curr_instruction_name == "jnz") // if current instruction is jnz
        {
            if (getReg(regs, curr_instruction_arg1) != 0) // if the value of the first argument is not 0
            {
                curr_instruction_idx += std::stoi(curr_instruction_arg2) - 1; // jump to the line with the number of the current line plus the value of the second argument minus 1
            }
        }

        ++curr_instruction_idx; // increment curr_instruction_idx
    }

    return regs; // return the registers
}