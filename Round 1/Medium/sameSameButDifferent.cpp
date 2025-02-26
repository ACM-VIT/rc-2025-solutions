/*
    Name: sameSameButDifferent

    Author: Vanshika Garg

    Difficulty: Medium

    Round:

    Test Case Description: String input.

    Constraints: String length must be between 2 to 1000.

/*
/*
Logic:
    You have to input a string of your choice, and then print the number of substring pairs that are anagrams of each other.
Sample Input:
    abba

Sample Output:
    2 (it's two because: ab-ba;abb-bba the pairs are anagrams of each other.)
*/

/*
    Edge Cases:

    Input1:
        reverse
    Output1:
        6

    Input2:
        cuckoo

    Output2:
       1
    Input3:
        computing
    Output3:
       0
    Input4:
        mississippi
    Output4:
        25
    Input5:
        mercedes
    Output5:
       3
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

int countAnagramSubstrings(const std::string &str)
{
    int n = str.length();
    int count = 0;

    // Try all possible substring lengths from 2 to n
    for (int len = 2; len <= n; len++)
    {
        // Map to store sorted substring frequency
        std::unordered_map<std::string, int> substringCount;

        // Generate all substrings of current length
        for (int i = 0; i <= n - len; i++)
        {
            // Extract and sort the substring
            std::string substring = str.substr(i, len);
            std::string sortedSubstring = substring;
            std::sort(sortedSubstring.begin(), sortedSubstring.end());

            // Add to map
            substringCount[sortedSubstring]++;
        }

        // Count anagram pairs for current length
        for (const auto &pair : substringCount)
        {
            if (pair.second > 1)
            {
                count += (pair.second * (pair.second - 1)) / 2;
            }
        }
    }

    return count;
}

int main()
{

    std::string inp;

    // Take input
    std::cin >> inp;

    int result = countAnagramSubstrings(inp);

    // Print output
    std::cout << result << std::endl;

    return 0;
}
