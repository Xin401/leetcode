#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        long long result = 0;
        int n = nums.size();
        int count = 0;
        int left = 0;
        int target = *max_element(nums.begin(), nums.end());
        for (int right = 0; right < n; right++)
        {
            if (nums[right] == target)
            {
                count += 1;
            }
            while (count >= k)
            {
                result += n - right;
                if (nums[left] == target)
                {
                    count -= 1;
                }
                left += 1;
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {1, 3, 2, 3, 3};
    int k = 2;
    Solution sol;
    cout << sol.countSubarrays(nums, k);
}