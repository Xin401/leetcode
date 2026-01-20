#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string encode(vector<string> &strs)
    {
        string result = "";
        for (const auto &s : strs)
        {
            if (s.size() < 10)
            {
                result += "00" + to_string(s.size()) + s;
            }
            else if (s.size() < 100)
            {
                result += "0" + to_string(s.size()) + s;
            }
            else
            {
                result += to_string(s.size()) + s;
            }
        }
        return result;
    }

    vector<string> decode(string s)
    {
        vector<string> result;
        int ptr = 0;
        int num = 0;
        while (ptr < s.size())
        {
            string num = s.substr(ptr, 3);
            result.push_back(s.substr(ptr + 3, stoi(num)));
            ptr += 3 + stoi(num);
        }
        return result;
    }
};
