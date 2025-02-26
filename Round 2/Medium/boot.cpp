/*
    Name: Boot
    Author: Aditya Singh
    Difficulty: Medium
    Round:

    Test Case Description:
    The first line of input consists of two positive integers separated by a space.

    Constraints:
    - The first number must be a positive integer between 0 and 255 (inclusive).
    - The second number must be a positive integer between 0 and 255 (inclusive).

    Logic:
    - Convert both the numbers to its binary representation.
    - binarys is converted to its 2's comliment.
    - the resultant 2's compliment binarys are added.
    - The added binary is converted to decimal then it is the answer.


    Sample Input:
    3 2
    Sample Output:
    507


    Explanation:
    - Binary representation of 3 and 2 is "11" and "10".
    - Converted into 2's compliment "11111110" and "11111101"
    - Added the binary and then represented as a positive integer


    Edge Cases:
    Input1: 3 3
    Output1:
    250
    Explanation: Binary of 1 is "1", single part is "1", AND operation returns "1".

    Input2: 22 56
    Output2:
    434

    Input3: 44 122
    Output3:
    346

    Input4: 244 233
    Output4:
    35

    Input5: 245 254
    Output5:
    13
*/
#include <iostream>
#include <bitset>
#include <cstdint>
#include <string>

std::bitset<8> twosComplement(const std::bitset<8> &binary)
{
    std::bitset<8> ones = binary;
    ones.flip();
    std::bitset<8> twos = ones.to_ulong() + 1;
    return twos;
}

int main()
{


    std::string input1, input2;
    uint8_t num1, num2;

    std::cin >> input1 >> input2;

    // Check for negative inputs
    if (input1.find('-') != std::string::npos || input2.find('-') != std::string::npos)
    {
        std::cout << "Error: Numbers must be between 0 and 255. \nYou need not handle such cases in your code." << std::endl;
        return 1;
    }

    num1 = std::stoi(input1);
    num2 = std::stoi(input2);

    if (num1 > 255 || num2 > 255)
    {
        std::cout << "Error: Numbers must be between 0 and 255. \nYou need not handle such cases in your code." << std::endl;
        return 1;
    }

    std::bitset<8> binary1(num1);
    std::bitset<8> binary2(num2);

    std::bitset<8> twos1 = twosComplement(binary1);
    std::bitset<8> twos2 = twosComplement(binary2);

    std::bitset<16> sum(twos1.to_ulong() + twos2.to_ulong());

    uint16_t result = sum.to_ulong();

    std::cout << result << std::endl;

    return 0;
}
