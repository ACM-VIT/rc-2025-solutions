/*
    Name: ezShift
    Author: Kaustubh Kanodia
    Difficulty: Easy
    Round: 1

    Test Case Description:
    The input consists of a string representing the time in MMHH format.
    Constraints:
    - Input string contains exactly 4 digits.
    - The first two digits represent minutes (00 to 59).
    - The last two digits represent hours (00 to 23).
*/

/*
    Logic:
    - Parse the input as two separate integers: minutes and hours.
    - Convert the hours from 24-hour format to 12-hour format for analog clock mirroring.
    - Calculate the mirrored hours: (12 - hours) % 12.
        * If the result is 0, set it to 12.
    - Calculate the mirrored minutes: (60 - minutes) % 60.
        * If the result is 60, set it to 0 and increment the mirrored hour.
    - Format the mirrored time back into MMHH format.
    Sample Input:
    3012
    Sample Output:
    3012
*/

/*
    Edge Cases:
    Input1: 4512
    Output1: 1512
    Input2: 4321
    Output2: 1703
    Input3: 1509
    Output3: 4503
    Input4: 1002
    Output4: 5010
    Input5: 3508
    Output5: 2504
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

string getMirroredTime(int hours, int minutes)
{
    // Convert to 12-hour format if necessary
    int mirroredHours = (12 - hours) % 12;
    if (mirroredHours == 0)
        mirroredHours = 12;

    // Calculate mirrored minutes
    int mirroredMinutes = (60 - minutes) % 60;
    if (mirroredMinutes == 60)
    {
        mirroredMinutes = 0;
        mirroredHours = (mirroredHours % 12) + 1; // Adjust the hour
    }

    // Format and return the mirrored time in MMHH format
    ostringstream result;
    result << setw(2) << setfill('0') << mirroredMinutes
           << setw(2) << setfill('0') << mirroredHours;
    return result.str();
}

int main()
{

    string inputTime;
    cin >> inputTime;

    // Validate input format
    if (inputTime.size() != 4 || !isdigit(inputTime[0]) || !isdigit(inputTime[1]) ||
        !isdigit(inputTime[2]) || !isdigit(inputTime[3]))
    {
        cout << "Invalid Input. You need not handle such cases in your code" << endl;
        return 1;
    }

    // Extract minutes and hours from the input (MMHH format)
    int minutes = stoi(inputTime.substr(0, 2));
    int hours = stoi(inputTime.substr(2, 2));

    // Validate the extracted time
    if (hours < 0 || hours >= 24 || minutes < 0 || minutes >= 60)
    {
        cout << "Invalid Input. You need not handle such cases in your code" << endl;
        return 1;
    }

    // Convert 24-hour time to 12-hour format for mirroring
    int adjustedHours = (hours % 12 == 0) ? 12 : hours % 12;

    // Get the mirrored time
    string mirroredTime = getMirroredTime(adjustedHours, minutes);
    cout << mirroredTime << endl;

    return 0;
}
