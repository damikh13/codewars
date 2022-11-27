#include <string>
#include <map>

std::string DNAStrand(const std::string& dna) // returns the complementary DNA strand
{
    std::map<char, char> complementary_dna{ // map of complementary DNA
        {'A', 'T'},
        {'T', 'A'},
        {'C', 'G'},
        {'G', 'C'}
    }; 

    std::string complementary_dna_strand; // complementary DNA strand
    for (char c : dna) // for all c in dna
    {
        complementary_dna_strand += complementary_dna[c]; // add the complementary DNA of c to complementary_dna_strand
    }
    return complementary_dna_strand; // return complementary_dna_strand
}