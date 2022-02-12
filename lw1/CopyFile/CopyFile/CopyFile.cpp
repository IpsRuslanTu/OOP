#include <iostream>
#include <fstream>
#include <optional>
#include <string>

using namespace std;

struct Args
{
    string inputFileName;
    string outputFileName;
};

optional<Args> ParseArgs(int argc, char* argv[])
{
    if (argc != 3)
    {
        return nullopt;
    }
    Args args;
    args.inputFileName = argv[1];
    args.outputFileName = argv[2];
    return args;
}

int main(int argc, char *argv[])
{
    auto args = ParseArgs(argc, argv);
    // Проверка правильности аргументов командной строки
    if (!args)
    {
        cout << "Invalid arguments count\n";
        cout << "Usage: CopyFile.exe <input file name> <output file name>\n";
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

    // Открываем выходной файл
    ofstream output;
    output.open(args->outputFileName);
    if (!output.is_open())
    {
        cout << "Failed to open '" << args->outputFileName << "' for writing\n";
        return 1;
    }

    // Копируем содержиое входного файла в выходной
    char ch;
    while (input.get(ch))
    {
        if (!output.put(ch))
        {
            break;
        }
    }

    if (input.bad())
    {
        cout << "Filed to read data to input file\n";
        return 1;
    }

    if (!output.flush())
    {
        cout << "Filed to write data to output file\n";
        return 1;
    }

    return 0;
}