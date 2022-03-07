#include "Dec2Bin.h"
#include <iostream>
#include <optional>
#include <string>

using namespace std;

optional<int> checkArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n";
		cout << "Usage: dec2bin.exe <number from 0 to (2^32 - 1)>\n";
		return nullopt;
	}

	try
	{
		int numFromArg = stoi(argv[1]);
		if (numFromArg >= 0)
			return numFromArg;
		else
		{
			cout << "Error. Input unsigned number\n";
		}
	}
	catch (invalid_argument err)
	{
		cout << "Error. Your argument is not a number\n";
	}
	catch (out_of_range err)
	{
		cout << "Error. Enter a number in the range from 0 to (2^32 - 1)\n";
	}

	return nullopt;
}

void PrintNumInBinary(int num)
{
	bool printBit = false;

	for (int i = 31; i >= 0; --i)
	{
		if (printBit == false && (num >> i & 1))
		{
			printBit = true;
			cout << "1";
		}
		if (printBit)
		{
			cout << ((num >> i) & 1);
		}
	}
	cout << "\n";
}

int main(int argc, char* argv[])
{
	auto inputNum = checkArgs(argc, argv);
	// Проверка правильности аргументов командной строки, получение числа
	if (!inputNum)
	{
		return 1;
	}

	PrintNumInBinary(*inputNum);

	return 0;
}