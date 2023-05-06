#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        const int MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int n = nums.size(), left = 0, right = n - 1, count = 0;
        vector<int> pows(n, 1);
        for (int i = 1; i < n; ++i)
        {
            pows[i] = (pows[i - 1] * 2) % MOD;
        }
        while (left <= right)
        {
            if (nums[left] + nums[right] <= target)
            {
                count = (count + pows[right - left]) % MOD;
                ++left;
            }
            else
            {
                --right;
            }
        }
        return count;
    }
};