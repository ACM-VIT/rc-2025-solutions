/*
    Name: GoddId
    Author: Aditya Singh
    Difficulty: Medium
    Round:

    Test Case Description:
    The first line of input consists of two positive integers separated by a space.

    Constraints:
    - First input should be an integer and between 0(inclusive) and 1000(inclusive).
    - Second input should be an integer and between 0(inclusive) and 1000 (inclusive).


    Logic:
    - The input values represent:
      - frequency: The source's frequency (f).
      - speed: The speed of the source (vs).
    - Using the Doppler effect formulas, calculate:
      - Observed frequency when the source is approaching (f_approaching).
      - Observed frequency when the source is receding (f_receding).
    - Outputs are the two calculated frequencies.

    Sample Input:
    500 30

    Sample Output:
    547.92
    459.79

    Explanation:
    - Given:
      - Frequency = 500 Hz
      - Source speed = 30 m/s
      - Speed of sound in air = 343 m/s
    - Observed frequency when approaching:
      f_approaching = f * (v / (v - vs)) = 500 * (343 / (343 - 30)) = 547.92 Hz
    - Observed frequency when receding:
      f_receding = f * (v / (v + vs)) = 500 * (343 / (343 + 30)) = 459.79 Hz

    Edge Cases:
    Input1: 1000 0
    Output1:
    1000.00
    1000.00

    Input2: 440 10
    Output2:
    453.21
    427.54

    Input3: 100 343
    Output3:
    inf
*/

#include <iostream>
#include <iomanip> // For formatting output
using namespace std;

int main()
{
  // Constants
  const double speedOfSound = 343.0; // Speed of sound in air (m/s)
  double sourceFrequency, sourceSpeed;

  // Input from the user
  cin >> sourceFrequency;
  cin >> sourceSpeed;

  // Check for non-positive inputs
  if (sourceFrequency <= 0 || sourceSpeed <= 0 || sourceFrequency >= 1000 || sourceSpeed >= 1000)
  {
    cout << "Invalid Input. You need not handle such cases in your code." << endl;
    return 0; // Exit the program
  }

  // Calculate frequencies
  double frequencyApproaching = sourceFrequency * (speedOfSound / (speedOfSound - sourceSpeed));
  double frequencyReceding = sourceFrequency * (speedOfSound / (speedOfSound + sourceSpeed));

  // Output results
  cout << fixed << setprecision(2); // Formatting to 2 decimal places
  cout << frequencyApproaching << endl;
  cout << frequencyReceding << endl;

  return 0;
}
