#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> result(nums.size(), 1);
        int prefix_production = 1, suffix_production = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            prefix_production *= nums[i - 1];
            suffix_production *= nums[nums.size() - i];
            result[i] *= prefix_production;
            result[nums.size() - 1 - i] *= suffix_production;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = sol.productExceptSelf(nums);
    for (const auto &n : result)
    {
        cout << n << ',';
    }
}