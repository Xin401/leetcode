#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> group;
        for (const auto &s : strs)
        {
            vector<int> count(26, 0);
            for (const auto &c : s)
            {
                count[c - 'a']++;
            }
            string key = "";
            for (const auto &c : count)
            {
                key += to_string(c) + "#";
            }
            group[key].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto &pair : group)
        {
            result.push_back(pair.second);
        }
        return result;
    }
};
int main()
{
    Solution sol;
    vector<string> strs = {"bdddddddddd", "bbbbbbbbbbc"};
    sol.groupAnagrams(strs);
}