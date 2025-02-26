#include <iostream>
#include <vector>
#include <string>

/*
    Name: myCousinsNameIsOlefin

    Author: Mahendra Sajjan Choudhary

    Difficulty: Medium

    Round: RC 25

    Test Case Description:
        The first line of input contains a single integer n.
        The second line of input contains a single integer p.

    Constraints:
        - n: 6 to 100
        - p: 1 to n-1
*/

/*
    Logic:
        - If numCarbons is less than or equal to 5, return "Invalid Input".
        - If doubleBondPosition is out of the valid range, return "Invalid Input".
        - Initialize all internal carbons with 2 hydrogens.
        - The first and last carbons have 3 hydrogens unless they are involved in the double bond.
        - Adjust hydrogen count for the carbons involved in the double bond (reduce by 1 for each).
        - If any carbon has a negative hydrogen count, return "Invalid Input".
        - Construct and return the hydrogen count as a string for each carbon in the chain.

    Sample Input:
        6
        2

    Sample Output:
        321222
*/

/*
    Edge Cases:
    - Edge Case 1:
        Input1: 6 1
        Output1: 221223
        Description: Double bond at the beginning of the chain.
    - Edge Case 2:
        Input2: 6 5
        Output2: 322221
        Description: Double bond at the end of the chain.
    - Edge Case 3:
        Input3: 7 3
        Output3: 3222122
        Description: Double bond in the middle of a longer chain.
    - Edge Case 4:
        Input4: 95 94
        Output4: 32222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222212
    - Edge Case 5:
        Input5: 100 99
        Output5: 3222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222212
*/

std::string carbonChainWithDoubleBond(int numCarbons, int doubleBondPosition)
{
    if (numCarbons <= 5)
    {
        return "Invalid Input. Please look at the question description. Errors/Exception cases need not be handled in your solution."; // Chain must have more than 5 carbons
    }
    if (doubleBondPosition < 1 || doubleBondPosition >= numCarbons)
    {
        return "Invalid Input. Please look at the question description. Errors/Exception cases need not be handled in your solution."; // Double bond position must be within valid range
    }

    // Initialize hydrogens: 2 for internal, 3 for terminal carbons
    std::vector<int> hydrogens(numCarbons, 2);
    hydrogens[0] = 3;              // First carbon has 3 hydrogens unless it has a double bond
    hydrogens[numCarbons - 1] = 3; // Last carbon has 3 hydrogens unless it has a double bond

    // Adjust hydrogen count for double bond
    hydrogens[doubleBondPosition - 1] -= 1;
    hydrogens[doubleBondPosition] -= 1;

    // Validate hydrogen counts
    for (int h : hydrogens)
    {
        if (h < 0)
        {
            return "Invalid Input. Please look at the question description. Errors/Exception cases need not be handled in your solution."; // Negative hydrogen count is not valid
        }
    }

    // Construct result string
    std::string result;
    for (int h : hydrogens)
    {
        result += std::to_string(h);
    }
    return result;
}

int main()
{

    int numCarbons, doubleBondPosition;

    // Taking inputs
    std::cin >> numCarbons;
    std::cin >> doubleBondPosition;

    // Get the result
    std::string result = carbonChainWithDoubleBond(numCarbons, doubleBondPosition);

    // Output the result
    std::cout << result << std::endl;

    return 0;
}
