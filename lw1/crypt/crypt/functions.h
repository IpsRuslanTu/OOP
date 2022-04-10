#pragma once
#include <iostream>
#include <string>
#include <optional>

struct Args
{
    std::string command;
    std::string fileIn;
    std::string fileOut;
    int key;
};

std::optional<Args> ParseArgs(int argc, char* argv[]);