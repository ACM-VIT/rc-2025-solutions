/*
    Name: domDomDom

    Author: Harshit Narang

    Difficulty: Medium

    Round: [Round Info]

    Test Case Description:
    The program takes one integer as input.

    Constraints:
    - Input number should be a positive integer.
    - The integer should be between 0 and 100000 (both inclusive).

    Logic:
    - Convert the input number to its word representation using a helper function.
    - Count the number of vowels (case-insensitive) and consonants in the word representation of the number.
    - Output the remainder of consonants divided by vowels.

    Sample Input:
    123

    Sample Output:
    0

    Edge Cases and Explanations:

    Input1: 0
    Output1: 0
    Explanation:
    - Word representation of 0 is "zero."
    - Vowels: 'e', 'o' (Count = 2).
    - Consonants: 'z', 'r' (Count = 2).
    - Remainder: 2 % 2 = 0.

    Input2: 99999
    Output2: 10
    Explanation:
    - Word representation is "ninety-nine thousand nine hundred and ninety-nine."
    - Vowels in "ninety": 'i', 'e' (2).
    - Vowels in "nine": 'i', 'e' (2).
    - Vowels in "thousand": 'o', 'a' ,'u'(3).
    - Vowels in "nine": 'i', 'e' (2).
    - Vowels in "hundred": 'u', 'e' (2).
    - Vowels in "and": 'a' (1).
    - Vowels in "ninety": 'i', 'e' (2).
    - Vowels in "nine": 'i', 'e' (2).
    - Total vowels: 16.
    - Total consonants: 33.
    - Remainder: 26 % 16 = 10.

    Input3: 1
    Output3: 1
    Explanation:
    - Word representation is "one."
    - Vowels: 'o', 'e' (2).
    - Consonants: 'n' (1).
    - Remainder: 1 % 2 = 1.

    Input4: 100000
    Output4: 1
    Explanation:
    - Word representation is "one lakh."
    - Vowels in "one": 'o', 'e' (2).
    - Vowel in "lakh": 'a' (1).
    - Total vowels: 3.
    - Total consonants: 4.
    - Remainder: 4 % 3 = 1.

    Input5: 5000
    Output5: 2
    Explanation:
    - Word representation is "five thousand."
    - Vowels in "five": 'i', 'e' (2).
    - Vowels in "thousand": 'o', 'a' , 'u'(3).
    - Total vowels: 5.
    - Total consonants: 7.
    - Remainder: 7 % 5 = 2.
*/

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <limits>

std::string convertToWords(int num)
{
    std::vector<std::string> below_20 = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                                         "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
                                         "seventeen", "eighteen", "nineteen"};
    std::vector<std::string> tens = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty",
                                     "ninety"};
    std::string hundred = "hundred";
    std::string thousand = "thousand";
    std::string lakh = "lakh";

    if (num == 0)
        return "zero";

    std::string words = "";

    if (num >= 100000)
    {
        words += below_20[num / 100000] + " " + lakh;
        num %= 100000;
        if (num)
            words += " ";
    }

    if (num >= 1000)
    {
        words += convertToWords(num / 1000) + " " + thousand;
        num %= 1000;
        if (num)
            words += " ";
    }

    if (num >= 100)
    {
        words += below_20[num / 100] + " " + hundred;
        num %= 100;
        if (num)
            words += " and ";
    }

    if (num >= 20)
    {
        words += tens[num / 10];
        num %= 10;
        if (num)
            words += "-";
    }
    if (num > 0)
    {
        words += below_20[num];
    }

    return words;
}

int countVowels(const std::string &str)
{
    int count = 0;
    for (char ch : str)
    {
        if (std::tolower(ch) == 'a' || std::tolower(ch) == 'e' ||
            std::tolower(ch) == 'i' || std::tolower(ch) == 'o' ||
            std::tolower(ch) == 'u')
        {
            ++count;
        }
    }
    return count;
}

int countConsonants(const std::string &str)
{
    int count = 0;
    for (char ch : str)
    {
        if (std::isalpha(ch) && !(std::tolower(ch) == 'a' || std::tolower(ch) == 'e' ||
                                  std::tolower(ch) == 'i' || std::tolower(ch) == 'o' ||
                                  std::tolower(ch) == 'u'))
        {
            ++count;
        }
    }
    return count;
}

int main()
{
   
    try
    {
        int number;

        // Input validation for integer
        std::cin >> number;
        if (std::cin.fail())
        {
            throw std::invalid_argument("Invalid input. Please enter a valid integer. You need not handle such cases in your code.");
        }

        // Range validation
        if (number < 0 || number > 100000)
        {
            throw std::out_of_range("Number out of range. Enter a number between 0 and 100000. You need not handle such cases in your code.");
        }

        std::string words = convertToWords(number);
        int vowelCount = countVowels(words);
        int consonantCount = countConsonants(words);

        if (vowelCount == 0)
        {
            throw std::logic_error("Division by zero. No vowels present in the word representation. You need not handle such cases in your code.");
        }

        int result = consonantCount % vowelCount;
        std::cout << result << std::endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const std::logic_error &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred. Please try again. You need not handle such cases in your code." << std::endl;
    }

    return 0;
}
