#include "WorkWithVector.h"

std::string GetStringFromUser()
{
    std::cout << "Enter a float type number separated by a space:\n";
    std::string str;
    std::getline(std::cin, str);
    return str;
}

std::vector<float> GetFloatVectorFromString(std::string str) {
	std::stringstream ss;
	ss.str(str);

	std::vector<float> vectorOfFloat;
	float num;

	// 1.нужно показать ошибку
	while (ss >> num) {
		vectorOfFloat.push_back(num);
	}
	return vectorOfFloat;
}

float MultiplyMaxAndMinElementsOfVector(const std::vector<float> inputVector) {
	float maxElement = *max_element(inputVector.begin(), inputVector.end());
	float minElement = *min_element(inputVector.begin(), inputVector.end());
	//с мальнькой
	float MultiMaxAndMin = maxElement * minElement;

    return MultiMaxAndMin;
}

//2.можно сделать более уневирсально, если передавать функцию
std::vector<float> MultiplyNegativeValuesInVector(const std::vector<float> inputVector, const float operand) {
	std::vector<float> newVector(inputVector.size());
	for (int i = 0; i < inputVector.size(); ++i)
    {
		newVector[i] = (inputVector[i] < 0) ? (inputVector[i] * operand) : (inputVector[i]);
    }
	return newVector;
}