/*
    Name: theWordRift
    Author: Kaustubh Kanodia
    Difficulty: Easy
    Round: 1

    Test Case Description:
    The input consists of 2 strings.
    Constraints:
    - Both strings have up to 10 characters.
    - Characters are always lowercase alphabets from 'a' to 'j'.
*/

/*
    Logic:
    - The first number uses the mapping: 'a' = 0, 'b' = 1, ..., 'j' = 9.
    - The second number uses the reverse mapping: 'a' = 9, 'b' = 8, ..., 'j' = 0.
    - Now both numbers are added and the result is converted according to the first mapping.
    Sample Input:
    abba
    bb
    Sample Output:
    bji
*/

/*
    Edge Cases:
    Input1: a
            a
    Output1: a
    Input2: abcbcaabc
            cdefghija
    Output2: hhhffcbcb
    Input3: acegibdfhj
            aabbccddee
    Output3: bgefgffgec
    Input4: abba
            bb
    Output4: bji
    Input5: abcdefghij
            jihgfedcba
    Output5: cegjbdfhi
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Map the first alien numeral system to decimal
int alien1ToDecimal(char alienDigit)
{
    return alienDigit - 'a';
}

// Map the second alien numeral system to decimal (reverse mapping)
int alien2ToDecimal(char alienDigit)
{
    return 'j' - alienDigit;
}

// Convert a decimal digit to the first alien numeral system
char decimalToAlien1(int decimalDigit)
{
    return 'a' + decimalDigit;
}

// Convert an alien number from the first system to decimal
int alien1ToDecimalNumber(const string &alienNumber)
{
    int decimalValue = 0;
    int base = 10;

    for (char digit : alienNumber)
    {
        decimalValue = decimalValue * base + alien1ToDecimal(digit);
    }

    return decimalValue;
}

// Convert an alien number from the second system to decimal
int alien2ToDecimalNumber(const string &alienNumber)
{
    int decimalValue = 0;
    int base = 10;

    for (char digit : alienNumber)
    {
        decimalValue = decimalValue * base + alien2ToDecimal(digit);
    }

    return decimalValue;
}

// Convert a decimal number to the first alien numeral system
string decimalToAlien1Number(int decimalNumber)
{
    if (decimalNumber == 0)
        return "a";

    string alienNumber = "";
    int base = 10;

    while (decimalNumber > 0)
    {
        alienNumber += decimalToAlien1(decimalNumber % base);
        decimalNumber /= base;
    }

    reverse(alienNumber.begin(), alienNumber.end());
    return alienNumber;
}

int main()
{

    string alienNum1, alienNum2;

    cin >> alienNum1 >> alienNum2;

    // Validate inputs
    if (alienNum1.empty() || alienNum2.empty() ||
        alienNum1.size() > 10 || alienNum2.size() > 10)
    {
        cout << "Invalid Input. You need not handle such cases in your code." << endl;
        return 1;
    }

    for (char c : alienNum1 + alienNum2)
    {
        if (c < 'a' || c > 'j')
        {
            cout << "Invalid Input. You need not handle such cases in your code." << endl;
            return 1;
        }
    }

    // Convert alien numbers to decimal
    int decimal1 = alien1ToDecimalNumber(alienNum1);
    int decimal2 = alien2ToDecimalNumber(alienNum2);

    // Perform the sum
    int sum = decimal1 + decimal2;

    // Convert the result back to the first alien numeral system
    string result = decimalToAlien1Number(sum);

    cout << result << endl;

    return 0;
}
