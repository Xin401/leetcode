#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int res = 0, sum = 0;
        unordered_map<int, int> count;
        count[0]++;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (count.find(sum - goal) != count.end())
            {
                res += count[sum - goal];
            }
            count[sum]++;
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {0, 0, 0, 0, 0};
    int goal = 0;
    Solution sl;
    cout << sl.numSubarraysWithSum(nums, goal) << endl;
}