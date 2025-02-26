/*
    Name: reverse
    Author: Aditya Naik
    Difficulty: Easy
    Round: Round 1

    Test Case Description:
    The first line of input of each test case contains a single integer,'n' -  the size of the array.
    The second line of input consists of 'n' space-separated integers I1 I2 I3 I4......

    Constraints:
    - Input must be a valid vector of integers.
    - n must be at least 1.


/*
    Logic:
    - The first element of the prefix XOR array is the first element of the resulting array.
    - For each subsequent element in the prefix XOR array, calculate the XOR of the current element and the previous element.
    - Store the results in a new array and return it.

    Sample Input:
    5
    5 2 0 3 1

    Sample Output:
    5 7 2 3 2

    Explanation:
    - The prefix XOR array is [5, 2, 0, 3, 1].
    - Reconstruct the original array using XOR logic:
    Original array = [5, 5 ^ 2, 2 ^ 0, 0 ^ 3, 3 ^ 1] = [5, 7, 2, 3, 2].
*/

/*
Edge Cases:
    Input1:
        1
        1
    Output1:
        1
    Explanation: A single-element array remains unchanged.

    Input2:
        3
        0 0 0
    Output2:
        0 0 0
    Explanation: XORing zero with any number results in the same number.

    Input3:
        3
        4 6 2
    Output3:
        4 2 4
    Explanation: Prefix XOR values are used to derive the original array.
*/

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

// Function to reconstruct the original array from prefix XOR array
vector<int> findArrayFromPrefixXor(const vector<int> &pref)
{
    vector<int> result;
    int temp = 0;
    result.push_back(pref[0]);
    for (size_t i = 1; i < pref.size(); i++)
    {
        temp = pref[i] ^ pref[i - 1];
        result.push_back(temp);
    }
    return result;
}

int main()
{
    try
    {
        int n;
        cin >> n;
        if (cin.fail())
            throw invalid_argument("Invalid input! Please enter a valid integer. You need not handle such cases in your code.");
        if (n <= 0)
            throw invalid_argument("Input must be greater than 0. You need not handle such cases in your code.");
        vector<int> pref(n);
        for (int i = 0; i < n; i++)
        {
            cin >> pref[i];
            if (cin.fail())
            {
                throw invalid_argument("Invalid array input! Please enter valid integers. You need not handle such cases in your code.");
            }
        }
        vector<int> result = findArrayFromPrefixXor(pref);
        for (int num : result)
            cout << num << " ";
        cout << endl;
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
