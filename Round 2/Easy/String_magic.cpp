/*
    Name: String_magic

    Author: Navdha Sharma

    Difficulty: Easy

    Round:

    Test Case Description: Single line string input,without any space.

    Constraints:The string should only contain[a to z]and[A to Z].

/*

    Logic:In this problem,assuming strings position starts at 0 the code will follow the conditions given below:
    1 if the alphabet is at even position and small it will print the alphabet as it is.
    2 if the alphabet is at even position and capital it will print the next alphabet.
    3 if the alphabet is at odd position and small it will prints its ASCII value.
    4 if the alphabet is at odd position and capital it will print ASCII of next alphabet.
    5 if the alphabet lies at position which is a perfect square and is small ,it will make the alphabet capital.
    6 if the alphabet lies at position which is a perfect square and is capital ,it will make the alphabet small.

    Sample Input:HelloWorld
    Sample Output:hEl108O88o114lD

*/

/*
    Edge Cases:

    Input1:Z
    Output1:Z

    Input2:aZbcDg
    Output2:Azb99d103

    Input3:afowkJDREBCJSKMndkdoNKFOVNkfkivnfkz
    Output3:AFo119K75E83FbD75T76N110D107d111O76G80Wnk102k105v110f107z

    Input4:AaZz
    Output4:aAA122

    Input5:aaaaAAAAzzzzzZZZZZ
    Output5:AAa97a66B66zZz122z91A91z91

*/

#include <iostream>
#include <cmath>
#include <string>
#include <cctype>
using namespace std;

bool isPerfectSquare(int n)
{
    int sqrtN = sqrt(n);
    return sqrtN * sqrtN == n;
}

bool isValidString(const string &inputString)
{
    for (char c : inputString)
    {
        if (!isalpha(c))
        {
            return false;
        }
    }
    return true;
}

string processString(const string &inputString)
{
    string result;

    for (size_t i = 0; i < inputString.length(); i++)
    {
        char charAtPos = inputString[i];

        if (isPerfectSquare(i))
        {
            if (islower(charAtPos))
            {
                result += toupper(charAtPos);
            }
            else
            {
                result += tolower(charAtPos);
            }
        }
        else if (i % 2 == 0)
        {
            if (islower(charAtPos))
            {
                result += charAtPos;
            }
            else
            {
                result += (char)((charAtPos - 'A' + 1) % 26 + 'A');
            }
        }
        else
        {
            if (islower(charAtPos))
            {
                result += to_string((int)charAtPos);
            }
            else
            {
                result += to_string((int)charAtPos + 1);
            }
        }
    }

    return result;
}

int main()
{

    string inputString;
    cin >> inputString;

    if (!isValidString(inputString))
    {
        cerr << "Error:Not a valid input.You need not handle such cases." << endl;
    }
    else
    {
        cout << processString(inputString) << endl;
    }

    return 0;
}
