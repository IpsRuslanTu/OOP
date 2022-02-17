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
        cout << "Usage: FindText.exe <file name> '<text to search>'\n";
        return nullopt;
    }
    Args args;
    args.inputFileName = argv[1];
    args.textToSearch = argv[2];
    return args;
}

void FindText(ifstream& input, string stringForSearch, vector<int>& lineWithMatch)
{
    // Выполняет поиск строки в файле
    string lineFromFile;
    int counter = 0;
    while (getline(input, lineFromFile))
    {
        ++counter;
        auto pos = lineFromFile.find(stringForSearch);
        if (pos != string::npos)
        {
            lineWithMatch.push_back(counter);
        }
    }
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

    // Массив для хранения номеров строк, где найдена заданная строка
    vector<int> lineWithMatch;

    FindText(input, args->textToSearch, lineWithMatch);

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
 
    cout << "Text not found\n";
    return 1;
}