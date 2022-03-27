#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

std::string GetStringFromUser();

std::vector<float> GetFloatVectorFromString(std::string str);

float MultiplyMaxAndMinElementsOfVector(const std::vector<float> inputVector);

std::vector<float> MultiplyNegativeValuesInVector(const std::vector<float> inputVector, const float operand);