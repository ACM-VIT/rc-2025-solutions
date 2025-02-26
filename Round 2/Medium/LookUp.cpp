/*
    Name: LookUp

    Author: Rohit Phaniram Sakamuri

    Difficulty: Medium

    Round: TBD

    Test Case Description:
    The input consists of space separated integers.

    Test Case Description:
    The input consists of n space separated integers.

    Constraints:
    At least one integer must be input. Only the first 10 integers will be considered for compute if more than 10 integers are input. Integers must be non-negative.
    1 <= n <= 10
    Each integer must be non-negative.
    The integer must lie between 0 and 999999 (inclusive).
*/

/*
    Logic:
    Let the number of integers input be N (max 10). Then, for each integer input, the next Nth prime is found and the next Nth primes for each input is output.

    Sample Input:
    0 1 2 3

    Sample Output:
    7 7 11 13
*/

/*
Edge Cases:

Input1: 111 0 2 4 18 11 8 19 66 31 5 69
Output1: 167 29 31 37 59 47 43 61 107 73

Input2: 18 19 42 74
Output2: 31 37 59 97

Input3: 88 18 17 62 8
Output3: 107 37 37 83 23

Input4: 9 99 999 9999 99999 999999
Output4: 29 127 1033 10067 100069 1000099

Input5: 0 0 2 2 19 19
Output5: 13 13 17 17 43 43

*/

#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

bool isPrime(int num)
{
    if (num < 2)
        return false;
    for (int i = 2; i <= std::sqrt(num); ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int NthNextPrime(int num, int N)
{
    int count = 0;
    int candidate = num + 1;

    while (count < N)
    {
        if (isPrime(candidate))
        {
            ++count;
            if (count == N)
                break;
        }
        ++candidate;
    }

    return candidate;
}

int main()
{

    std::string input;
    std::getline(std::cin, input);
    int count;

    std::istringstream iss(input);
    std::vector<int> numbers;
    std::vector<int> outArr;
    int num;

    while (iss >> num)
    {
        if (num < 0)
        {
            std::cerr << "Error: Only non-negative integers are allowed. You need not handle such cases in your code.\n";
            return 1;
        }

        if (num > 9999999)
        {
            std::cerr << "Error: Integers must be between 0 and 999999 (inclusive). You need not handle such cases in your code.\n";
            return 1;
        }

        numbers.push_back(num);
        if (numbers.size() == 10)
            break;
    }

    count = numbers.size() > 10 ? 10 : numbers.size();
    for (int n : numbers)
    {
        outArr.push_back(NthNextPrime(n, count));
    }

    for (int prime : outArr)
    {
        std::cout << prime << " ";
    }
    std::cout << "\n";

    return 0;
}
