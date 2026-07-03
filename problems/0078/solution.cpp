#include <vector>
using namespace std;

class Solution {
 private:
  void backtrack(vector<int>& nums, int startIndex, vector<int>& path,
                 vector<vector<int>>& res) {
    res.push_back(path);

    for (int i = startIndex; i < nums.size(); i++) {
      path.push_back(nums[i]);
      backtrack(nums, i + 1, path, res);
      path.pop_back();
    }
  }

 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> path;
    vector<vector<int>> res;
    backtrack(nums, 0, path, res);
    return res;
  }
};