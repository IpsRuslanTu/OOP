#include "functions.h"

std::optional<Args> ParseArgs(int argc, char* argv[])
{
    if (argc != 5)
    {
        std::cout << "Invalid arguments count\n";
        std::cout << "Usage: crypt.exe <crypt or decrypt> <input file> <output file> <key> \n";
        return std::nullopt;
    }
    Args args;

    args.command = argv[1];
    args.fileIn = argv[2];
    args.fileOut = argv[3];
    args.key = std::stoi(argv[4]);

    return args;
}