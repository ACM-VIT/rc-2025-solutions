/*
    Name: finalCount
    Author: Prateek Purohit
    Difficulty: Easy

    Test Case Description:
    First line is a positive integer(n)
    Second line is a positive integer(k)

    CONSTRAINTS:
    1<=n<=10^5
    1<=k<=10^5

    Logic:
    Calculate the super digit of the number.
    First input is the number. Second input is the number of times the given number is repeated.

    Sample Input 1:
    196
    3

    Sample Output 1:
    3

    Explanation:
    196
    3
    196196196
    1+9+6+1+9+6+1+9+6 = 48
    4+8 = 12
    1+2 = 3  (final answer)

    Sample Input 2:
    100000
    1

    Sample Output 2:
    1

    Sample Input 3:
    9
    5

    Sample Output 3:
    9

    Sample Input 4:
    9
    999

    Sample Output 4:
    9

    Sample Input 5:
    98989
    99999

    Sample Output 5:
    9

*/

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// function to calculate the super digit recursively
int superDigitHelper(long long n)
{
    if (n < 10)
    {
        return n;
    }

    // Recursive case for sum the digits of n
    long long sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }

    // Recursively call superDigitHelper on the sum
    return superDigitHelper(sum);
}

// Function to calculate super digit
int superDigit(string n, int k)
{
    // Check for empty string
    if (n.empty())
    {
        throw invalid_argument("Input string 'n' cannot be empty. You need not handle such cases in your code");
    }

    // Calculate the sum of digits of n
    long long sum = 0;
    for (char digit : n)
    {
        sum += digit - '0'; // Convert char to integer
    }

    sum *= k;

    return superDigitHelper(sum);
}

int main()
{

    try
    {
        int n;
        int k;

        cin >> n;
        cin >> k;

        if (n > 100000 || n < 1 || k > 100000 || k < 1)
        {
            cerr << "input out of bounds. You need not handle such cases in your code" << endl;
            exit(0);
        }

        string num = to_string(n);
        cout << superDigit(num, k) << endl;
    }
    catch (const exception &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
