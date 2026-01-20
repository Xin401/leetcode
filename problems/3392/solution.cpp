#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countSubarrays(vector<int> &nums)
    {
        int result = 0;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (nums[i] + nums[i + 2] == nums[i + 1] / 2.0)
            {
                result++;
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {-1, -4, -1, 4};
    Solution sol;
    cout << sol.countSubarrays(nums);
}