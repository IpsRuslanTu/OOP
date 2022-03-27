#pragma once

#include <iostream>
#include <map>

void PrintMap(std::map <std::string, unsigned int> countWords);

std::map <std::string, unsigned int> AddWordToMap(const std::map <std::string, unsigned int> mapWords,
	std::string word);

std::map <std::string, unsigned int> AddAndCountWordsToMap(const std::map <std::string,
	unsigned int> countWords, std::string str);