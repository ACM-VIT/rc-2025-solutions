/*
    Name: dissection
    Author: Prateek Purohit
    Difficulty: Medium

    Test Case Description:
    The input consists of two integers.
    First line is a positive integer(n)
    Second line is a positive integer(k)

    CONSTRAINTS:
    1<=n<=1000
    2<=k<=10

    Logic:
    The user needs to find out the number of ways a number 'n' can be represented as sum of k^th power of unique natural numbers.
    First input is the number. Second input is the power.

    Sample Input 1:
    27
    3

    Sample Output 1:
    1

    Explanation:
    Here we have to find all combination of unique cubes adding up to 27.
    The only possible solution is 3^3. Hence the final answer is 1.

    Sample Input 2:
    100
    2

    Sample Output 2:
    3

    Explanation:
    10^2 = 100;
    6^2 + 8^2 = 100;
    1^2 + 3^2 + 4^2 + 5^2 + 7^2 = 100;

    Here total 3 ways are possible to get sum of squares of unique natural numbers.
    Therefore "3" is the final answer.

    Sample Input 3:
    1000
    2

    Sample Output 3:
    1269

    Sample Input 4:
    2
    10

    Sample Output 4:
    0

    Sample Output 5:
    999
    10

    Sample Output 5:
    0
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <stdexcept>

using namespace std;

int power(int a, int k)
{
    if (k == 0)
    {
        return 1;
    }
    if (k % 2 == 0)
    {
        int temp = power(a, k / 2);
        if (temp > INT_MAX / temp)
        {
            return INT_MAX;
        }
        return temp * temp;
    }
    // else
    if (a > INT_MAX / power(a, k - 1))
    {
        return INT_MAX;
    }
    return a * power(a, k - 1);
}

int powerSumHelper(int n, const vector<int> &powers, int index)
{
    if (index == 0)
    {
        return (n == 1) ? 1 : 0;
    }

    int res = 0;

    if (n > powers[index])
    {
        // Case when x is greater than the current power
        res += powerSumHelper(n - powers[index], powers, index - 1);
        res += powerSumHelper(n, powers, index - 1);
    }
    else if (n == powers[index])
    {
        // Case when x equals the current power
        res = 1 + powerSumHelper(n, powers, index - 1);
    }
    else
    {
        // Case when x is less than the current power
        res += powerSumHelper(n, powers, index - 1);
    }

    return res;
}

int main()
{
   
    int n, k;
    cin >> n >> k;

    try
    {
        if (n > 1000 || n < 1)
        {
            throw out_of_range("n must be from 1 to 1000. You need not handle such cases in your code");
        }
        if (k > 10 || k < 2)
        {
            throw out_of_range("k must be from 2 to 10. You need not handle such cases in your code");
        }

        int pow = 1;
        vector<int> powers;
        for (int a = 2; pow <= n; a++)
        {
            powers.push_back(pow);
            pow = power(a, k);
        }

        cout << powerSumHelper(n, powers, powers.size() - 1) << endl;
    }
    catch (const out_of_range &e)
    {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
