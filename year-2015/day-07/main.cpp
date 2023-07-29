#include <algorithm>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <istream>
#include <limits>
#include <map>
#include <sstream>
#include <vector>

using ushort = unsigned short;

int processFile(const char *filename, 
                const bool override_b = false,
                const int resultPart1 = 0)
{
    std::ifstream f(filename);
    std::string str, line;

    std::deque<std::string> lines;
    while (std::getline(f, line))
    {
        lines.push_back(line);
    }
    f.close();
    std::map<std::string, ushort> wires;

    if (override_b)
        wires["b"] = resultPart1;

    std::map<std::string, std::function<ushort(const ushort n1, const ushort n2)>>
        operations = {
            {"AND", [](auto n1, auto n2)
             { return n1 & n2; }},
            {"OR", [](auto n1, auto n2)
             { return n1 | n2; }},
            {"LSHIFT", [](auto n1, auto n2)
             { return n1 << n2; }},
            {"RSHIFT", [](auto n1, auto n2)
             { return n1 >> n2; }},
        };

    auto getValue = [&](const std::string &str, ushort &out) -> bool
    {
        if (str[0] >= 'a' && str[0] <= 'z')
        {
            if (wires.find(str) == wires.end())
            {
                return false;
            }
            out = wires[str];
            return true;
        }
        else
        {
            out = std::stoi(str);
            return true;
        }
    };

    std::string op;

    while (lines.size() > 0)
    {
        line = lines.front();
        lines.pop_front();
        std::istringstream iss(line);
        ushort a, b, result;
        iss >> str;

        if (str == "NOT")
        {
            iss >> str;
            if (!getValue(str, a))
            {
                lines.push_back(line);
                continue;
            }
            result = ~a;
        }
        else
        {
            if (!getValue(str, a))
            {
                lines.push_back(line);
                continue;
            }
            iss >> op;
            if (op != "->")
            {
                iss >> str;
                if (!getValue(str, b))
                {
                    lines.push_back(line);
                    continue;
                }
                result = operations[op](a, b);
            }
            else
            {
                iss >> str;
                if (!override_b || str != "b")
                    wires[str] = a;
                continue;
            }
        }
        iss >> str;
        iss >> str;
        if (!override_b || str != "b")
            wires[str] = result;
    }

    return wires["a"];
}

int main()
{
    int resultPart1 = processFile("my-input.txt");
    std::cout << "Result part 1 = " << resultPart1 << std::endl;

    int resultPart2 = processFile("my-input.txt", true, resultPart1);
    std::cout << "Result part 2 = " << resultPart2 << std::endl;
    
    return 0;
}
