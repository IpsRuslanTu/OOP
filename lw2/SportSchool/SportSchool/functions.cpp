#include "functions.h"
#include <fstream>
#include <string>

std::set<std::string> GetSetFromFile(std::string inputFile)
{
    std::set<std::string> tempSet;
    std::string item;
    std::ifstream input(inputFile);
    if (input.is_open())
    {
        while (std::getline(input, item))
        {
            tempSet.insert(item);
        }
    }
    else
    {
        //избавляемся
        std::cout << "Warning. File " << inputFile << " unable to open. Check the input data." << std::endl;
        std::cout << "Your list would be not complete." << std::endl;
    }
    return tempSet;
}