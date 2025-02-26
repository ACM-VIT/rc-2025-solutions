/*
    Name: clearedToLand
    Author: Manan Shah
    Difficulty: Medium
    Round:
    Test Case Description:
        The first line of input contains 1 non-negative integer n.
    Constraints:
        0 ≤ n ≤ 10^7
*/

/*
    Logic:
        - The aviation industry uses a system of naming runways based on the magnetic bearing angle of the runway. A runway is named by a number between 01 and 36, which is the runway heading in tens of degrees. For example, a runway with a heading of 90 degrees is named Runway 09. The opposite end of the runway is named by adding 18 to the runway heading and taking the modulo 36. For example, the opposite end of Runway 09 is Runway 27.

        - The input is an angle in degrees.
        - The bearing angle is calculated by taking the angle modulo 360.
        - The bearing angle is rounded to the nearest 10.
        - The runway heading is calculated by dividing the rounded bearing angle by 10.
        - If the runway heading is a single digit, it is padded with a zero.
        - The opposite runway heading is calculated by adding 18 to the runway heading and taking the modulo 36.
        - If the opposite runway heading is a single digit, it is padded with a zero.
        - The output is the runway heading and opposite runway heading in ICAO format.

    Sample Input:
    467
    Sample Output:
    Permission to land on Runway WUN WUN denied due to headwinds. Please land on Runway TOO NIN-ER instead.
*/

/*
    Edge Cases:
    Input1:
    0
    Output1:
    Permission to land on Runway ZEE-RO ZEE-RO denied due to headwinds. Please land on Runway WUN AIT instead.

    Input2:
    360
    Output2:
    Permission to land on Runway ZEE-RO ZEE-RO denied due to headwinds. Please land on Runway WUN AIT instead.

    Input3:
    238943
    Output3:
    Permission to land on Runway TOO SIX denied due to headwinds. Please land on Runway ZEE-RO AIT instead.

    Input4:
    10000000
    Output4:
    Permission to land on Runway TOO AIT denied due to headwinds. Please land on Runway WUN ZEE-RO instead.

    Input5:
    9876543
    Output5:
    Permission to land on Runway TREE ZEE-RO denied due to headwinds. Please land on Runway WUN TOO instead.

    Input6:
    15
    Output6:
    Permission to land on Runway ZEE-RO TOO denied due to headwinds. Please land on Runway TOO ZEE-RO instead.
*/

#include <iostream>
#include <unordered_map>
#include <stdexcept>
#include <cmath>
#include <string>

using namespace std;

int round(int n)
{
    // Smaller multiple
    int a = (n / 10) * 10;
    // Larger multiple
    int b = a + 10;

    // Return of closest of two
    return (n - a >= b - n) ? b : a;
}

string convert_icao(string n, unordered_map<char, string> ICAO)
{
    string result = "";
    for (int i = 0; i < n.length(); i++)
    {
        result += ICAO[n[i]] + " ";
    }
    return result;
}

string permissionToLand(int input, unordered_map<char, string> ICAO)
{
    // Calculate the bearing angle
    int bearingAngle = input % 360;

    // Find the runway heading, by rounding bearingAngle to the nearest 10
    int runwayHeading = (round(bearingAngle) / 10) % 36;

    // If heading is single digit, pad it with one zero and store it in a string
    string runwayHeadingStr = (runwayHeading < 10) ? "0" + to_string(runwayHeading) : to_string(runwayHeading);

    // Find the runway heading for the opposite end of the runway
    int oppositeRunwayHeading = (runwayHeading + 18) % 36;

    // If opposite heading is single digit, pad it with one zero and store it in a string
    string oppositeRunwayHeadingStr = (oppositeRunwayHeading < 10) ? "0" + to_string(oppositeRunwayHeading) : to_string(oppositeRunwayHeading);

    cout << "Permission to land on Runway " << convert_icao(runwayHeadingStr, ICAO) << "denied due to headwinds. Please land on Runway " << convert_icao(oppositeRunwayHeadingStr, ICAO) << "instead." << endl;

    return convert_icao(oppositeRunwayHeadingStr, ICAO);
}

int main()
{


    unordered_map<char, string> ICAO;
    ICAO['0'] = "ZEE-RO";
    ICAO['1'] = "WUN";
    ICAO['2'] = "TOO";
    ICAO['3'] = "TREE";
    ICAO['4'] = "FOW-ER";
    ICAO['5'] = "FIFE";
    ICAO['6'] = "SIX";
    ICAO['7'] = "SEV-EN";
    ICAO['8'] = "AIT";
    ICAO['9'] = "NIN-ER";

    try
    {
        int input;
        cin >> input;

        // Validate input to ensure it's a valid type
        if (cin.fail())
        {
            throw runtime_error("Error: You need not handle such cases in your code");
        }
        else if (input < 0 || input > 1e8)
        {
            throw invalid_argument("Error: Input should be a positive integer less than 10^7. You need not handle such cases in your code");
        }

        permissionToLand(input, ICAO);
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}