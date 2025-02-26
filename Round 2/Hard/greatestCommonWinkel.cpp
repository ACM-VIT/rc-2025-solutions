/*
    Name: greatestCommonWinkel
    Author: Manan Shah
    Difficulty: Medium
    Round:
    Test Case Description:
        The first line of input contains 3 space-separated unique floats, 'x0, x1, x2' - the x-coordinates of the 3 points.
        The second line of input contains 3 space-separated unique floats, 'y0, y1, y2' - the y-coordinates of the 3 points.
    Constraints:
        All the floats ('x0' - 'x2', 'y0' - 'y2') are in the range of -10^8 to 10^8.
        'x1', 'x2' and 'x3' must be unique (i.e. x1 != x2, x1 != x3, x2 != x3).
        'y1', 'y2' and 'y3' must be unique (i.e. y1 != y2, y1 != y3, y2 != y3).
        NOTE: Take the value of PI as 3.142.
*/

/*
    Logic:
        - The 6 floats are the coordinates of 3 points in the plane, which form 2 vectors with a common tail.
        - Each point is taken as the common tail and the angle between the two vectors is calculated in degrees, rounded to the nearest integer.
        - The final output is the gcd of the three angles obtained.

    Sample Input:
    10 0 -5
    -5 0 6
    Sample Output:
    2
*/

/*
    Edge Cases:
    Input1:
    1 4 -2
    7 -3 11
    Output1:
    2

    Input2:
    0.00000001 0.00000002 100000000
    0.00000001 0.00000002 100000000
    Output2:
    180

    Input3:
    1000000000 900000000 800000000
    1000000000 900000000 800000000
    Output3:
    180

    Input4:
    3.37 0 5
    3.83 0 -1
    Output4:
    60

    Input5:
    -695 10506 -98903
    -462 284798 22000
    Output5:
    1
*/

#include <iostream>
#include <math.h>
#include <stdexcept>
#include <vector>

#define PI 3.142

using namespace std;

struct Coordinate
{
    float x;
    float y;
};

// Function to calculate the angle between the two vectors and check if it's the same as the type_angle
int calculateAngleAndCheck(vector<Coordinate> coords)
{
    float x0, y0, x1, y1, x2, y2;
    x0 = coords[0].x;
    y0 = coords[0].y;
    x1 = coords[1].x;
    y1 = coords[1].y;
    x2 = coords[2].x;
    y2 = coords[2].y;

    // Getting the two vectors we want (NOTE: here, the vector will be xi + yj):
    Coordinate v1, v2;
    v1.x = x1 - x0;
    v1.y = y1 - y0;
    v2.x = x2 - x0;
    v2.y = y2 - y0;

    // Calculating the angle between the two vectors:
    float dot_product = (v1.x * v2.x) + (v1.y * v2.y);
    float magnitude_v1 = sqrt(pow(v1.x, 2) + pow(v1.y, 2));
    float magnitude_v2 = sqrt(pow(v2.x, 2) + pow(v2.y, 2));

    float costheta = dot_product / (magnitude_v1 * magnitude_v2);
    if (costheta > 1)
    {
        costheta = 1;
    }
    else if (costheta < -1)
    {
        costheta = -1;
    }
    float angle = acos(costheta);

    // Converting the angle to degrees:
    angle = angle * 180 / PI;

    // Rounding the angle to the nearest integer:
    angle = round(angle);

    return angle;
}

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int gcdOfAngles(int a, int b, int c)
{
    return gcd(gcd(a, b), c);
}

int findAngles(vector<Coordinate> coords)
{
    vector<int> angles;

    // Calculating the angles between the vectors formed by the 3 points:
    int angle1 = calculateAngleAndCheck(coords);
    angles.push_back(angle1);

    // Rotating the points to get the other two angles:
    Coordinate temp = coords[0];
    coords[0] = coords[1];
    coords[1] = coords[2];
    coords[2] = temp;

    int angle2 = calculateAngleAndCheck(coords);
    angles.push_back(angle2);

    temp = coords[0];
    coords[0] = coords[1];
    coords[1] = coords[2];
    coords[2] = temp;

    int angle3 = calculateAngleAndCheck(coords);
    angles.push_back(angle3);

    return gcdOfAngles(angles[0], angles[1], angles[2]);
}

int main()
{

    try
    {
        vector<Coordinate> coords;
        for (int i = 0; i < 3; i++)
        {
            Coordinate coord;
            cin >> coord.x;
            coords.push_back(coord);
        }
        for (int i = 0; i < 3; i++)
        {
            cin >> coords[i].y;
        }

        // Validate input to ensure it's a valid type
        if (cin.fail())
        {
            throw runtime_error("Error: You need not handle such cases in your code");
        }
        else if (coords[0].x > pow(10, 9) || coords[0].x < -pow(10, 9) || coords[0].y > pow(10, 9) || coords[0].y < -pow(10, 9) || coords[1].x > pow(10, 9) || coords[1].x < -pow(10, 9) || coords[1].y > pow(10, 9) || coords[1].y < -pow(10, 9) || coords[2].x > pow(10, 9) || coords[2].x < -pow(10, 9) || coords[2].y > pow(10, 9) || coords[2].y < -pow(10, 9))
        {
            throw invalid_argument("Error: The values of x and y lie between 10e-8 and 10e8. You need not handle such cases in your code");
        }
        else if (coords[0].x == coords[1].x || coords[0].x == coords[2].x || coords[1].x == coords[2].x)
        {
            throw invalid_argument("Error: x values must be unique. You need not handle such cases in your code");
        }
        else if (coords[0].y == coords[1].y || coords[0].y == coords[2].y || coords[1].y == coords[2].y)
        {
            throw invalid_argument("Error: y values must be unique. You need not handle such cases in your code");
        }

        cout << (findAngles(coords)) << endl;
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}