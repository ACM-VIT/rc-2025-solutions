/*
    Name: listAlchemy
    Author: Prateek Purohit
    Difficulty: Medium

    Test Case Description:
    The input consists of two lines.
    first line contains a positive integer(n).
    second line contains an array of integers of length n.

    CONSTRAINTS:
    10 <= n <= 50

    Logic:
    Given n and an array of n integers, divide the array into subArrays of length m where m is the largest divisor of n. Sort the odd
    positioned subArrays in increasing order and even positioned subArrays in decreasing order. Merge back the array with all the increasing order arrays first followed by the decreasing arrays. Further sort them in order of appearance in initial array.

    eg. n = 15:
    m = 5; make 3 subArrays of length 5;
    Sort the first and third in increasing order, sort the second in decreasing order.
    Print subarray 1, subarray 3, subarray 2;
    eg. n = 16:
    m = 8; make 2 subArrays of length 8;
    Sort the first increasing, the second decreasing.
    Print subarray 1, subarray 2;

    Sample Input 1:
        25
        9 3 1 -2 5 -3 -6 10 40 -738 330 -562 -433 673 -253 574 475 848 31 67 43 94 79 93 66
    Expected Output 1:
        -2 1 3 5 9 -562 -433 -253 330 673 43 66 79 93 94 40 10 -3 -6 -738 848 574 475 67 31

    Sample Input 2:
        10
        -999 864 4 7 65 864 -7 44 56 -9
    Expected Output 2:
        -999 4 7 65 864 864 56 44 -7 -9

    Sample Input 3:
        15
        -7 5 73 33 -100 21 73 998 -18 44 1 69 751 76 -97
    Expected Output 3:
        -100 -7 5 33 73 -97 1 69 76 751 998 73 44 21 -18

    Sample Input 4:
        50
        269 363 77 -4 379 316 -52 256 18 313 352 288 -134 -45 62 410 -183 -196 319 98 -12 -107 -140 -49 14 -99 310 93 456 179 -195 -86 77 159 490 174 392 -24 191 279 2 382 110 354 285 403 -65 404 -119 495
    Sample Output 4:
        -196 -183 -140 -134 -107 -52 -49 -45 -12 -4 14 18 62 77 98 256 269 288 313 316 319 352 363 379 410 495 490 456 404 403 392 382 354 310 285 279 191 179 174 159 110 93 77 2 -24 -65 -86 -99 -119 -195

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    try
    {
        if (n < 10 || n > 50)
        {
            throw out_of_range("Array size must be between 10 and 50. You need not handle such cases in your code");
        }

        int m;
        for (int i = n / 2; i >= 1; i--)
        {
            if (n % i == 0)
            {
                m = i;
                break;
            }
        }
        vector<vector<int>> subArrays;
        for (int i = 0; i < n; i += m)
        {
            vector<int> subArray(arr.begin() + i, arr.begin() + i + m);
            subArrays.push_back(subArray);
        }
        vector<vector<int>> oddSubArrays, evenSubArrays;
        int subArrayCounter = 0;
        for (int i = 0; i < subArrays.size(); i++)
        {
            if (subArrayCounter % 2 == 0)
            {
                sort(subArrays[i].begin(), subArrays[i].end());
                oddSubArrays.push_back(subArrays[i]);
            }
            else
            {
                sort(subArrays[i].rbegin(), subArrays[i].rend());
                evenSubArrays.push_back(subArrays[i]);
            }
            subArrayCounter++;
        }
        vector<int> finalArray;
        for (const auto &subArray : oddSubArrays)
        {
            finalArray.insert(finalArray.end(), subArray.begin(), subArray.end());
        }
        for (const auto &subArray : evenSubArrays)
        {
            finalArray.insert(finalArray.end(), subArray.begin(), subArray.end());
        }
        for (int num : finalArray)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    catch (const out_of_range &e)
    {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}