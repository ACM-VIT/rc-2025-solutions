/*
    Name: minMax

    Author: Aarjav Jain

    Difficulty: Easy

    Round: Round 1

    Test Case Description:
    - Takes a string as input
    - Returns a string as output

    Constraints:
    - Input must be a non-empty string of lowercase alphabets
    - 1 <= length of input string <= 50
*/

/*
    Logic:
    - Take a string of characters as input.
    - Find the characters with minimum and maximum ASCII values.
    - Calculate the difference between the maximum and minimum ASCII values.
    - For each character in the string, add the difference to the ASCII value of the character.
    - If the new ASCII value exceeds 'z', wrap around to 'a'.
    - Return the modified string.

    Sample Input:
    hello

    Sample Output:
    rovvy

    Explanation:
    - The minimum character is 'e' with ASCII value 101.
    - The maximum character is 'o' with ASCII value 111.
    - The difference is 10.
    - ASCII values: 'h' = 104, 'e' = 101, 'l' = 108, 'l' = 108, 'o' = 111
    - New ASCII values: 114 = 'r', 111 = 'o', 118 = 'v', 118 = 'v', 121 = 'y'
    - Modified string: rovvy
*/

/*
    Edge Cases:

    Input1: aaaaa
    Output1: aaaaa

    Input2: abcdefghijklmnopqrstuvwxyz
    Output2: zabcdefghijklmnopqrstuvwxy

    Input3: azazazaz
    Output3: zyzyzyzy

    Input4: abcda
    Output4: defgd

    Input5: reverse
    Output5: ivmvijv
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string input;
    cin >> input;
    if (input.empty() || input.size() > 50)
    {
        cout << "Invalid Input. You need not handle such cases in your code." << endl;
        return 0;
    }
    for (char c : input)
    {
        if (!isalpha(c) || !islower(c))
        {
            cout << "Invalid Input. You need not handle such cases in your code." << endl;
            return 0;
        }
    }
    char minChar = *min_element(input.begin(), input.end());
    char maxChar = *max_element(input.begin(), input.end());
    int diff = maxChar - minChar;
    for (char &ch : input)
    {
        int tmp = ch + diff;
        ch = tmp > 'z' ? 'a' + (tmp - 'z' - 1) : tmp;
    }
    cout << input << endl;
    return 0;
}