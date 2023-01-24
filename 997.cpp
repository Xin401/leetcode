#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findJudge(int n, vector<vector<int> > &trust)
    {
        if (trust.size() < n - 1)
        {
            return -1;
        }
        vector<vector<int> > judge(n + 11);
        vector<bool> town(n + 11, false);
        for (auto &v : trust)
        {
            town[v[0]] = true;
            if (!town[v[1]])
            {
                judge[v[1]].push_back(v[0]);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (!town[i] && judge[i].size() == n - 1)
            {
                return i;
            }
        }
        return -1;
    }
};
int main()
{
}