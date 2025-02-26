// Name: Outliers
// Author: P G Ghautham Arveen
// Difficulty: Easy
// Round:
// Test Case Description: A positive integer n followed by n space separated integers
// Constraints: 1<=n<=1000
// a[i] <= 1000
// Logic:
// We need to find the number of elements that are greater than the mean + standard deviation of the given elements.

// Sample Input 1:
// 20
// 16 29 37 48 65 64 7 68 9 80 11 12 93 14 95 46 97 48 79 20
// Sample Output 1:
// 5

// Sample Input 2:
// 10
// 15 29 33 46 57 96 77 80 69 10
// Sample Output 2:
// 96 80

/*

Edge Cases:

Input1: 1
        999
Output1:
Explanation:  No output.

Input2: 5
        1 2 3 4 5
Output2: 5
Explanation: Indicating some math operation.

Input3: 10
15 29 33 46 57 96 77 80 69 10
Output3: 96 80

Input4: 20
16 29 37 48 65 64 7 68 9 80 11 12 93 14 95 46 97 48 79 20
Output4: 80 93 95 97 79

Input5: 2
19 20
Output5:
Explanation: No output.



*/
#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
using namespace std;

double calculateMean(const std::vector<double> &data)
{
    double sum = 0.0;
    for (size_t i = 0; i < data.size(); ++i)
    {
        sum += data[i];
    }
    return sum / data.size();
}

double calculateStandardDeviation(const std::vector<double> &data)
{
    double mean = calculateMean(data);
    double variance = 0.0;

    for (size_t i = 0; i < data.size(); ++i)
    {
        double value = data[i];
        variance += (value - mean) * (value - mean);
    }
    variance /= data.size();

    return sqrt(variance);
}

int main()
{

    try
    {
        int n;
        cin >> n;

        if (n <= 0 || n > 1000)
        {
            throw invalid_argument("Invalid input for n. Error cases need not be handled in your solution.");
        }

        vector<double> data(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> data[i];
            if (data[i] < 0 || data[i] > 1000)
            {
                throw invalid_argument("Invalid input for elements. Error cases need not be handled in your solution.");
            }
        }
        double mean = calculateMean(data);
        double stdDev = calculateStandardDeviation(data);
        double peak = mean + stdDev;

        int count = 0;
        for (size_t i = 0; i < n; ++i)
        {
            if (data[i] > peak)
            {
                cout << data[i] << " ";
            }
        }

        return 0;
    }
    catch (invalid_argument e)
    {
        cout << e.what();
    }
}