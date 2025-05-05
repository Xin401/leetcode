#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    void backtrack(int n, vector<string> &result, int open_count, string current)
    {
        if (open_count == 0 && n == 0)
        {
            result.push_back(current);
            return;
        }
        if (open_count == 0 && n != 0)
        {
            backtrack(n - 1, result, open_count + 1, current + "(");
        }
        else if (open_count != 0 and n == 0)
        {
            backtrack(n, result, open_count - 1, current + ")");
        }
        else
        {
            backtrack(n - 1, result, open_count + 1, current + "(");
            backtrack(n, result, open_count - 1, current + ")");
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        backtrack(n, result, 0, "");
        return result;
    }
};