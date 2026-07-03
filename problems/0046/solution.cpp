#include <vector>
using namespace std;

class Solution {
 private:
  void backtrack(vector<int>& nums, vector<int>& used, vector<int>& path,
                 vector<vector<int>>& res) {
    if (path.size() == nums.size()) {
      res.push_back(path);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (used[i]) continue;

      used[i] = true;
      path.push_back(nums[i]);

      backtrack(nums, used, path, res);

      path.pop_back();
      used[i] = false;
    }
  }

 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<int> used(nums.size());
    vector<int> path;
    vector<vector<int>> res;
    backtrack(nums, used, path, res);
    return res;
  }
};