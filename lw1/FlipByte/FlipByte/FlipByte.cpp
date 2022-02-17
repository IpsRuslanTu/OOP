#include <iostream>
#include <string>
#include <optional>
#include <bitset>

using namespace std;

optional<int> checkArgs(int argc, char* argv[])
{
    if (argc != 2)
    {
        cout << "Invalid arguments count\n";
        cout << "Usage: flipbyte.exe <number from 0 to 255>\n";
        return nullopt;
    }    

    string buf = argv[1];
    for (int i = 0; i < buf.size(); ++i)
        if (!isdigit(buf[i]))
        {
            cout << "Error. The number contains invalid characters.\n";
            return nullopt;
        }

    int numFromArg = stoi(buf);
    cout << numFromArg << endl;
    if (numFromArg >= 0 && numFromArg <= 255)
    {
        return numFromArg;
    }
    else
    {
        cout << "Incorrect input. Use number from 0 to 255, as parameter\n";
        return nullopt;
    }
}

int main(int argc, char* argv[])
{
    auto inputNum = checkArgs(argc, argv);
    // Проверка правильности аргументов командной строки, получение числа
    if (!inputNum)
    {
        return 1;
    }

    bitset<8> inputNum2x = *inputNum;
    string backwardNum2x = inputNum2x.to_string();
    reverse(backwardNum2x.begin(), backwardNum2x.end());
    bitset<8> bitsetObj(backwardNum2x);
   
    cout << *inputNum << " - your number\n";
    cout << inputNum2x << " - in binary system\n";
    cout << backwardNum2x << " - in binary system, opposite \n";
    cout << bitsetObj.to_ulong() << " - your inverted number \n";
}