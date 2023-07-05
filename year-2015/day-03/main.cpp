#include <iostream>
#include <fstream>
#include <map>

int main(void)
{
    char dir;     // Tracks the directions instructions provided by the elf
    int x = 0;    // Tracks santa's x coordinate as he moves between houses
    int y = 0;    // Tracks santa's y coordinate as he moves between houses
    std::pair <int, int> houseCoordinates (0, 0);
    std::map<std::pair<int, int>, int> houseMap;    // Tracks visited houses

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
    
    std::map<std::pair<int, int>, int>::iterator itr;
    itr = houseMap.find(std::make_pair(x,y));
    if (itr != houseMap.end())
    {
        itr->second++;
    }
    else
    {
        houseMap.insert(std::make_pair(std::make_pair(x, y), 1));
    }

    }

    std::cout << "Answer Part One = " << houseCoordinates.first << std::endl;
    std::cout << "Answer Part Two = " << houseCoordinates.second << std::endl;

    return 0;
}
