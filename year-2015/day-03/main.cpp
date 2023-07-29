#include <iostream>
#include <fstream>
#include <map>

int main(void)
{
    char dir;  // Tracks the directions instructions provided by the elf
    int x = 0; // Tracks santa's x coordinate as he moves between houses
    int y = 0; // Tracks santa's y coordinate as he moves between houses
    std::map<std::pair<int, int>, int> houseMap; // Tracks visited houses

    houseMap.insert(std::make_pair(std::make_pair(0, 0), 1));

    std::fstream fin("my-input-year-2015-day-03.txt", std::fstream::in);
    while (fin >> dir)
    {
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
        itr = houseMap.find(std::make_pair(x, y));
        if (itr != houseMap.end())
        {
            itr->second++;
        }
        else
        {
            houseMap.insert(std::make_pair(std::make_pair(x, y), 1));
        }
    }

    std::cout << "Answer Part One = " << houseMap.size() << std::endl;

    char dir2;  // Tracks the directions instructions provided by the elf
    int xs = 0; // Tracks santa's x coordinate as he moves between houses
    int ys = 0; // Tracks santa's y coordinate as he moves between houses
    int xr = 0; // Tracks robot-santa's x coordinate as it moves between houses
    int yr = 0; // Tracks robot-santa's y coordinate as it moves between houses
    int m = 0;  // Tracks number of moves
    std::map<std::pair<int, int>, int> houseMap2; // Tracks visited houses

    houseMap2.insert(std::make_pair(std::make_pair(0, 0), 2));

    std::fstream fin2("my-input-year-2015-day-03.txt", std::fstream::in);
    while (fin2 >> dir2)
    {
        m++;
        if (m % 2 == 1)
        {
            switch (dir2)
            {
            case '^':
                ys++;
                break;
            case 'v':
                ys--;
                break;
            case '>':
                xs++;
                break;
            case '<':
                xs--;
                break;
            default:
                std::cout << "Unexpected input, terminating execution";
                return 1;
            }

            std::map<std::pair<int, int>, int>::iterator itr2;
            itr2 = houseMap2.find(std::make_pair(xs, ys));
            if (itr2 != houseMap2.end())
            {
                itr2->second++;
            }
            else
            {
                houseMap2.insert(std::make_pair(std::make_pair(xs, ys), 1));
            }
        }
        else
        {
             switch (dir2)
            {
            case '^':
                yr++;
                break;
            case 'v':
                yr--;
                break;
            case '>':
                xr++;
                break;
            case '<':
                xr--;
                break;
            default:
                std::cout << "Unexpected input, terminating execution";
                return 1;
            }

            std::map<std::pair<int, int>, int>::iterator itr2;
            itr2 = houseMap2.find(std::make_pair(xr, yr));
            if (itr2 != houseMap2.end())
            {
                itr2->second++;
            }
            else
            {
                houseMap2.insert(std::make_pair(std::make_pair(xr, yr), 1));
            }
        }
    }
    std::cout << "m = " << m << std::endl;
    std::cout << "Answer Part Two = " << houseMap2.size() << std::endl;

    return 0;
}
