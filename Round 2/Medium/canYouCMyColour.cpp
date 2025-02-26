/*
    Name: canYouCMyColour

    Author: Harshit Vootukuri

    Difficulty: Medium

    Round:

    Test Case Description:
      The input for this question is a 24-bit binary number N.

    Constraints:
      N should only contain 0's and 1's.
      Length of N should be exactly 24.
*/
/*
    Logic:
        The given 24-bit binary number is split into three 8-bit binary numbers which will represent the RGB values of a colour.
        The complement of the colour is calculated and is represented in CMY colour format.

    Sample Input:
        111111110000000000000000


    Sample Output:
        1 0 0
*/
/*
    Edge Cases:
      Input 1:
        111111110000000000000000
      Output 1:
        1.0000 0.0000 0.0000
      Input 2:
        111111111111111111111111
      Output 2:
        1.0000 1.0000 1.0000
      Input 3:
        000000000000000000000000
      Output 3:
        0.0000 0.0000 0.0000
      Input 4:
        101010101010101010101010
      Output 4:
        0.6667 0.6667 0.6667
      Input 5:
        100000001000000010000000
      Output 5:
        0.5020 0.5020 0.5020

*/

#include <iostream>
#include <string>
#include <bitset>
#include <vector>
#include <iomanip>

int main()
{

  std::string inp;
  std::cin >> inp;
  try
  {
    if (inp.length() != 24)
    {
      throw std::runtime_error("Invalid input length");
    }
    for (char &c : inp)
    {
      if (c != '1' && c != '0')
      {
        throw std::runtime_error("Invalid Input Format");
      }
    }
    std::vector<unsigned char> bytes;
    for (int i = 0; i < 24; i += 8)
    {
      bytes.push_back(static_cast<unsigned char>(std::bitset<8>(inp.substr(i, 8)).to_ulong()));
    }
    std::vector<float> cmy_values;
    for (int i = 0; i < 3; i++)
    {
      cmy_values.push_back(1.0f - ((255 - static_cast<float>(bytes[i])) / 255.0f));
    }

    std::cout << std::fixed << std::setprecision(4);
    std::cout << cmy_values[0] << " " << cmy_values[1] << " " << cmy_values[2];
  }
  catch (const std::exception &e)
  {
    std::cerr << "Invalid Input. Please look at the question description. Errors/Exception cases need not be handled in your solution." << std::endl;
    return -1;
  }
  return 0;
}