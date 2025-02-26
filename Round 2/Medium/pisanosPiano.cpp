/*
    Name: pisanosPiano
    Author: Hemanth Balgi
    Difficulty: Medium
    Round:
    Test Case Description:
        The first line of input contains a single positive integer,'n'.
    Constraints:
        1 <= n <= 9999
*/

/*
    Logic:
    -Start with the Fibonacci numbers 0 and 1.
    -In each iteration, calculate the next Fibonacci number modulo n using the sum of the previous two numbers.
    -Check if the sequence 0, 1 repeats.
    -The iteration count when 0, 1 repeats is the Pisano period.
    -The Pisano period is always found within n^2 iterations.
    -Output the number of iterations it took for the sequence to repeat.

    Sample Input:
    65
    Sample Output:
    140
*/

/*
    Edge Cases:
    Input1: 76
    Output1: 18

    Input2: 100
    Output2: 300

    Input3: 1
    Output3: 0

    Input4: 7
    Output4: 16

    Input5: 25
    Output5: 100
*/

#include <iostream>
#include <stdexcept>
using namespace std;

// Function to find the Pisano period for a given number n
int pisanoPeriod(int n)
{
    int previous = 0, current = 1;

    // The Pisano period always starts with 0, 1
    for (int i = 0; i < n * n; i++)
    {
        int temp = current;
        current = (previous + current) % n;
        previous = temp;

        // The period starts with 0, 1 again
        if (previous == 0 && current == 1)
        {
            return i + 1;
        }
    }
    return 0; // Return 0 if no period is found, which shouldn't happen
}

int main()
{

    try
    {
        int n;
        cin >> n;

        // Check if the input is a valid integer and within the valid range (1 to 9999)
        if (cin.fail() || n <= 0 || n > 9999)
        {
            throw invalid_argument("Error: Input is not a positive integer in range 0-9999. You need not handle such cases in your code");
        }

        // Calculate and print the Pisano period
        int period = pisanoPeriod(n);
        cout << period << endl;
    }
    catch (const exception &e)
    {
        // Catch any errors and print "Invalid input"
        cout << "Error: Input is not a positive integer in range 0-9999. You need not handle such cases in your code" << endl;
    }
    return 0;
}