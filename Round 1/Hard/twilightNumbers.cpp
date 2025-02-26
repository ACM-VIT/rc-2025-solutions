/*
    Name: twilightNumbers
    Author: Hemanth Balgi
    Difficulty: Hard
    Round:
    Test Case Description:
        The first line of input contains a single integer,'n'.
    Constraints:
        'n' is a four digit number.
        'n' cannot have all digits identical(example: 1111,9999).
*/

/*
    Logic:
        - Any four digit number that doesn't have all it's digits identical arrives at a constant number 6147 after a finite number of iterations of a set of operations.
        - The set of operations are as follows:
            - Arrange the number into ascending and descending order as two different values.
            - Subtract the ascending value from the descending value.
            - This operation is iterated over until the value reaches 6147, the number of iterations are counted and is the output.
        - The number of iterations can only be in the range of 0-7 both including for any four digit that satisfies the constraints.

    Sample Input:
    1234
    Sample Output:
    3
*/

/*
    Edge Cases:
    Input1: 6147
    Output1: 0

    Input2: 1000
    Output2: 5

    Input3: 9087
    Output3: 4

    Input4: 1006
    Output4: 7

    Input5: 7641
    Output5: 1

    Input6: 6589
    Output6: 2

    Input7: 1234
    Output7: 3

    Input8: 7493
    Output8: 6


*/
#include <iostream>
#include <algorithm>
#include <string>
#include <stdexcept>
using namespace std;

// Function to calculate the number of iterations to reach Kaprekar's constant
int kaprekarIterations(int num)
{
    const int KAPREKAR_CONSTANT = 6174; // The Kaprekar constant
    int count = 0;

    while (num != KAPREKAR_CONSTANT)
    {
        // Convert the number to a string and pad with zeros if necessary
        string numStr = to_string(num);
        while (numStr.size() < 4)
            numStr += '0';

        // Sort digits in ascending and descending order
        string ascending = numStr, descending = numStr;
        sort(ascending.begin(), ascending.end());
        sort(descending.rbegin(), descending.rend());

        // Compute the difference between descending and ascending numbers
        int ascNum = stoi(ascending);
        int descNum = stoi(descending);
        num = descNum - ascNum;

        count++;
    }

    return count;
}

int main()
{

    try
    {
        int num;
        cin >> num;

        // Validate input to ensure it's a valid four-digit number
        if (cin.fail() || num < 1000 || num > 9999 ||
            to_string(num).find_first_not_of(to_string(num)[0]) == string::npos)
        {
            throw runtime_error("Error: Input should be a four-digit number. You need not handle such cases in your code");
        }

        // Calculate the number of iterations to reach Kaprekar's constant
        int iterations = kaprekarIterations(num);
        cout << iterations << endl;
    }
    catch (const exception &e)
    {
        // Handle invalid input and display the error message
        cout << e.what() << endl;
        return 1;
    }

    return 0;
}
