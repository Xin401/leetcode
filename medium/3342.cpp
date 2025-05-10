#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

class Solution
{
public:
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        int height = moveTime.size();
        int length = moveTime[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> min_time(height, vector<int>(length, INT32_MAX));
        vector<pair<int, int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        // time, y, x
        pq.push({0, 0, 0});
        moveTime[0][0] = 0;
        while (!pq.empty())
        {
            vector<int> t = pq.top();
            pq.pop();
            int time = t[0];
            int y = t[1];
            int x = t[2];
            if (time >= min_time[y][x])
            {
                continue;
            }
            if (y == height - 1 && x == length - 1)
            {
                return time;
            }
            min_time[y][x] = time;
            for (const auto &d : direction)
            {
                int next_y = y + d.first;
                int next_x = x + d.second;
                if (0 <= next_y && next_y < height && 0 <= next_x && next_x < length)
                {
                    if (min_time[next_y][next_x] == INT32_MAX)
                    {
                        pq.push({max(time, moveTime[next_y][next_x]) + (y + x) % 2 + 1, next_y, next_x});
                    }
                }
            }
        }
        return 0;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> moveTime = {{0, 4}, {4, 4}};
    cout << sol.minTimeToReach(moveTime);
}