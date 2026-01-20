#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        set<int> store(nums.begin(), nums.end());
        int result = 0;
        for (const auto &n : store)
        {
            if (store.find(n - 1) == store.end())
            {
                int length = 1;
                while (store.find(n + length) != store.end())
                {
                    length += 1;
                }
                result = max(length, result);
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    Solution sol;
    cout << sol.longestConsecutive(nums);
}