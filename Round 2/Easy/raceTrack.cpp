/*
    Name: raceTrack

    Author: Aarjav Jain

    Difficulty: Easy

    Round: Round 1

    Test Case Description:
    - Takes three space-separated integer a b c

    Constraints:
    - 0 < a, b, c < 10000
*/

/*
    Logic:
    - Take three integers a, b and c as input.
        - The first racer beats the second by a units.
        - The first racer beats the third by b units.
        - The second racer beats the third by c units.
    - Return the length of the race track to two decimal places.

    Sample Input: 11 90 80

    Sample Output: 880.00

    Explanation:
    - The first racer beats the second by 11 units.
    - The first racer beats the third by 90 units.
    - The second racer beats the third by 80 units.
    - length = (a * c) / (c + a - b) = (11 * 80) / (80 + 11 - 90) = 880.00
*/

/*
    Edge Cases:

    Input1: 1 1 1
    Output1: 1.00

    Input2: 5000 4900 50
    Output2: 1666.67

    Input3: 86 36 450
    Output3: 77.40

    Input4: 812 828 602
    Output4: 834.17

    Input5: 916 436 417
    Output5: 425.83
*/

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a <= 0 || b <= 0 || c <= 0 || a >= 10000 || b >= 10000 || c >= 10000)
    {
        cout << "Invalid Input. You need not handle such cases in your code." << endl;
        return 1;
    }
    cout << fixed << setprecision(2) << (double)(a * c) / (c + a - b) << endl;
    return 0;
}