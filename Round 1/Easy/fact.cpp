/*
    Name: fact
    Author: Aditya Naik
    Difficulty: Easy
    Round: Round 1

    Test Case Description:
    The first line of input of each test case contains a single integer,'n'.

    Constraints:
    - Input must be a valid integer.
    - n must be between 0 and 65535 (Both inclusive).


/*
    Logic:
    -We take a 16-bit number as the input ans split it into 2 8-bit numbers.
    -We then take the XOR of the 2 8-bit numbers which then forms thefirst 8 bits of the result.
    -The second part of the result is the first 8 bits of the input we get.

    Sample Input:
    1000

    Sample Output:
    60163

    Explanation:
    -The first 8 bits of the input are 00000011 and the second 8 bits are 11101000.
    -After taking XOR we get 11101011.
    -We then concatenate the first 8 bits of the input which results in 1110101100000011 which is 60163.
*/

/*
Edge Cases:
    Input1: 0
    Output1: 0
    Explanation: 0 XOR 0 is 0 and first 8 bits of 0 are also zero.

    Input2: 1
    Output2: 256
    Explanation: 00000000 XOR 00000001 is 00000001 + 00000000 which is 256.

    Input3: 65280
    Output3: 65535
    Explanation: 65280 is 1111111100000000 which results in 2^16 - 1.

    Input4: 65535
    Output4: 255
    Explanation: 1^1 is 0 therefore first 8 bits are all zero and rest are 1.
*/

#include <iostream>
#include <cmath>

using namespace std;
// Function that convert Decimal to binary
int decToBinary(int n)
{
    string str1 = "";
    string str2 = "";
    for (int i = 15; i >= 8; i--)
    {
        int k = n >> i;
        if (k & 1)
            str1 += '1';
        else
            str1 += '0';
    }
    for (int i = 7; i >= 0; i--)
    {
        int k = n >> i;
        if (k & 1)
            str2 += '1';
        else
            str2 += '0';
    }
    int sum = 0;
    for (int i = 0; i < 8; i++)
    {
        if (str1[i] != str2[i])
            sum += pow(2, 15 - i);
    }
    int r = 0;
    for (int i = 0; i < 8; i++)
    {
        if (str1[i] == '1')
            r += pow(2, 7 - i);
    }
    return sum + r;
}

int main()
{

    try
    {
        int n;
        cin >> n;
        if (cin.fail())
            throw invalid_argument("Invalid input! Please enter a valid integer. You need not handle such cases in your code.");
        if (n < 0 || n > 65535)
            throw out_of_range("Input must be between 0 and 65535. You need not handle such cases in your code.");

        int ans = decToBinary(n);
        cout << ans;
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
