#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
    {
        vector<int> remain(capacity.size());
        int now = 0, ret = 0;
        for (int i = 0; i < capacity.size(); i++)
        {
            remain[i] = capacity[i] - rocks[i];
            if (remain[i] == 0)
            {
                ret++;
            }
        }
        sort(remain.begin(), remain.end());
        now = ret;
        while (additionalRocks > 0 && now < capacity.size())
        {
            if (remain[now] <= additionalRocks)
            {
                additionalRocks -= remain[now++];
                ret++;
            }
            else
            {
                break;
            }
        }
        return ret;
    }
};

int main()
{
    int additionalRocks;
    int size = 3;
    vector<int> capacity(size), rocks(size);
    for (int i = 0; i < size; i++)
    {
        cin >> capacity[i];
    }
    for (int i = 0; i < size; i++)
    {
        cin >> rocks[i];
    }
    cin >> additionalRocks;
    Solution solution;
    cout << solution.maximumBags(capacity, rocks, additionalRocks);
}