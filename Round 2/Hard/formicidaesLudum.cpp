/*
    Name: formicidaesLudum

    Author: Harshit Vootukuri

    Difficulty: Hard

    Round:

    Test Case Description:
        The first line of input consists of four space-seperated integers T x y N, where (x,y) are two dimensional coordinates
        The following "N" lines of input consist of two space-seperated integers X Y, where (X,Y) are two dimensional coordinates

    Constraints:
        T: 0 to 1000 (inclusive)
        x: -2147483648 to 2147483647
        y: -2147483648 to 2147483647
        N: 0 to 10 (inclusive)
        X: -2147483648 to 2147483647
        Y: -2147483648 to 2147483647
        X != x
        Y != y
*/
/*
Logic:
    This problem is a modified version of Langton's Ant with obstacles.

    Langton's Ant is a cellular automaton which is similar to Conway's Game of Life that moves on a grid with a simple set of rules.
    The ant starts on a cell, and at each step, it first looks at the color of its current cell.
    If the cell is white (or initially unvisited), the ant turns left (counterclockwise), flips the cell's color to black, and tries to move forward one cell.
    If the cell is black, the ant turns right (clockwise), flips the cell back to white, and tries to move forward.

    In this problem, the participant is required to calculate the position of the ant after T steps,
    where the ant starts from the initial position (x,y) and there are a total of N obstacles at (X,Y)

Sample Input:
    2 0 0 1
    -1 0


Sample Output:
    0 1
*/

/*
    Edge Cases:
        Input 1:
            1000 2147483646 -2147483647 1
            2147483645 -2147483647
        Output 1:
            -2147483643 2147483642

        Input 2:
            0 -2147483647 2147483646 10
            -2147483646 2147483646
            -2147483647 2147483645
            -2147483646 2147483645
            -2147483648 2147483646
            -2147483647 2147483644
            -2147483646 2147483644
            -2147483645 2147483646
            -2147483645 2147483645
            -2147483645 2147483644
            -2147483644 2147483646
        Output 2:
            -2147483647 2147483646
        Input 3:
            1 0 0 4
            1 0
            0 1
            -1 0
            0 -1
        Output 3:
            0 0
        Input 4:
            500 2147483646 2147483646 10
            2147483645 2147483646
            2147483646 2147483645
            2147483645 2147483645
            2147483644 2147483646
            2147483646 2147483644
            2147483644 2147483644
            2147483643 2147483646
            2147483646 2147483643
            2147483643 2147483643
            2147483642 2147483646
        Output 4:
            2147483644 2147483645
        Input 5:
            750 -2147483647 -2147483647 10
            -2147483646 -2147483647
            -2147483647 -2147483646
            -2147483646 -2147483646
            -2147483645 -2147483647
            -2147483647 -2147483645
            -2147483645 -2147483645
            -2147483644 -2147483647
            -2147483647 -2147483644
            -2147483644 -2147483644
            -2147483643 -2147483647
        Output 5:
            -2147483647 -2147483647
*/

#include <iostream>
#include <vector>
#include <set>
#include <utility>

int main()
{
    try
    {
        int t, initX, initY, numObstacles;
        if (!(std::cin >> t >> initX >> initY >> numObstacles))
        {
            throw std::runtime_error("Invalid input format");
        }

        if (t < 0 || numObstacles < 0 || t > 1000 || numObstacles > 10)
        {
            throw std::runtime_error("Input not in mentioned range");
        }

        std::set<std::pair<int, int>> obstacles;
        for (int i = 0; i < numObstacles; ++i)
        {
            int x, y;
            if (!(std::cin >> x >> y))
            {
                throw std::runtime_error("Invalid input");
            }

            if (x == initX && y == initY)
            {
                throw std::runtime_error("Invalid obstacle coordinates");
            }

            obstacles.insert({x, y});
        }

        int direction = 0;
        int x = initX, y = initY;
        std::set<std::pair<int, int>> whiteCells;

        for (int step = 0; step < t; ++step)
        {
            std::pair<int, int> currentCell = {x, y};

            // Determine if the current cell is white or black
            bool isWhite = whiteCells.count(currentCell);

            // Turn and flip the color of the cell
            if (isWhite)
            {
                direction = (direction + 1) % 4;
                whiteCells.erase(currentCell);
            }
            else
            {
                direction = (direction + 3) % 4;
                whiteCells.insert(currentCell);
            }

            // Store the current position
            int newX = x, newY = y;

            // Calculate next position
            switch (direction)
            {
            case 0:
                newY++;
                break;
            case 1:
                newX++;
                break;
            case 2:
                newY--;
                break;
            case 3:
                newX--;
                break;
            }

            // Only move if there's no obstacle
            if (!obstacles.count({newX, newY}))
            {
                x = newX;
                y = newY;
            }
        }

        std::cout << x << " " << y << std::endl;
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Invalid Input. Please look at the question description. Errors/Exception cases need not be handled in your solution." << std::endl;
        return 1;
    }
}