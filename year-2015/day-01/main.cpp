#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
    char ch;
    int floor = 0;
    int position = 0;
    int firstPositionAtBasement = 0;
    bool haveFoundTheBasement = false;
    fstream fin("my-input.txt", fstream::in);
    while (fin >> noskipws >> ch)
    {
        position++;

        switch (ch)
        {
        case '(':
            floor++;
            break;
        case ')':
            floor--;
            break;
        default:
            cout << "Unexpected input, terminating execution";
            return 1;
        }

        bool firstTimeAtBasement = !haveFoundTheBasement && floor == -1;
        if (firstTimeAtBasement)
        {
            firstPositionAtBasement = position;
            haveFoundTheBasement = true;
        }
    }

    cout << "Answer Part One = " << floor << endl;
    cout << "Answer Part Two = " << firstPositionAtBasement;
    
    return 0;
}
