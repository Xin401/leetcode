#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void del(vector<stack<int>> &count, vector<bool> &table, int ptr)
{
    table[ptr] = true;
    cout << ptr << ' ';
    while (!count[ptr].empty())
    {
        int next = count[ptr].top();
        count[ptr].pop();
        del(count, table, next);
    }
}
class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < n - 1)
        {
            return -1;
        }
        else
        {
            int ret = 0;
            vector<stack<int>> count(n);
            vector<bool> table(n, false);
            int ptr = 0;
            for (auto &p : connections)
            {
                count[p[0]].push(p[1]);
                count[p[1]].push(p[0]);
            }
            while (ptr != n)
            {
                del(count, table, ptr);
                while (ptr != n && table[ptr])
                {
                    ptr++;
                }
                ret += ptr != n ? 1 : 0;
            }
            return ret;
        }
    }
};