/*
    Name: followTrend

    Author: Aarjav Jain

    Difficulty: Easy

    Round: Round 1

    Test Case Description:
    - Takes a string as input
    - Returns an integer as output

    Constraints:
    - Input must be a non-empty string with 'X' and 'Y' characters only
    - Length of the string <= 8
*/

/*
    Logic:
    - The input pattern is a sequence of 'X' and 'Y' where:
        - 'X' stands for increasing: the next digit must be larger than the previous digit.
        - 'Y' stands for decreasing: the next digit must be smaller than the previous digit.
    - Start with the first digit and try all remaining unused digits to match the pattern.
    - Return the smallest sequence of unique digits that satisfies the pattern.

    Sample Input:
    XY

    Sample Output:
    132

    Explanation:
    - The pattern "XYX" means:
        - First digit < Second digit (X) -> 1 < 3
        - Second digit > Third digit (Y) -> 3 > 2
    - The smallest sequence satisfying the pattern is 132
*/

/*
    Edge Cases:

    Input1: XYXYXYXY
    Output1: 132547698

    Input2: XXXXXXXX
    Output2: 123456789

    Input3: YYYYYYYY
    Output3: 987654321

    Input4: XXYYXXYY
    Output4: 125436987

    Input5: XXXXYYYY
    Output5: 123498765
*/

#include <iostream>
#include <vector>
using namespace std;
int main()
{

    string inp;
    cin >> inp;
    bool valid = !inp.empty() && inp.size() <= 8;
    for (char c : inp)
    {
        if (c != 'X' && c != 'Y')
        {
            valid = false;
            break;
        }
    }
    if (!valid)
    {
        cout << "Invalid Input. You need not handle such cases in your code." << endl;
        return 0;
    }
    vector<int> seq;
    vector<bool> used(10, false);
    auto backtrack = [&](int idx, auto &&backtrackRef) -> bool
    {
        if (idx == inp.size() + 1)
            return true;
        for (int d = 1; d <= 9; ++d)
        {
            if (!used[d] && (idx == 0 || (inp[idx - 1] == 'X' && seq.back() < d) || (inp[idx - 1] == 'Y' && seq.back() > d)))
            {
                used[d] = true;
                seq.push_back(d);
                if (backtrackRef(idx + 1, backtrackRef))
                    return true;
                seq.pop_back();
                used[d] = false;
            }
        }
        return false;
    };
    if (backtrack(0, backtrack))
    {
        for (int d : seq)
            cout << d;
        cout << endl;
    }
    return 0;
}