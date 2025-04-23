#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> myMap;
        int diff = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            diff = target - nums[i];
            if (myMap.find(diff) != myMap.end())
            {
                return vector<int>{myMap[diff], i};
            }
            myMap[nums[i]] = i;
        }
        return vector<int>{0, 0};
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 6, 11, 15};
    for (const auto &n : sol.twoSum(nums, 8))
    {
        cout << n;
    }
}