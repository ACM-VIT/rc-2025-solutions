/*
    Name: falsePositive

    Author: Aarjav Jain, Hemanth Balgi

    Difficulty: Easy

    Round: Round 1

    Test Case Description:
    - Takes a string of characters as input

    Constraints:
    - Input must be a non-empty string of alphabets and digits.
    - 1 <= length of input string <= 50
*/

/*
    Logic:
    - Take a string of characters as input.
    - Convert the input string to lowercase.
    - Check if the input string is palindrome or not.
    - If the input string is a palindrome, print "false".
    - If the input string is not a palindrome, print "true".

    Sample Input: programming

    Sample Output: true

    Explanation:
    - The input string "programming" is not a palindrome.
*/

/*
    Edge Cases:

    Input1: coding
    Output1: true

    Input2: Madam
    Output2: false

    Input3: a
    Output3: false

    Input4: racecar
    Output4: false

    Input5: acm
    Output5: true
*/

#include <iostream>
using namespace std;
int main()
{
    string inp;
    cin >> inp;
    if (inp.empty() || inp.length() > 50)
    {
        cout << "Invalid Input. You need not handle such cases in your code." << endl;
        return 0;
    }
    string rev = "";
    for (int i = 0; i < inp.length(); i++)
        inp[i] = tolower(inp[i]);
    for (int i = inp.length() - 1; i >= 0; i--)
        rev += inp[i];
    if (rev == inp)
        cout << "false" << endl;
    else
        cout << "true" << endl;
    return 0;
}