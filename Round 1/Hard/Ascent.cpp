
// Name: Ascent
// Author: P G Ghautham Arveen
// Difficulty: Hard
// Round:
// Test Case Description: A positive integer n followed by n*n space separated integers
// Constraints: 1<=n<=25
// a[i][j] <= 1000
// Logic:
// The points are connected by edges. We need to find the number of steps to reach the highest point from the lowest point.
// We can move only to a point that is higher than the current point.
// We can move only in the 4 directions: up, down, left, right. We need to find the number of steps to reach the highest point from the lowest point.

// Sample Input 1:
// 4
// 1 4 3 4
// 4 65 6 5
// 7 89 91 345
// 75 8 9 314
// Sample Output 1:
// 5

// Sample Input 2:
// 2
// 1 2
// 3 4
// Sample Output 2:
// 2

/*
    Edge Cases:

    Input1: 1
            999
    Output1: 0
    Explanation: Hinting at counter logic (counter is 0 prod is 0).

    Input2: 25
    57 156 248 306 402 185 112 283 438 497 298 660 148 725 34 763 590 636 923 754 572 906 633 73 914
    72 150 48 422 612 235 893 383 75 395 102 862 642 375 214 917 773 404 656 461 980 469 221 461 531
    35 36 383 56 646 305 740 96 446 952 548 703 837 341 202 57 720 296 260 94 198 262 716 287 710
    582 778 448 646 654 222 804 873 119 890 510 470 202 918 476 468 419 430 424 538 71 79 181 440 497
    302 643 820 566 740 970 704 758 411 155 558 951 489 982 860 629 713 723 404 723 889 573 194 49 533
    821 876 839 147 711 976 984 218 219 770 37 818 964 395 188 88 788 288 950 874 196 649 575 38 727
    758 281 363 415 761 419 995 956 695 148 768 492 83 454 754 886 806 339 515 641 830 426 18 918 432
    443 188 287 63 441 804 993 210 769 564 163 693 971 788 158 522 918 195 820 426 448 670 894 939 582
    346 404 311 481 518 93 143 208 337 58 659 698 189 35 609 272 854 51 377 394 786 726 435 820 100
    92 470 364 923 349 275 322 331 839 729 26 667 628 562 616 398 782 387 317 110 402 856 246 114 530
    231 798 986 213 167 982 703 132 685 545 348 259 462 316 39 666 925 774 287 846 309 201 942 629 42
    678 286 937 22 151 750 875 572 246 544 148 460 870 694 175 111 379 58 20 839 921 898 216 232 470
    666 557 766 233 568 742 22 989 484 691 435 489 638 397 354 228 560 94 736 568 371 281 298 283 547
    119 268 985 420 673 349 191 398 737 594 690 656 390 194 19 303 852 785 712 564 405 571 984 878 973
    981 980 499 558 990 45 312 79 996 15 270 534 341 846 406 384 962 963 109 765 770 402 274 151 282
    367 258 466 703 608 490 832 638 729 719 232 49 939 862 575 253 462 282 598 947 459 300 312 575 2
    502 128 373 133 301 256 429 411 59 523 91 474 512 59 353 302 790 530 720 942 544 694 676 948 632
    690 561 748 388 61 752 742 348 572 220 67 389 234 276 734 273 227 144 32 734 235 909 372 919 700
    373 20 956 290 825 487 355 980 275 267 395 649 704 580 950 458 669 83 311 586 57 903 994 238 178
    568 854 2 326 629 384 203 18 265 312 586 368 631 291 785 21 627 637 55 132 855 547 810 827 463
    94 127 883 492 744 990 671 487 485 857 174 562 746 217 281 529 138 97 948 939 453 937 434 769 538
    641 704 79 520 561 854 616 5 60 335 213 689 47 214 811 536 61 235 174 220 814 558 645 194 634
    900 64 288 669 943 295 641 887 670 621 244 635 408 857 431 98 519 539 451 309 553 353 430 966 859
    167 839 311 891 456 537 826 230 727 434 938 606 434 646 990 580 102 709 632 891 168 397 520 973 118
    876 885 195 558 507 518 582 1000 659 213 618 348 914 475 873 662 981 53 418 601 404 62 90 520 672
    Output2: 11940
    Explanation: Giving a very large matrix to ensure the correct logic is implemented.

    Input3: 3
    1 1 1
    1 1 1
    1 1 1
    Output3: 0
    Explanation: All elements are same. So, no steps needed.

    Input4: 3
    1 2 3
    4 5 6
    7 8 9
    Output4: 36
    Explanation: Ensuring proper traversal.

    Input5: 3
    1 4 12
    4 4 4
    15 4 4
    Output5: 30
    Explanation: Order of top, bottom, right, left matters.
*/

#include <iostream>
#include <vector>
using namespace std;

int countStepsToHighestPoint(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int x = 0, y = 0;
    int value = matrix[0][0];
    int steps = 0;

    // Define the directions for top, bottom, left, and right
    vector<pair<int, int>> directions;
    directions.push_back(make_pair(-1, 0)); // Up
    directions.push_back(make_pair(1, 0));  // Down
    directions.push_back(make_pair(0, -1)); // Left
    directions.push_back(make_pair(0, 1));  // Right

    while (true)
    {
        int current_value = matrix[x][y];
        int next_x = x, next_y = y;

        // Use a normal iteration loop
        for (int i = 0; i < directions.size(); ++i)
        {
            int dx = directions[i].first;
            int dy = directions[i].second;

            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && matrix[nx][ny] > current_value)
            {
                current_value = matrix[nx][ny];
                next_x = nx;
                next_y = ny;
            }
        }

        if (next_x == x && next_y == y)
        {
            break;
        }

        x = next_x;
        y = next_y;
        steps++;
        value = matrix[x][y];
    }

    return steps * value;
}

int main()
{

    try
    {
        int n;
        cin >> n;

        if (n <= 0 || n > 50)
        {
            throw invalid_argument("Invalid input for matrix size. Error cases need not be handled in your solution.");
        }

        vector<vector<int>> matrix(n, vector<int>(n));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> matrix[i][j];
                if (matrix[i][j] < 0 || matrix[i][j] > 1000)
                {
                    throw invalid_argument("Invalid input for matrix elements. Error cases need not be handled in your solution.");
                }
            }
        }

        int steps = countStepsToHighestPoint(matrix);
        cout << steps << endl;
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}