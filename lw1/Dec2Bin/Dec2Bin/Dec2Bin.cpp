#include <iostream>
#include <optional>
#include <string>

using namespace std;

bool isNumber(string temp)
{
	for (int i = 0; i < temp.size(); ++i)
		if (!isdigit(temp[i]))
		{
			cout << "Error. Check the 2nd parameter. It should be a number.\n";
			return false;
		}

	return true;
}

optional<int> checkArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n";
		cout << "Usage: dec2bin.exe <number from 0 to (2^31)>\n";
		return nullopt;
	}

	if (!isNumber(argv[1]))
		return nullopt;

	try
	{
		int numFromArg = stoi(argv[1]);
		if (numFromArg >= 0)
			return numFromArg;
		else
			cout << "Error. Input unsigned number\n";
	}
	catch (out_of_range err)
	{
		cout << "Error. Enter a number in the range from 0 to (2^31)\n";
	}

	return nullopt;
}

void PrintNumInBinary(int num)
{
	bool printBit = false;

	for (int i = 31; i >= 0; --i)
	{
		if (printBit)
		{
			cout << ((num >> i) & 1);
		}
		if (printBit == false && (num >> i & 1))
		{
			printBit = true;
			cout << 1;
		}
	}

	if (printBit == false)
		cout << 0;
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