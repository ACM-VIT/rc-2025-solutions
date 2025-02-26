/*
    Name: timeCrunch

    Author: Rishit Shivam

    Difficulty: Medium

    Round:

    Test Case Description:
        The first line of input contains a single integer,'n'.
        The second line of input contains a single integer,'t',
        The third line of input consists of n*n space-separated integers I1 I2 I3 I4......

    Constraints:
        - 1 <= n <= 100
        - 0 <= t <= 50
        - The elements of third input are integers within the range of [-1000, 1000].
*/

/*
    Logic:
        - The program takes the size of the matrix (n) and a number (t). It then initializes an n x n matrix with values from input.
        - It performs t operations, where:
            - If the operation number is odd, it rotates the matrix 90 degrees clockwise.
            - If the operation number is even, it adds the number t to each element of the matrix.

    Sample Input:
    3
    2
    9 10 11 12 13 14 15 16 17

    Sample Output:
    17 14 11
    18 15 12
    19 16 13
*/

/*
    Edge Cases:

    Input1: 2
            4
            1 2 4 5
    Output1: 13 12
             10 9

    Input2: 3
            10
            2 4 2 4 1 3 2 3 1
    Output2: 52 54 52
             53 51 54
             51 53 52

    Input3: 3
            3
            9 8 7 6 5 4 3 2 1
    Output3: 4 5 6
             7 8 9
             10 11 12

    Input4: 4
            2
            1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6
    Output4: 5 11 7 3
             6 12 8 4
             7 3 9 5
             8 4 10 6

    Input5: 3
            15
            3 2 1 1 2 3 3 2 1
    Output5: 108 107 106
             106 107 108
             108 107 106
*/

#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

// Function to add 'a' to each element of the square matrix
void addToMatrix(int **matrix, int n, int a)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            matrix[i][j] += a;
        }
    }
}

// Function to rotate the matrix 90 degrees clockwise
void rotateMatrix(int **matrix, int n)
{
    // Transpose the matrix
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n / 2; ++j)
        {
            swap(matrix[i][j], matrix[i][n - j - 1]);
        }
    }
}

int main()
{

    int n, t;

    // Input n and t with error handling
    cin >> n >> t;

    try
    {
        // Constraint checks
        if (n < 1 || n > 100)
        {
            throw out_of_range("Error: n must be between 1 and 100. You need not handle such cases in your code.");
        }
        if (t < 0 || t > 50)
        {
            throw out_of_range("Error: t must be between 0 and 50. You need not handle such cases in your code.");
        }

        // Dynamically allocate matrix
        int **matrix = new int *[n];
        for (int i = 0; i < n; ++i)
        {
            matrix[i] = new int[n];
        }

        // Taking input of matrix elements with validation
        for (int i = 0; i < n * n; ++i)
        {
            cin >> matrix[i / n][i % n];
            if (matrix[i / n][i % n] < -1000 || matrix[i / n][i % n] > 1000)
            {
                throw out_of_range("Error: Matrix elements must be between -1000 and 1000. You need not handle such cases in your code.");
            }
        }

        // Perform operations t times
        for (int i = 1; i <= t; ++i)
        {
            if (i % 2 == 0)
            {
                addToMatrix(matrix, n, t); // Add t to each element in the matrix
            }
            else
            {
                rotateMatrix(matrix, n); // Rotate matrix 90 degrees clockwise
            }
        }

        // Print the final matrix
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }

        // Deallocate memory
        for (int i = 0; i < n; ++i)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    catch (const out_of_range &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
