#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string customSortString(string order, string s)
    {
        int count[26] = {0};
        for (char c : s)
        {
            count[c - 'a']++;
        }
        string result = "";
        for (char c : order)
        {
            while (count[c - 'a'] > 0)
            {
                result += c;
                count[c - 'a']--;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            while (count[i] > 0)
            {
                result += (char)('a' + i);
                count[i]--;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.customSortString("cba", "abcd") << endl;
    return 0;
}