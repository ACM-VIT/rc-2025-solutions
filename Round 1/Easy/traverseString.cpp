/*
    Name: traverseString

    Author: Aarjav Jain

    Difficulty: Easy

    Round: Round 1

    Test Case Description:
    - Takes a string of characters as input
    - Returns an array of integer as output

    Constraints:
    - Input must be a non-empty string of characters
    - 1 < length of input string <= 50
    - Input must only contain alphabetic characters
*/

/*
    Logic:
    - Take a string of characters as input.
    - Iterate through each pair of consecutive characters in the string.
    - Calculate the absolute difference between the ASCII values of consecutive characters.
    - Return the array with all the absolute differences as space-separated integers.

    Sample Input:
    hello

    Sample Output:
    3 7 0 3

    Explanation:
    - ASCII values: 'h' = 104, 'e' = 101, 'l' = 108, 'l' = 108, 'o' = 111
    - Absolute differences: |104 - 101| = 3, |101 - 108| = 7, |108 - 108| = 0, |108 - 111| = 3
*/

/*
    Edge Cases:

    Input1: coding
    Output1: 12 11 5 5 7

    Input2: ABCdef
    Output2: 1 1 33 1 1

    Input3: zyxwvutsrqponmlkjihgfedcba
    Output3: 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

    Input4: aaaaaa
    Output4: 0 0 0 0 0

    Input5: xHhwfAo
    Output5: 48 32 15 17 37 46
*/

#include <iostream>
#include <vector>
using namespace std;
int main()
{

    string inp;
    cin >> inp;
    if (inp.empty() || inp.length() == 1 || inp.length() > 50)
    {
        cout << "Invalid Input. You need not handle such cases in your code." << endl;
        return 0;
    }
    for (char c : inp)
    {
        if (!isalpha(c))
        {
            cout << "Invalid Input. You need not handle such cases in your code." << endl;
            return 0;
        }
    }
    vector<int> diff;
    for (int i = 0; i < inp.length() - 1; i++)
        diff.push_back(abs(inp[i] - inp[i + 1]));
    for (int i : diff)
        cout << i << " ";
    cout << endl;
    return 0;
}