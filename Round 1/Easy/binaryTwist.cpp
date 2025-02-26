/*
    Name: binaryTwist

    Author: Aarjav Jain

    Difficulty: Easy

    Round: Round 1

    Test Case Description:
    - Takes a single integer as input
    - Returns a single integer as output

    Constraints:
    - Input must be a integer between 1 and 255 both inclusive
*/

/*
    Logic:
    - Take an integer number as input.
    - Convert the number to its binary value.
    - Take 1's complement of the binary value.
    - Reverse the complented binary value.
    - Convert the reversed value back to decimal and return it.

    Sample Input:
    5

    Sample Output:
    95

    Explanation:
    - The binary value of 5 is 00000101
    - The 1's complement of the binary value is 11111010
    - The reversed value of the 1's complement is 01011111
    - The decimal value of the reversed value is 95
*/

/*
    Edge Cases:

    Input1: 10
    Output1: 175

    Input2: 8
    Output2: 239

    Input3: 121
    Output3: 97

    Input4: 2
    Output4: 191

    Input5: 64
    Output5: 253
*/


#include <iostream>
using namespace std;
int main()
{

    int num, bits = 8;
    cin >> num;
    if (num < 1 || num > 255)
    {
        cout << "Invalid Input. You need not handle such cases in your code." << endl;
        return 0;
    }
    string binary(bits, '0');
    for (int i = bits - 1; i >= 0; --i, num /= 2)
        binary[i] = (num % 2 ? '1' : '0');
    for (char &bit : binary)
        bit = (bit == '1') ? '0' : '1';
    string reverse = binary;
    for (int i = 0, j = bits - 1; i < j; ++i, --j)
    {
        char temp = reverse[i];
        reverse[i] = reverse[j];
        reverse[j] = temp;
    }
    int result = 0, base = 1;
    for (int i = reverse.size() - 1; i >= 0; i--, base *= 2)
        if (reverse[i] == '1')
            result += base;
    cout << result << endl;
    return 0;
}