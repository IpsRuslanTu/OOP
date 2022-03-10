#include <iostream>
#include <optional>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const int SIZE_MATRIX = 3;

typedef float Matrix3x3[SIZE_MATRIX][SIZE_MATRIX];

struct Args
{
	string inFile1;
	string inFile2;
};

struct WrapperMatrix
{
	Matrix3x3 innerMatrix;
};

optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n";
		cout << "Usage: CopyFile.exe <input file name> <output file name>\n";
		return nullopt;
	}
	Args args;
	args.inFile1 = argv[1];
	args.inFile2 = argv[2];
	return args;
}

optional<ifstream> OpenFile(string fileIn)
{
	ifstream input;
	input.open(fileIn);
	if (!input.is_open())
	{
		cout << "Failed to open '" << fileIn << "' for reading\n";
		return nullopt;
	}
	return input;
}

optional<WrapperMatrix> CreateMatrixFromFile(ifstream& input)
{
	WrapperMatrix matrix;

	float num;
	string buf;

	int i = 0;
	int j = 0;
	while (!input.eof())
	{
		if (i > 2) return nullopt;
		getline(input, buf);
		stringstream str;
		str.str(buf);

		j = 0;
		while (str >> num)
		{
			if (j > 2)
			{
				return nullopt;
			}
			matrix.innerMatrix[i][j] = num;
			++j;
		}
		++i;
	}

	return matrix;
}

void PrintMatrix(Matrix3x3 inputMatrix)
{
	for (int i = 0; i < SIZE_MATRIX; ++i)
	{
		for (int j = 0; j < SIZE_MATRIX; ++j)
			cout << inputMatrix[i][j] << " ";
		cout << "\n";
	}
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
		return 1;


	auto input1 = OpenFile(args->inFile1);
	if (!input1)
		return 1;

	auto input2 = OpenFile(args->inFile2);
	if (!input2)
		return 1;

	auto newMatrix1 = CreateMatrixFromFile(*input1);
	if (!newMatrix1)
	{
		cout << "Wrong matrix in file" << args->inFile1 << "\n";
		return 1;
	}
	auto newMatrix2 = CreateMatrixFromFile(*input2);
	if (!newMatrix2)
	{
		cout << "Wrong matrix in file" << args->inFile2 << "\n";
		return 1;
	}

	PrintMatrix(newMatrix1->innerMatrix);
	cout << endl;
	PrintMatrix(newMatrix2->innerMatrix);
		
	return 0;
}