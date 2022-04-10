#include <iostream>
#include <fstream>
#include "functions.h"

// Проверить все аргументы args command и key от 0 до 255

using namespace std;

int main(int argc, char* argv[])
{
    auto args = ParseArgs(argc, argv);

    if (!args)
    {
        return 1;
    }

    ifstream input;
    input.open(args->fileIn);
    if (!input.is_open())
    {
        cout << "Failed to open '" << args->fileIn << "' for reading\n";
        return 1;
    }

    ofstream output;
    output.open(args->fileOut);
    if (!output.is_open())
    {
        cout << "Failed to open '" << args->fileOut << "' for writing\n";
        return 1;
    }

    char byte;
    while (input.get(byte))
    {
        cout << byte << " ";
    }
}