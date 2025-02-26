/*
    Name: Queens_gambit

    Author: Navdha Sharma

    Difficulty: hard

    Round:

    Test Case Description:
    line 1: (x,y)
    line 2: (x,y)

    Constraints:
    x should be between 1 to 8.
    y should be between A to H.(both capital)


/*

    Logic:In this problem, we take input the position of queen and knight respectively.
    The code will return the number of coincidences in the possible moves of queen and knightin a single move.

    Sample Input:
    line 1:2,A
    line 2:3,C
    Sample Output:4

*/

/*
    Edge Cases:

    Input1:
    4,G
    4,G
    Output1:0

    Input2:
    1,A
    8,G
    Output2:1

    Input3:
    2,A
    3,A
    Output3:3

    Input4:
    2,F
    3,C
    Output4:2

    Input5:
    4,D
    5,A
    Output5:1

*/

#include <iostream>
#include <vector>
#include <set>
#include <sstream>
using namespace std;
bool isValid(int x, int y, int n)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}
vector<pair<int, int>> knightMoves(int x, int y, int n)
{
    vector<pair<int, int>> moves;
    int knightMoves[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    for (int i = 0; i < 8; i++)
    {
        int nx = x + knightMoves[i][0];
        int ny = y + knightMoves[i][1];
        if (isValid(nx, ny, n))
        {
            moves.push_back({nx, ny});
        }
    }
    return moves;
}
vector<pair<int, int>> queenMoves(int x, int y, int n)
{
    vector<pair<int, int>> moves;
    for (int i = 0; i < n; i++)
    {
        if (i != x)
            moves.push_back({i, y});
        if (i != y)
            moves.push_back({x, i});
    }
    for (int i = 1; i < n; i++)
    {
        if (isValid(x + i, y + i, n))
            moves.push_back({x + i, y + i});
        if (isValid(x - i, y - i, n))
            moves.push_back({x - i, y - i});
        if (isValid(x + i, y - i, n))
            moves.push_back({x + i, y - i});
        if (isValid(x - i, y + i, n))
            moves.push_back({x - i, y + i});
    }

    return moves;
}

int main()
{

    string queenInput, knightInput;
    const int boardSize = 8;
    cin >> queenInput;
    cin >> knightInput;
    int queenRow, queenCol;
    stringstream queenSS(queenInput);
    string queenRowStr, queenColStr;

    if (getline(queenSS, queenRowStr, ',') && getline(queenSS, queenColStr))
    {
        queenRow = stoi(queenRowStr);
        queenCol = queenColStr[0] - 'A';
    }
    else
    {
        cout << "ERROR :you need not handle such cases in your code.\n";
        return 1;
    }
    int knightRow, knightCol;
    stringstream knightSS(knightInput);
    string knightRowStr, knightColStr;

    if (getline(knightSS, knightRowStr, ',') && getline(knightSS, knightColStr))
    {
        knightRow = stoi(knightRowStr);
        knightCol = knightColStr[0] - 'A';
    }
    else
    {
        cout << "ERROR :you need not handle such cases in your code.\n";
        return 1;
    }

    if (queenRow < 1 || queenRow > 8 || queenCol < 0 || queenCol > 7 ||
        knightRow < 1 || knightRow > 8 || knightCol < 0 || knightCol > 7)
    {
        cout << "ERROR :you need not handle such cases in your code.\n";
        return 1;
    }
    int qRow = queenRow - 1;
    int qCol = queenCol;
    int kRow = knightRow - 1;
    int kCol = knightCol;
    vector<pair<int, int>> knightPos = knightMoves(kRow, kCol, boardSize);
    vector<pair<int, int>> queenPos = queenMoves(qRow, qCol, boardSize);
    set<pair<int, int>> knightSet(knightPos.begin(), knightPos.end());
    set<pair<int, int>> queenSet(queenPos.begin(), queenPos.end());

    int coincidences = 0;
    for (const auto &move : knightSet)
    {
        if (queenSet.find(move) != queenSet.end())
        {
            coincidences++;
        }
    }

    cout << coincidences << endl;

    return 0;
}
