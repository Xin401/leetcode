#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int zero, one;
        zero = one = 0;
        for (auto &c : s)
        {
            if (c == '1')
            {
                one++;
            }
            else
            {
                zero++;
                zero = min(zero, one);
            }
        }
        return zero;
    }
};

int main()
{
    string str;
    cin >> str;
    Solution sol;
    cout << sol.minFlipsMonoIncr(str);
}