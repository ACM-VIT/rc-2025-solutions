/*
    Name: sayAgain

    Author: Rishit Shivam

    Difficulty: Hard

    Round:

    Test Case Description:
    The first line of input contains a positive integer n,
    THe second line of input contains a string s.

    Constraints:
    - n is between 1 and 100.
    - The string contains only characters from 'a' to 'i'.
*/

/*
    Logic:
    The program prints the Look-and-Say sequence up to the nth term with character mapping.
    The numbers are mapped from 1:a, 2:b, 3:c, ..., 9:i.
    Other input characters are to be omitted.

    Sample Input:
    3
    abccde

    Sample Output:
    aaabbcadae
    cabbacaaadaaae
    acaabbaaaccaadcaae
*/

/*
    Edge Cases:

    Input1: 2
            bhaaage
    Output1: abahcaagae
             aaabaaahacbaagaaae

    Input2: 4
            baddad
    Output2: abaabdaaad
             aaabbaabadcaad
             cabbbaabaaadacbaad
             acaacbbaabcaadaaacabbaad

    Input3: 6
            chaddi
    Output3: acahaabdai
             aaacaaahbaabadaaai
             caaccaahabbaabaaadcaai
             acbabcbaahaabbbaabcaadacbaai
             aaacabaaabacabbaahbacbbaabacbaadaaacabbaai
             caacaaabcaabaaacaabbbaahabaaacbbbaabaaacabbaadcaacaabbbaai

    Input4: 8
            hhhhhgiacdddbb
    Output4: ehagaiaaaccdbb
             aeahaaagaaaicabcadbb
             aaaeaaahcaagcaaiacaaabacaaadbb
             caaecaahacbaagacbaaiaaaccaabaaaccaadbb
             acbaaeacbaahaaacabbaagaaacabbaaicabcbaabcabcbaadbb
             aaacabbaaeaaacabbaahcaacaabbbaagcaacaabbbaaiacaaabacabbaabacaaabacabbaadbb
             caacaabbbaaecaacaabbbaahacbaacbacbbaagacbaacbacbbaaiaaaccaabaaacaabbbaabaaaccaabaaacaabbbaadbb
             acbaacbacbbaaeacbaacbacbbaahaaacabbaacabaaacbbbaagaaacabbaacabaaacbbbaaicabcbaabcaacbacbbaabcabcbaabcaacbacbbaadbb

    Input5: 5
            bbcbbcidadhd
    Output5: bbacbbacaiadaaadahad
             bbaaacbbaaacaaaiaaadcaadaaahaaad
             bbcaacbbcaaccaaicaadacbaadcaahcaad
             bbacbaacbbacbabcbaaiacbaadaaacabbaadacbaahacbaad
             bbaaacabbaacbbaaacabaaabacabbaaiaaacabbaadcaacaabbbaadaaacabbaahaaacabbaad

*/

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>


using namespace std;

const size_t MAX_STRING_LENGTH = 1000000; // Reasonable limit for string length

string nextTermWithMapping(const string &term)
{
    if (term.empty())
        return "";
    string result;
    result.reserve(2 * term.length()); // Pre-allocate space
    int count = 1;

    for (size_t i = 1; i < term.length(); ++i)
    {
        if (result.length() > MAX_STRING_LENGTH)
        {
            throw runtime_error("Result too large");
        }
        if (term[i] == term[i - 1])
        {
            count++;
        }
        else
        {
            result += (char)('a' + ((count - 1) % 9));
            result += term[i - 1];
            count = 1;
        }
    }
    result += (char)('a' + ((count - 1) % 9));
    result += term.back();

    return result;
}

vector<string> lookAndSaySequenceWithMapping(int n, const string &startTerm)
{
    vector<string> sequence;
    sequence.reserve(n); // Pre-allocate space
    string term = startTerm;

    for (int i = 0; i < n && term.length() <= MAX_STRING_LENGTH; ++i)
    {
        term = nextTermWithMapping(term);
        sequence.push_back(term);
    }

    return sequence;
}

void validateInput(int n, const string &startTerm)
{
    if (n < 1 || n > 100)
    {
        throw invalid_argument("Invalid n value");
    }
    if (startTerm.empty() || startTerm.length() > MAX_STRING_LENGTH)
    {
        throw invalid_argument("Invalid string length");
    }
    for (char c : startTerm)
    {
        if (c < 'a' || c > 'i')
        {
            throw invalid_argument("Invalid character in string");
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    try
    {
        int n;
        string startTerm;

        if (!(cin >> n >> startTerm))
        {
            throw invalid_argument("Input error");
        }

        validateInput(n, startTerm);

        vector<string> sequence = lookAndSaySequenceWithMapping(n, startTerm);

        for (const string &term : sequence)
        {
            cout << term << '\n';
        }
        cout.flush();
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}