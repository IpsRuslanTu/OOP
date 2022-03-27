#include <fstream>
#include <iomanip>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>

using namespace std;

const int SIZE_MATRIX = 3;
const int MAX_INDEX_MATRIX = 2;

typedef float Matrix3x3[SIZE_MATRIX][SIZE_MATRIX];

struct Args
{
	string inputFile1;
	string inputFile2;
};

struct WrapperMatrix
{
	Matrix3x3 innerMatrix;
};

optional<Args> ParseArgs(int argc, char* argv[]);

optional<ifstream> OpenFile(string fileIn);

optional<WrapperMatrix> CreateMatrixFromFile(ifstream& input);

WrapperMatrix MultMatrix(float matrix1[][SIZE_MATRIX], float matrix2[][SIZE_MATRIX]);

void PrintMatrix(Matrix3x3 inputMatrix);

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
		return 1;

	auto input1 = OpenFile(args->inputFile1);
	if (!input1)
		return 1;

	auto input2 = OpenFile(args->inputFile2);
	if (!input2)
		return 1;

	auto newMatrix1 = CreateMatrixFromFile(*input1);
	if (!newMatrix1)
	{
		cout << "Wrong matrix in file " << args->inputFile1 << "\n";
		return 1;
	}
	auto newMatrix2 = CreateMatrixFromFile(*input2);
	if (!newMatrix2)
	{
		cout << "Wrong matrix in file " << args->inputFile2 << "\n";
		return 1;
	}

	WrapperMatrix resultMatrix = MultMatrix(newMatrix1->innerMatrix, newMatrix2->innerMatrix);

	PrintMatrix(resultMatrix.innerMatrix);

	return 0;
}

optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n";
		cout << "Usage: MultiMatrix.exe <input file with matrix> <input file with matrix>\n";
		return nullopt;
	}
	Args args;
	args.inputFile1 = argv[1];
	args.inputFile2 = argv[2];
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

//2. Подумай над более подходящим названием
optional<WrapperMatrix> CreateMatrixFromFile(ifstream& input)
{
	WrapperMatrix matrixFromFile;

	float num;
	string buf;

	int i = 0;
	int j = 0;
	while (!input.eof())
	{
		if (i > MAX_INDEX_MATRIX)
			return nullopt;

		getline(input, buf);
		stringstream str;
		str.str(buf);

		j = 0;
		while (str >> num)
		{
			if (j > MAX_INDEX_MATRIX)
			{
				return nullopt;
			}

			matrixFromFile.innerMatrix[i][j] = num;
			++j;
		}
		++i;
	}

	if (i != SIZE_MATRIX && j != SIZE_MATRIX)
		return nullopt;

	return matrixFromFile;
}

//1. Можно изменить на typdef
WrapperMatrix MultMatrix(float matrix1[][SIZE_MATRIX], float matrix2[][SIZE_MATRIX])
{
	WrapperMatrix finalMatrix = { 0 };
	float temp = 0;

	for (int i = 0; i < SIZE_MATRIX; ++i)
	{
		for (int j = 0; j < SIZE_MATRIX; ++j)
		{
			for (int k = 0; k < SIZE_MATRIX; ++k)
			{
				temp = matrix1[i][k] * matrix2[k][j];
				finalMatrix.innerMatrix[i][j] += temp;
			}
		}
	}
	return finalMatrix;
}

void PrintMatrix(Matrix3x3 inputMatrix)
{
	for (int i = 0; i < SIZE_MATRIX; ++i)
	{
		for (int j = 0; j < SIZE_MATRIX; ++j)
			cout << fixed << setprecision(3) << inputMatrix[i][j] << " ";
		cout << "\n";
	}
}