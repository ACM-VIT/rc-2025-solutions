/*
    Name: streamAdd
    Author: Kaustubh Kanodia
    Difficulty: Medium
    Round: 1

    Test Case Description:
    The input consists of two strings, `word1` and `word2`.
    Constraints:
    - Strings consist of lowercase English letters ('a' to 'z').
*/

/*
    Logic:
    - Generate the Fibonacci sequence of indices (1, 1, 2, 3, 5, 8, ...).
    - Use the sequence to alternately pick characters from the two strings:
        * Odd-indexed Fibonacci positions pick from `word1`.
        * Even-indexed Fibonacci positions pick from `word2`.
    - Stop when indices exceed the length of both strings.
    - Combine the selected characters in the order they are picked.
    Sample Input:
    word1: reverse
    word2: coding
    Sample Output:
    rcedr
*/

/*
    Edge Cases:
    Input1: a
            b
    Output1: ab
    Input2: banana
            pineapple
    Output2: bpannl
    Input3: fgoasufbsakuyfaf
            ouastfgvihakbsfi
    Output3: fogasvy
    Input4: smhsmhsmh
            acmacmacm
    Output4: sammmc
    Input5: penpineappleapple
            pineappleapplepen
    Output5: ppenila

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to generate Fibonacci sequence up to a maximum index
// 1 1 2 3 5 8 13 21 (ref)
vector<int> generateFibonacci(int maxIndex)
{
    vector<int> fib = {1, 1}; // First two Fibonacci numbers
    while (true)
    {
        int nextFib = fib[fib.size() - 1] + fib[fib.size() - 2];
        if (nextFib > maxIndex)
            break;
        fib.push_back(nextFib);
    }
    return fib;
}

// Function to weave the strings based on Fibonacci indices
string fibonacciWeave(const string &word1, const string &word2)
{
    vector<int> fib = generateFibonacci(max(word1.size(), word2.size()));

    string result = "";
    bool takeFromWord1 = true; // Alternate between word1 and word2

    for (int index : fib)
    {
        // Check which string to pick the character from
        if (takeFromWord1 && index <= word1.size())
        {
            result += word1[index - 1];
        }
        else if (!takeFromWord1 && index <= word2.size())
        {
            result += word2[index - 1];
        }
        // Alternate between the two words
        takeFromWord1 = !takeFromWord1;
    }

    return result;
}

int main()
{
    
    string word1, word2;

    cin >> word1 >> word2;

    // Validate input
    if (word1.empty() || word2.empty())
    {
        cout << "Invalid Input. You need not handle such cases in your code." << endl;
        return 1;
    }

    for (char c : word1 + word2)
    {
        if (!islower(c))
        {
            cout << "Invalid Input. You need not handle such cases in your code." << endl;
            return 1;
        }
    }

    string result = fibonacciWeave(word1, word2);

    cout << result << endl;

    return 0;
}
