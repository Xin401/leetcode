#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    bool reach(const vector<int> &bomb1, const vector<int> &bomb2)
    {
        return pow(bomb1[0] - bomb2[0], 2) + pow(bomb1[1] - bomb2[1], 2) <= pow(bomb1[2], 2);
    }
    int dfs(const vector<vector<int>> &bombs, vector<bool> &visit, int bomb)
    {
        int num = 0;
        for (int i = 0; i < bombs.size(); i++)
        {
            if (num == bombs.size())
            {
                break;
            }
            if (!visit[i] && reach(bombs[bomb], bombs[i]))
            {
                num++;
                visit[i] = true;
                num += dfs(bombs, visit, i);
            }
        }
        return num;
    }
    int maximumDetonation(vector<vector<int>> &bombs)
    {
        vector<bool> visit;
        int ret = 0;
        for (int i = 0; i < bombs.size(); i++)
        {
            visit = vector<bool>(bombs.size(), false);
            ret = max(ret, dfs(bombs, visit, i));
        }
        return ret;
    }
};

int main()
{
    vector<vector<int>> bombs = {{2, 1, 3}, {6, 1, 4}};
    Solution sol;
    cout << sol.maximumDetonation(bombs);
}
