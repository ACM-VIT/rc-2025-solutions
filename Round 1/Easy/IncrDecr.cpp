/*
    Name: IncrDecr
    Author: P G Ghautham Arveen
    Difficulty: Easy
    Round: 1
    Test Case Description:
    First line is a positive integer(n)
    Second line is a set of n integers separated by space.
    CONSTRAINTS:
    1<=n<=350
    -10^5<=a[i]<=10^5

    Logic:
    First Line is an integer n which is the number of integers in the second line.
    Second Line is a set of n integers separated by space.
    Sample Input:
    6
    10 100 20 -30 400 50
    Sample Output:
    470
    Explanation:
    The answer is initialised to 0
    The first element is 10. 10 is added to the answer. the next number is 100. 10 < 100. So 100 is added to the answer.
    new answer is 110. 20 is less than 100. So 20 is subtracted from the answer. new answer is 90. Similarly -30 is subtracted from the answer.
    new answer is 120. 400 is added to the answer. new answer is 520. 50 is subtracted from the answer. new answer is 470.

/*

Edge Cases:

Input1: 1
        999
Output1: 999
Explanation:  For indicating addition.

Input2: 1
        -99
Output2: 99
Explanation: For indicating subtraction. And start point is 0.

Input3: 2
20 19
Output3: 1
Explanation: Complemet of Input5.

Input4: 20
16 29 37 48 65 64 7 68 9 80 11 12 93 14 95 46 97 48 79 20
Output4: 26

Input5: 2
19 20
Output5: 39
Explanation: No output.

*/

#include <iostream>
#include <stdexcept>
using namespace std;

int IncDec(int n, int a[])
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (ans < a[i])
        {
            ans += a[i];
        }
        else
        {
            ans -= a[i];
        }
    }
    return ans;
}

int main()
{

    try
    {
        int n;
        cin >> n;
        if (n <= 0)
        {
            throw invalid_argument("n must be an integer greater than 0. Errors cases need not be handled in your solution.");
        }

        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] < -1000 || a[i] > 1000)
            {
                throw out_of_range("Array elements must be between -1000 and 1000. Errors cases need not be handled in your solution.");
            }
        }

        int result = IncDec(n, a);
        cout << result << endl;
    }
    catch (const invalid_argument &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
    catch (const out_of_range &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
    catch (...)
    {
        cerr << "An unexpected error occurred" << endl;
    }

    return 0;
}