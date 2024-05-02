#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ptr1 = 0;
        int ptr2 = nums.size() - 1;
        int ret = 0;
        while (ptr1 != ptr2)
        {
            if (nums[ptr1] + nums[ptr2] == 0)
            {
                ret = max(abs(nums[ptr1]), ret);
                ptr1++;
            }
            else if (nums[ptr1] + nums[ptr2] > 0)
            {
                ptr2--;
            }
            else
            {
                ptr1++;
            }
        }
        return ret ? ret : -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-1, 2, -3, 3};
    cout << s.findMaxK(nums) << endl;
    return 0;
}