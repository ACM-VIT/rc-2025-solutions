/*
    Name: Area

    Author: P G Ghautham Arveen

    Difficulty: Easy

    Round: 1

    Test Case Description: 3 positive space separated integers a, b, c

    Constraints: 1<=a,b,c<=1000

    Logic: The input is 3 integers a, b, c. The 3 integers are coordinates in a xyz plane.
    We need to find the area of the triangle formed by the 3 points.

    Sample Input 1:
    1 1 1
    Sample Output 1:
    1

    Sample Input 2:
    23 56 10
    Sample Output 2:
    712

    Sample Input 3:
    1000 1000 1000
    Sample Output 3:
    866026



    /*
    Edge Cases:

    Input1:
    1 1 1
    Output1: 1
    Explanation: The proper use of ceil function is tested here

    Input2:
    1000 1000 1000
    Output2: 866026
    Explanation: The largest possible input is tested here.

    Input3:
    24 45 67
    Output3: 1792
    Explanation: Random numbers are tested here.

    Input4:
    3 3 3
    Output4: 8
    Explanation: Random numbers.

    Input5:
    1 2 3
    Output5: 4
    Explanation: Random numbers.
*/


#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// a function that takes an array of 3 integers a, b, c and returns an array of (a^2 + b^2 ) ^ 0.5, (b^2 + c^2) ^ 0.5, (c^2 + a^2) ^ 0.5

float *Sides(int a, int b, int c)
{
    float *ans = new float[3];
    ans[0] = sqrt(a * a + b * b);
    ans[1] = sqrt(b * b + c * c);
    ans[2] = sqrt(c * c + a * a);
    return ans;
}

float HeronsArea(int a, int b, int c)
{
    float *sides = Sides(a, b, c);
    float s = (sides[0] + sides[1] + sides[2]) / 2;
    float area = sqrt(s * (s - sides[0]) * (s - sides[1]) * (s - sides[2]));
    return area;
}

int main()
{

    int a, b, c;
    try
    {
        cin >> a >> b >> c;
        if (a <= 0 || b <= 0 || c <= 0)
        {
            throw invalid_argument("a, b, c must be integers greater than 0. Error cases need not be handled in your solution.");
        }
        cout << static_cast<long long>(ceil(HeronsArea(a, b, c))) << endl;
    }
    catch (invalid_argument e)
    {
        cout << e.what();
    }

    return 0;
}