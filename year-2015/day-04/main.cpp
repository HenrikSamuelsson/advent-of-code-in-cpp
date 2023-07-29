#include <iostream>
#include <string>
#include "md5.h"

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    std::string input;
    cout << "Enter your puzzle input: ";
    std::getline(std::cin, input);

    unsigned numberPostfix = 0;
    unsigned answerPart1;
    unsigned answerPart2;

    std::string prefixPart1 = "00000";
    std::string prefixPart2 = "000000";

    std::string hash;
    bool matchPart1 = false;
    bool matchPart2 = false;
    
    do
    {
        numberPostfix++;

        std::string inputWithPostfix;
        inputWithPostfix = input + std::to_string(numberPostfix);

        hash = md5(inputWithPostfix);

        if (!matchPart1 && hash.rfind(prefixPart1, 0) == 0)
        {
            matchPart1 = true;
            answerPart1 = numberPostfix;
        }
        if (!matchPart2 && hash.rfind(prefixPart2, 0) == 0)
        {
            matchPart2 = true;
            answerPart2 = numberPostfix;
        }
    } while (!(matchPart1 && matchPart2));

    cout << "Answer part 1: " << answerPart1 << endl;
    cout << "Answer part 2: " << answerPart2 << endl;

    return 0;
}
