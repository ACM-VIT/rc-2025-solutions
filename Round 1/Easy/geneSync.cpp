/*
    Name: geneSync

    Author: Rishit Shivam

    Difficulty: Easy

    Round: 1

    Test Case Description:
    The input consists of 2 strings.
    The first line of input contains a string s1,
    THe second line of input contains a string s2.

    Constraints:
    s1 string length : 1 to 256 (Incusive)
    s2 string length: 1 to 256 (Incusive)
    The strings s1 and s2 can contain only uppercase 'A', 'T', 'G' and 'C' characters.
*/

/*
    Logic:
    It finds the length of Longest Common Subsequence (LCS) of two strings.

    Sample Input:
    ACCGGTCGAGTGCGCGGAAGCCGGCCGAA
    GTCGTTCGGAATGCCGTTGCTCTGTAAA

    Sample Output:
    20
*/

/*
    Edge Cases:

    Input1: GACACTGCCGCATACGCATCCCCCCCCCCCCCCCCCCCACACACACATGCG
            GGGGGGGGGGGGGG
    Output1: 6

    Input2: ACGCTCTCTCTGGACATGCCTGACTGAGTCAGTC
            ACCCTTTTGAG
    Output2: 11

    Input3: GTAGTAGTAGTATGAGGTGAGGAGAGAAGAGGTTTTT
            GTAGTATTGAAGAGGTTT
    Output3: 18

    Input4: CCTAGCCTAGCCTAGCCTAGCCGATCCGATCCGATCCGATCC
            TAGCCTAGCCGATCCGATCCTCCGATCC
    Output4: 28

    Input5: GCTATATCGATGCATGGGCACACTTAGACTA
            ATGCATGCATGCATGCATGC
    Output5: 17

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isValidDNASequence(const string &sequence)
{
    for (char c : sequence)
    {
        if (c != 'A' && c != 'T' && c != 'G' && c != 'C')
        {
            return false;
        }
    }
    return true;
}

int lcs(const string &s1, const string &s2)
{
    int m = s1.size();
    int n = s2.size();

    // creating 2D array to store lengths of LCS
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // bottom-up approach
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Length of LCS
    int lcs_length = dp[m][n];

    return lcs_length;
}

int main()
{

    string s1, s2;

    cin >> s1 >> s2;

    if (!isValidDNASequence(s1) || !isValidDNASequence(s2) || s1.size() > 256 || s2.size() > 256)
    {
        cout << "Invalid Input" << endl;
        return 1;
    }

    auto result = lcs(s1, s2);

    cout << result << endl;

    return 0;
}
