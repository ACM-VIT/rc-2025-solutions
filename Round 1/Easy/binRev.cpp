/*
    Name: binRev

    Author: Harshit Narang

    Difficulty: Easy

    Round: Round 1

    Test Case Description:
    This program takes a single integer as input.

    Constraints:
    - Input must be a positive integer.
    - The input integer should be between 1 and 500 (inclusive).

/*
    Logic:
    - The input number is first converted to its binary representation.
    - The binary string is then reversed.
    - The reversed binary string is converted back to an integer and returned.

    Sample Input:
    10

    Sample Output:
    5

    Explanation:
    - The binary representation of 10 is "1010".
    - The binary string is reversed to "0101".
    - The reversed binary string is then converted back to decimal: 5.

*/

/*
    Edge Cases:

    Input1: 1
    Output1: 1
    Explanation: Binary of 1 is "1", reversed binary is "1".

    Input2: 500
    Output2: 95
    Explanation: Binary of 500 is "111110100", reversed binary is "001011111" which converts to decimal 95.

    Input3: 15
    Output3: 15
    Explanation: Binary of 15 is "1111", reversed binary is "1111".

    Input4: 128
    Output4: 1
    Explanation: Binary of 128 is "10000000", reversed binary is "00000001".

    Input5: 255
    Output5: 255
    Explanation: Binary of 255 is "11111111", reversed binary is "11111111".
*/


#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>
#include <limits>

// Function to reverse the binary representation and return the new value
int reverseBinary(int input)
{
    // Convert the input to binary string
    std::string binary = std::bitset<32>(input).to_string();

    // Remove leading zeros from the binary representation
    binary.erase(0, binary.find_first_not_of('0'));

    // Reverse the binary string
    std::reverse(binary.begin(), binary.end());

    // Convert the reversed binary string back to an integer
    int reversedValue = 0;
    int base = 1; // For binary to decimal conversion

    for (int i = binary.size() - 1; i >= 0; --i)
    {
        if (binary[i] == '1')
        {
            reversedValue += base;
        }
        base *= 2;
    }

    return reversedValue;
}

int main()
{
   
    int input;

    // Ask the user for input
    // Check if the input is valid and within the required range
    while (true)
    {
        std::cin >> input;

        // Check if the input is a valid integer
        if (std::cin.fail())
        {
            // Clear the error flag and ignore the incorrect input
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid input! Please enter a valid integer. You need not handle such cases in your code." << std::endl;

            continue;
        }

        // Check if the input is within the valid range (1 to 500)
        if (input < 1 || input > 500)
        {
            std::cerr << "Input out of range! Please enter a number between 1 and 500.You need not handle such cases in your code." << std::endl;

            continue;
        }

        break; // Exit the loop if input is valid
    }

    // Display the output
    std::cout << reverseBinary(input) << std::endl;

    return 0;
}
