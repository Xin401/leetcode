#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<int> check;
        for (const auto &p : s)
        {
            if (!check.empty() && p == ')')
            {
                if (check.top() == '(')
                {
                    check.pop();
                }
                else
                {
                    return false;
                }
            }
            else if (!check.empty() && p == '}')
            {
                if (check.top() == '{')
                {
                    check.pop();
                }
                else
                {
                    return false;
                }
            }
            else if (!check.empty() && p == ']')
            {
                if (check.top() == '[')
                {
                    check.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                check.push(p);
            }
        }
        return check.empty();
    }
};

int main()
{
    Solution sol;
    string s = "[]";
    cout << boolalpha << sol.isValid(s);
}