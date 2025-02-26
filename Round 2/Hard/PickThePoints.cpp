/*
    Name: PickThePoints

    Author: Adheesh Garg

    Difficulty: Medium

    Round:

    Test Case Description:  Single line input with 8 space-separated integers.

    Constraints:  Each integer should be in range [-32768, 32767].

*/

/*
    Logic: The 8 integer inputs are the coordinates of the 4 vertices, for each triangle formed by the 4 vertices we take the number of points enclosed inside it, the output is the max among all

    Sample Input: 1 4 9 16 25 36 49 64

    Sample Output: 37
*/

/*
    Edge Cases:

    Input1: 0 0 0 0 0 0 0 0
    Output1: 0

    Input2: 32767 32767  32767 -32767  -32767 -32767  -32767 32767
    Output2: 2147254278

    Input3: 0 0  1 1  2 2  3 3
    Output3: 0

    Input4: 32766 32766 32767 32765 32765 32766 32766 32765
    Output4: 0

    Input5: 0 0 0 1 1 1 1 0
    Output5: 0

*/

#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <numeric>
#include <algorithm>


bool read_eight_integers(std::vector<int> &points)
{
    std::string line;
    if (!std::getline(std::cin, line))
        return false;
    std::istringstream iss(line);
    for (std::string token; iss >> token;)
    {
        try
        {
            int value = std::stoi(token);
            if (value < -(1 << 15) || value >= (1 << 15))
            {
                std::cerr << "Error: Input integer out of range.\n";
                return false;
            }
            points.push_back(value);
        }
        catch (...)
        {
            return false;
        }
    }
    return points.size() == 8;
}

double triangle_area(int x1, int y1, int x2, int y2, int x3, int y3)
{
    double s = 0.0;
    s += static_cast<double>(x1) * (static_cast<double>(y2) - static_cast<double>(y3));
    s += static_cast<double>(x2) * (static_cast<double>(y3) - static_cast<double>(y1));
    s += static_cast<double>(x3) * (static_cast<double>(y1) - static_cast<double>(y2));
    return std::fabs(s) / 2.0;
}

int integer_points_in_triangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    double area = triangle_area(x1, y1, x2, y2, x3, y3);
    if (area == 0.0)
        return 0;
    int b1 = std::gcd(std::abs(x2 - x1), std::abs(y2 - y1));
    int b2 = std::gcd(std::abs(x3 - x2), std::abs(y3 - y2));
    int b3 = std::gcd(std::abs(x1 - x3), std::abs(y1 - y3));
    return std::floor(area - (b1 + b2 + b3) / 2.0 + 1.0);
}

int main()
{

    std::vector<int> points;
    if (!read_eight_integers(points))
    {
        std::cerr << "Error: Please enter exactly 8 space-separated integers in the range [-32768, 32767].\n";
        return 1;
    }
    std::vector<std::pair<int, int>> coords;
    for (int i = 0; i < 8; i += 2)
        coords.push_back({points[i], points[i + 1]});
    int max_points = 0;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = i + 1; j < 4; ++j)
        {
            for (int k = j + 1; k < 4; ++k)
            {
                max_points = std::max(max_points, integer_points_in_triangle(
                                                      coords[i].first, coords[i].second,
                                                      coords[j].first, coords[j].second,
                                                      coords[k].first, coords[k].second));
            }
        }
    }
    std::cout << max_points << std::endl;
    return 0;
}
