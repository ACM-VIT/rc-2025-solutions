/*
    Name: digitSum

    Author: Naincy Jain

    Difficulty: Easy

    Round: Round 1

    Test Case Description:
    - Takes a single integer as input
    - Returns a single integer as output

    Constraints:
    - Input must be a integer between 0 and 1000 both inclusive
*/

/*
    Logic:
    - Take an integer number as input.
    - Calculate the factorial of the number.
    - Return the sum of the digits of the factorial.

    Sample Input:
    15

    Sample Output:
    45

    Explanation:
    - The factorial of 15 is 1307674368000
    - The sum of the digits of the factorial is 45
*/

/*
    Edge Cases:

    Input1: 0
    Output1: 1

    Input2: 123
    Output2: 765

    Input3: 10
    Output3: 27

    Input4: 681
    Output4: 6417

    Input5: 1000
    Output5: 10539
*/

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n < 0 || n > 1000)
    {
        cout << "Invalid Input. You need not handle such cases in your code." << endl;
        return 0;
    }
    vector<int> digits(1, 1);
    for (int i = 2; i <= n; i++)
    {
        int carry = 0;
        for (int j = 0; j < digits.size(); j++)
        {
            int prod = digits[j] * i + carry;
            digits[j] = prod % 10;
            carry = prod / 10;
        }
        while (carry)
        {
            digits.push_back(carry % 10);
            carry /= 10;
        }
    }
    int sum = 0;
    for (int digit : digits)
        sum += digit;
    cout << sum << endl;
    return 0;
}