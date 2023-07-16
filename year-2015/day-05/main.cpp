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

    if (std::regex_search("bottle" ,std::regex("(.)\\1"))) {
      std::cout << "string:literal => matched\n";
    }
    else {
        std::cout << "string:literal did not match" << std::endl;
    }

    if (std::regex_search("bocdttle", std::regex("(ab)|(cd)|(pq)|(xy)")) ) {
        std::cout << "string contains forbidden part" << std::endl;
    }
    else {
        std::cout << "string is OK" << std::endl;
    }
}
