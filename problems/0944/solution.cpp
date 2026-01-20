#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int ret = 0;
        for (int i = 0; i < strs[0].size(); i++)
        {
            bool flag = true;
            for (int j = 0; j < strs.size() - 1; j++)
            {
                if (strs[j][i] > strs[j + 1][i])
                {
                    flag = false;
                    break;
                }
            }
            ret += !flag ? 1 : 0;
        }
        return ret;
    }
};

int main()
{
    vector<string> strs;
    string str;
    int n = 2;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        strs.push_back(str);
    }
    Solution obj;
    cout << obj.minDeletionSize(strs);
}