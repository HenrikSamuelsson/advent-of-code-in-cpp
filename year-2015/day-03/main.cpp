#include <iostream>
#include <fstream>

int main(void)
{
    char dir;    // Tracks the directions instructions provided by the elf

    int x = 0;    // Tracks santa's x coordinate as he moves between houses
    int y = 0;    // Tracks santa's y coordinate as he moves between houses

    std::fstream fin("my-input-year-2015-day-03.txt", std::fstream::in);
    while (fin >> dir) {
        switch (dir)
        {
        case '^':
            y++;
            break;
        case 'v':
            y--;
            break;
             case '>':
            x++;
            break;
        case '<':
            x--;
            break;
        default:
            std::cout << "Unexpected input, terminating execution";
            return 1;
        }
    }

    std::cout << "Answer Part One = " << x << std::endl;
    std::cout << "Answer Part Two = " << y << std::endl;

    return 0;
}
