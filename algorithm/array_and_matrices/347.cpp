#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> count = {};
        int m = 1;
        for (const auto &n : nums)
        {
            count[n] += 1;
            m = max(count[n], m);
        }
        vector<vector<int>> bucket(m);
        for (const auto &n : count)
        {
            bucket[n.second - 1].push_back(n.first);
        }
        vector<int> result;
        for (int i = m - 1; i >= 0; i--)
        {
            for (const auto &n : bucket[i])
            {
                result.push_back(n);
            }
            if (result.size() == k)
            {
                return result;
            }
        }
        return {};
    }
};

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    Solution sol;
    vector<int> result = sol.topKFrequent(nums, k);
    for (const auto &n : result)
    {
        cout << n << ' ';
    }
}