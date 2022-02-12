#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include <vector>

using namespace std;

struct Args
{
    string inputFileName;
    string textToSearch;
};


optional<Args> ParseArgs(int argc, char* argv[])
{
    if (argc != 3)
    {
        cout << "Invalid arguments count\n";
        cout << "Usage: FindText.exe <file name> <text to search>\n";
        return nullopt;
    }
    Args args;
    args.inputFileName = argv[1];
    args.textToSearch = argv[2];
    return args;
}


int main(int argc, char* argv[])
{
    auto args = ParseArgs(argc, argv);
    // Проверка правильности аргументов командной строки
    if (!args)
    {
        return 1;
    }

    // Открываем входной файл
    ifstream input;
    input.open(args->inputFileName);
    if (!input.is_open())
    {
        cout << "Failed to open '" << args->inputFileName << "' for reading\n";
        return 1;
    }

    // Выполняет поиск строки в файле
    string stringFromFile;
    int counter = 0;
    vector<int> lineWithMatch;
    while (getline(input, stringFromFile))
    {
        ++counter;
        auto pos = stringFromFile.find(args->textToSearch);
        if (pos != string::npos)
        {
            lineWithMatch.push_back(counter);
        }
    }

    if (input.bad())
    {
        cout << "Filed to read data to input file\n";
        return 1;
    }

    if (lineWithMatch.size() > 0)
    {
        cout << "Text '" << args->textToSearch << "', found in " << args->inputFileName << "\n";
        cout << "Numbers of lines, where text was found:\n";
        for (int i = 0; i < lineWithMatch.size(); ++i)
        {
            cout << lineWithMatch[i] << "\n";
        }
        return 0;
    }
    else 
    {
        cout << "Text not found\n";
        return 1;
    }
}