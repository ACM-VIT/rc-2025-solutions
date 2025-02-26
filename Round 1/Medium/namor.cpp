/*
    Name: Namor

    Author: Harshit Narang

    Difficulty: Medium

    Round: [Round Info]

    Test Case Description:
    The program takes one integer as input.

    Constraints:
    - Input number should be a positive integer.
    - The integer should be between 1 and 2000 (both inclusive).
*/
/*
    Logic:
    - Convert the input number to its Roman numeral representation.
    - Calculate the ASCII sum of the Roman numeral string.
    - Reverse the ASCII sum and output the result.

    Sample Input:
    45

    Sample Output:
    52
*/
/*
    Edge Cases and Explanations:

    Input1: 23
    Output1: 593
    Explanation:
    - Roman numeral for 23 is "XXIII" (ASCII sum = 88 + 88 + 73 + 73 + 73 = 395).
    - Reversed sum: 593.

    Input2: 12
    Output2: 432
    Explanation:
    - Roman numeral for 12 is "XII" (ASCII sum = 88 + 73 + 73 = 234).
    - Reversed sum: 432.

    Input3: 1999
    Output3: 735
    Explanation:
    - Roman numeral for 1999 is "MCMXCIX" (ASCII sum = 77 + 67 + 77 + 88 + 67 + 73 + 88 = 537).
    - Reversed sum: 735.

    Input4: 244
    Output4: 754
    Explanation:
    - Roman numeral for 244 is "CCXLIV" (ASCII sum = 67 + 67 + 88 + 76 + 73 + 86 = 457).
    - Reversed sum: 754.

    Input5: 1000
    Output5: 77
    Explanation:
    - Roman numeral for 1000 is "M" (ASCII sum = 77).
    - Reversed sum: 77.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string intToRoman(int num)
{
    if (num <= 0 || num > 3999)
    {
        throw invalid_argument("Error: Input is not a positive integer. You need not handle such cases in your code.");
    }

    string roman = "";
    vector<pair<int, string>> romanMap = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

    for (const auto &entry : romanMap)
    {
        while (num >= entry.first)
        {
            roman += entry.second;
            num -= entry.first;
        }
    }
    return roman;
}

int asciiSum(const string &str)
{
    int sum = 0;
    for (char ch : str)
    {
        sum += static_cast<int>(ch);
    }
    return sum;
}

int reverseNumber(int num)
{
    int reversed = 0;
    while (num > 0)
    {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }
    return reversed;
}

int main()
{

    try
    {
        int X;
        cin >> X;

        if (X < 1 || X > 2000)
        {
            throw invalid_argument("Error: Input is not a positive integer. You need not handle such cases in your code.");
        }

        string romanX = intToRoman(X);
        int asciiSumX = asciiSum(romanX);
        int reversedSum = reverseNumber(asciiSumX);

        cout << reversedSum << endl;
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
