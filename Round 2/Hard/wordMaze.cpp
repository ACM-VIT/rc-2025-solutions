/*
    Name: wordMaze

    Author: Prateek Purohit

    Difficulty: Hard

    Round: [Round Info]

    Test Case Description:
    The program takes two input.
    First input contains an integer N.
    Second input contains a string(S) of length N.

    Constraints:
    - Input number should be a positive integer.
    - 1<=N<900
    - 1<=S<N
*/
/*
    Logic:
    - The user needs to find all the pallindromic substrings from the given string and then return the length of the substrings with maximum length among all.
    After this they have to move the first character to the last and repeat the same process. They have to repeat this for N times.

    Sample Input 1:
    7
    pqprrrp

    Sample Output 2:
    5
    5
    5
    3
    3
    3
    3

    Explanations:
    pqprrrp : - prrrp is a pallindrome of length 5, rrr of length 3. as 5>3 output is 5.
    qprrrpp: prrrp is a pallindrome of length 5, rrr of length 3 and pp is a pallindrome of length 2. As 5>3>2 output is 5
    prrrppq: prrrp is a pallindrome of length 5, rrr of length 3 and pp is a pallindrome of length 2. As 5>3>2 output is 5
    rrrppqp: rrr and pqp is a pallindrome of length 3 and pp of length 2. So output is 3.
    rrppqpr: output is 3(pqp).
    rppqprr: output is 3.
    ppqprrr: output is 3.

    Input2: 6 momdad
    Output2: 3 5 5 3 5 5

    Input3: 12 ccfcffccfcfc
    Output3: 5 7 7 7 7 9 9 9 9 7 5 4

    Input4:
    100
    rdhgmadamracecaraibohphobiadadrdhgadiklovjkfsqiwjzdxfjipguuvvcgrxxjfwinfuozapaapprrficlzkqqdvqradarx
    Output4:
    11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 9 7 7 7 7 7 7 7 7 9 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11

    Input 5:
    3
    bob
    Output 5:
    3 2 2

    Input 6:
    1
    x
    Output 6:
    1


*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <stdexcept>

void solve(char *str, int *a);
void init(int n);
void range_increment(int i, int j, int val);
int query(int i);
int max(int x, int y);
void update(int x, int y, int z);
void sort_a2(int *a, int *b, int size);
void merge2(int *a, int *left_a, int *right_a, int *b, int *left_b, int *right_b, int left_size, int right_size);

char S[1000001] = {0};
int tree_size, N, a[2000004], tree[2000000], ans[500000], b[500000], c[500000];

void solve(char *str, int *a)
{
    int len = strlen(str);

    std::vector<char> p(2 * (len + 1));

    for (int i = 0; i < len; i++)
    {
        p[2 * i] = '#';
        p[2 * i + 1] = str[i];
    }
    p[2 * len] = '#';
    p[2 * len + 1] = 0;

    int R = 0, Ri = 0;
    a[0] = R = Ri = 0;

    for (int i = 1; i <= len * 2; i++)
        if (i >= R)
        {
            if (p[i] != '#')
                a[i] = 1;
            else
                a[i] = 0;
            for (int j = i + 1; 1; j++)
                if (j <= 2 * len && 2 * i - j >= 0 && p[j] == p[2 * i - j])
                {
                    if (p[j] != '#')
                        a[i] += 2;
                }
                else
                {
                    Ri = i;
                    R = j - 1;
                    break;
                }
        }
        else
        {
            int mi = 2 * Ri - i;
            if (i + a[mi] >= R || mi == a[mi])
            {
                a[i] = R - i;
                for (int j = R + 1; 1; j++)
                    if (j <= 2 * len && 2 * i - j >= 0 && p[j] == p[2 * i - j])
                    {
                        if (p[j] != '#')
                            a[i] += 2;
                    }
                    else
                    {
                        Ri = i;
                        R = j - 1;
                        break;
                    }
            }
            else
                a[i] = a[mi];
        }
}

void init(int n)
{
    tree_size = 1;
    while (tree_size < n)
        tree_size *= 2;
    int i;
    for (i = 1; i < tree_size + n; i++)
        tree[i] = 0;
}

void range_increment(int i, int j, int val)
{
    for (i += tree_size, j += tree_size; i <= j; i = (i + 1) / 2, j = (j - 1) / 2)
    {
        if (i % 2 == 1)
            tree[i] = max(tree[i], val);
        if (j % 2 == 0)
            tree[j] = max(tree[j], val);
    }
}

int query(int i)
{
    int ans = 0, j;
    for (j = i + tree_size; j; j /= 2)
        ans = max(ans, tree[j]);
    return ans;
}

int max(int x, int y)
{
    return (x > y) ? x : y;
}

void update(int x, int y, int z)
{
    if (z > N)
    {
        int m = x + z / 2;
        if (z % 2)
            if (N % 2)
                update(m - N / 2, m + N / 2, N);
            else
                update(m - N / 2 + 1, m + N / 2 - 1, N - 1);
        else if (N % 2)
            update(m - N / 2, m + N / 2 - 1, N - 1);
        else
            update(m - N / 2, m + N / 2 - 1, N);
    }
    if (y < N)
    {
        range_increment(0, x, z);
        range_increment(y + 1, N - 1, z);
    }
    else
        range_increment(y - N + 1, x, z);
    return;
}

void sort_a2(int *a, int *b, int size)
{
    if (size < 2)
        return;
    int m = (size + 1) / 2;

    std::vector<int> left_a(m);
    std::vector<int> right_a(size - m);
    std::vector<int> left_b(m);
    std::vector<int> right_b(size - m);

    for (int i = 0; i < m; i++)
    {
        left_a[i] = a[i];
        left_b[i] = b[i];
    }
    for (int i = 0; i < size - m; i++)
    {
        right_a[i] = a[i + m];
        right_b[i] = b[i + m];
    }
    sort_a2(left_a.data(), left_b.data(), m);
    sort_a2(right_a.data(), right_b.data(), size - m);
    merge2(a, left_a.data(), right_a.data(), b, left_b.data(), right_b.data(), m, size - m);
}

void merge2(int *a, int *left_a, int *right_a, int *b, int *left_b, int *right_b, int left_size, int right_size)
{
    int i = 0, j = 0;
    while (i < left_size || j < right_size)
    {
        if (i == left_size)
        {
            a[i + j] = right_a[j];
            b[i + j] = right_b[j];
            j++;
        }
        else if (j == right_size)
        {
            a[i + j] = left_a[i];
            b[i + j] = left_b[i];
            i++;
        }
        else if (left_a[i] <= right_a[j])
        {
            a[i + j] = left_a[i];
            b[i + j] = left_b[i];
            i++;
        }
        else
        {
            a[i + j] = right_a[j];
            b[i + j] = right_b[j];
            j++;
        }
    }
}

int main()
{

    try
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::cin >> N >> S;

        // Check for valid N
        if (N < 1)
        {
            throw std::out_of_range("N must be at least 1. You need not handle such cases in your code.");
        }
        if (N > 900)
        {
            throw std::out_of_range("N cannot be greater than 900. You need not handle such cases in your code.");
        }

        // Check string length
        size_t sLength = strlen(S);
        if (sLength < N)
        {
            throw std::length_error("Input string length is less than N. You need not handle such cases in your code.");
        }
        if (sLength > N)
        {
            throw std::length_error("Input string length is greater than N. You need not handle such cases in your code.");
        }

        strncpy(S + N, S, N);
        solve(S, a);
        init(N);

        for (int i = 0; i < 4 * N; i++)
        {
            if (a[i])
            {
                if (i % 2)
                {
                    update(i / 2 - a[i] / 2, i / 2 + a[i] / 2, a[i]);
                }
                else
                {
                    update(i / 2 - a[i] / 2, i / 2 + a[i] / 2 - 1, a[i]);
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            ans[i] = query(i);
            b[i] = ans[i];
            c[i] = i;
        }

        sort_a2(b, c, N);

        for (int i = N - 1; i >= 0; i--)
        {
            for (int j = c[i]; 1; j = (j - 1 + N) % N)
            {
                if (ans[j] - ans[(j - 1 + N) % N] > 2)
                {
                    ans[(j - 1 + N) % N] = ans[j] - 2;
                }
                else
                {
                    break;
                }
            }
            for (int j = c[i]; 1; j = (j + 1) % N)
            {
                if (ans[j] - ans[(j + 1) % N] > 2)
                {
                    ans[(j + 1) % N] = ans[j] - 2;
                }
                else
                {
                    break;
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            std::cout << ans[i] << '\n';
        }

        return 0;
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::length_error &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
        return 1;
    }
}
