#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        if (grid.size() == 1 && grid[0].size() == 1) return 0;
        int rmd = grid[0][0] % x;
        int res = 0;
        vector<int> nums;
        for(const auto& vec : grid) {
            for(const auto& n : vec) {
                if (n % x != rmd) {
                    return -1;
                }
                nums.push_back(n);
            }
        }
        sort(nums.begin(), nums.end());
        int target = nums[nums.size()/2];
        // for (int i = 0; i < nums.size() - 1; i++) {
        //     if (nums[i] < avg && nums[i+1] > avg) {
        //         target = avg - nums[i] < nums[i+1] - avg ? nums[i] : nums[i+1];
        //     }
        // }
        for(const auto& n : nums) {
            res += abs(target - n) / x;
            // cout << n << ", ";
        }
        // cout << avg << endl;
        // cout << target << endl;
        return res;
    }
};

int main()
{
    Solution sol;
    // pair<vector<vector<int>>, int> param = {{{2,4},{6,8}},2};
    // pair<vector<vector<int>>, int> param = {{{1,5},{2,3}},1};
    pair<vector<vector<int>>, int> param = {{{980,476,644,56},{644,140,812,308},{812,812,896,560},{728,476,56,812}},84};
    cout << sol.minOperations(param.first, param.second);
}