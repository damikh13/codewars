#include <string>

std::string uint32_to_ip(uint32_t ip) // returns the IPv4 address as a string
{
    int num_1 = 0;
    int num_2 = 0;
    int num_3 = 0;
    int num_4 = 0;

    // getting first octet
    for (int i = 0; i < 8; ++i)
    {
        num_1 += ip & (1 << i);
    }
    ip >>= 8;

    // getting second octet
    for (int i = 0; i < 8; ++i)
    {
        num_2 += ip & (1 << i);
    }
    ip >>= 8;

    // getting third octet
    for (int i = 0; i < 8; ++i)
    {
        num_3 += ip & (1 << i);
    }
    ip >>= 8;

    // getting fourth octet
    for (int i = 0; i < 8; ++i)
    {
        num_4 += ip & (1 << i);
    }

    return std::to_string(num_4) + "." + std::to_string(num_3) + "." + std::to_string(num_2) + "." + std::to_string(num_1);
}