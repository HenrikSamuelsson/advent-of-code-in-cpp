#include <iostream>
#include<string>
#include "md5.h"
 
using std::cout; using std::endl;
 
int main(int argc, char *argv[])
{
    std::string input;
    cout << "Enter your puzzle input: ";
    std::getline(std::cin, input);
    cout << "puzzleInput = " << input << endl;

    unsigned numberPostfix = 0;
    std::string hash;
    bool match = false;
    do {
        numberPostfix++;

        std::string inputWithPostfix;
        inputWithPostfix = input + std::to_string(numberPostfix);
        //cout << "input with postfix" << inputWithPostfix << endl;
        
        hash = md5(inputWithPostfix);
        //cout << "md5 hash = " << hash << endl;
        if(numberPostfix == 609043) {
            cout << hash << endl;
            cout << hash[0] << endl;
            cout << hash[1] << endl;
            cout << (hash[2] & 0xf0) << endl;
        }

        std::string prefix = "000000";
 
    if (hash.rfind(prefix, 0) == 0) {
        match = true;
        std::cout << "String starts with the given prefix" << std::endl;
    } 

    } while (!match);//(hash[0] == 0 && hash[1] == 0 && ((char)(hash[2] & 0xf0)) == '0'));  
    //((hash[0] != 0) && (hash[1] != 0) && ((hash[2] & 0xf0) != '0'));

    cout << numberPostfix << endl; 
    return 0;
}
