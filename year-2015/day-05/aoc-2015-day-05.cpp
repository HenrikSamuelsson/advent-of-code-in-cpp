#include <fstream>
#include <iostream>
#include <iterator>
#include <regex>
#include <string>

bool stringIsNice(std::string s);

int main()
{
    std::ifstream infile("my-input.txt");
    std::string line;
    int numberOfNiceStrings = 0;

    while (std::getline(infile, line))
    {
        if (stringIsNice(line))
        {
            numberOfNiceStrings++;
        }
    }
    std::cout << "Solution part 1: " << numberOfNiceStrings;
}

bool stringIsNice(std::string s)
{
    if (std::regex_search(s, std::regex("(ab)|(cd)|(pq)|(xy)")))
    {
        return false;
    }

    std::regex const anyVowel("[aeiou]");
    std::ptrdiff_t const match_count(std::distance(
        std::sregex_iterator(s.begin(), s.end(), anyVowel),
        std::sregex_iterator()));
    if (match_count < 3)
    {
        //std::cout << s << " " << match_count << std::endl;
        return false;
    }

     if (!std::regex_search(s, std::regex("(.)\\1")))
        {
            return false;
        }
       
    return true;
}
