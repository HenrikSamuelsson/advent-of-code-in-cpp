#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
    char x = 'x';   // Dummy variable only used to catch the input x symbols.

    int l = 0;
    int w = 0;
    int h = 0;

    int paper = 0;
    int ribbon = 0;

    fstream fin("my-input.txt", fstream::in);
    while (fin >> l >> x >> w >> x >> h) {
        
        // Swap numbers around with intention to sort from small to large.
        if (l > h) {
            std::swap(l, h);
        }
        if (l > w) {
            std::swap(l, w);
        }
        if (w > h) {
           std::swap(w, h);
        }

        paper += 2 * l * w + 2 * w * h + 2 * h * l + l * w;
        ribbon += 2 * l + 2 * w + w * l * h;
    }

    cout << "Answer Part One = " << paper << endl;
    cout << "Answer Part Two = " << ribbon << endl;

    return 0;
}
