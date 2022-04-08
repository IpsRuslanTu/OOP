﻿#include "FunctionsForMap.h"
#include <algorithm>
#include <sstream>

void PrintMap(std::map <std::string, unsigned int> countWords)
{
    std::map <std::string, unsigned int>::iterator it;
    for (it = countWords.begin(); it != countWords.end(); it++)
    {
        std::cout << it->first << " -> " << it->second << std::endl;
    }
}

//1. кажется тут копирование лишним
std::map <std::string, unsigned int> AddWordToMap(std::map <std::string, unsigned int> mapWords, 
    std::string word)
{
    std::map <std::string, unsigned int> tempMapWords = mapWords;
    std::map <std::string, unsigned int>::iterator it;

    it = tempMapWords.find(word);

    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    it = tempMapWords.find(word);
    if (it == tempMapWords.end()) {
        tempMapWords.insert(make_pair(word, 1));
    }
    else
    {
        it->second++;
    }
    return tempMapWords;
}

//2. подумай над названиями, функции не делают то как названы
std::map <std::string, unsigned int> AddAndCountWordsToMap(const std::map <std::string, 
    unsigned int> countWords, std::string str)
{
    std::map <std::string, unsigned int> newWords = countWords;
    std::map <std::string, unsigned int>::iterator it;
    std::stringstream ss;
    ss.str(str);

    std::string word;
    while (ss >> word)
    {
        newWords = AddWordToMap(newWords, word);
    }
    return newWords;
}