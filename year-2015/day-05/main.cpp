#include <iostream>
#include <iterator>
#include <string>
#include <regex>

int main()
{
    std::string const text("Harry Botter");

    std::regex const anyVowel("[aeiou]+");
    std::ptrdiff_t const match_count(std::distance(
        std::sregex_iterator(text.begin(), text.end(), anyVowel),
        std::sregex_iterator()));
    std::cout << match_count << std::endl;

    std::regex const doubleLetter("(.)\1");
    if (std::regex_search(text, doubleLetter)) {
        std::cout << "doubleLetter" << std::endl;
    }

    //if (std::regex_match ("bottle", std::regex("(.)\1") ))
    if (std::regex_search("botle" ,std::regex("(.)\\1"))) {
      std::cout << "string:literal => matched\n";
    }
    else {
        std::cout << "string:literal did not match" << std::endl;
    }
}
