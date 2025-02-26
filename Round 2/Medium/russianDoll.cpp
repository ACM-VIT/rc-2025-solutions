/*
    Name: russianDoll

    Author: Rishit Shivam

    Difficulty: Medium

    Round:

    Test Case Description:
    - The first line of input contains an integer n.
    - The second line of input contains an integer k.

    Constraints:
    - 1 ≤ n ≤ 100
    - 1 ≤ k ≤ n
*/

/*
   Logic:
    - Input is taken for the number of pairs of parentheses(n) and the maximum allowed depth(k).
    - No closed bracket is allowed before an open bracket until the previous ones are closed.
    - The depth tells the number of consecutive open/close brackets.
    - The total number of possible combinations of such parantheses is returned.

    Sample Input:
    3
    2

    Sample Output:
    14
*/

/*
    Edge Cases:

    Input1: 8
            6
    Output1: 14

    Input2: 20
            1
    Output2: 1

    Input3: 30
            15
    Output3: 9694845

    Input4: 50
            25
    Output4: 946367425

    Input5: 100
            10
    Output5: 807672816
*/
#include <iostream>
#include <vector>
#include <stdexcept> // For handling exceptions
using namespace std;

const int MOD = 1e9 + 7;

// Function to count valid parentheses expressions with max depth constraint
int countValidParentheses(int n, int k)
{
    // dp[i][j]: Number of valid parentheses with i pairs and current depth j
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    // Base case: 1 valid way with 0 pairs and depth 0
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    { // Number of pairs
        for (int j = 0; j <= k; j++)
        { // Current depth
            // Add opening parenthesis `(` if depth doesn't exceed k
            if (j > 0)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
            }
            // Add closing parenthesis `)` if depth is valid
            if (j < k)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }

    // The result is dp[n][0], as valid expressions end at depth 0
    return dp[n][0];
}

int main()
{

    int n, k;

    try
    {
        cin >> n >> k;

        // Validate constraints for n and k
        if (n < 1 || n > 100)
        {
            throw invalid_argument("Value of n must be between 1 and 100. You need not handle such cases in your code.");
        }
        if (k < 1 || k > n)
        {
            throw invalid_argument("Value of k must be between 1 and n. You need not handle such cases in your code.");
        }

        // Calculate the result
        int result = countValidParentheses(n, k);

        // Print the result
        cout << result << endl;
    }
    catch (const exception &e)
    {
        // Handle errors and print error messages
        cout << e.what() << endl;
    }

    return 0;
}
