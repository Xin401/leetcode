#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        vector<int> count(26, 0);
        for (int i = 0; i <= s.length() - 1; i++)
        {
            count[s[i] - 'a'] += 1;
            count[t[i] - 'a'] -= 1;
        }
        for (const auto &n : count)
        {
            if (n != 0)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string s = "anagram", t = "nagaram";
    cout << boolalpha << sol.isAnagram(s, t);
}