#include <vector>
using namespace std;
class Solution {
 private:
  void backtrack(vector<int>& candidates, int target, vector<int>& path,
                 int pathSum, vector<vector<int>>& res, int startIndex) {
    if (pathSum == target) {
      res.push_back(path);
      return;
    } else if (pathSum > target) {
      return;
    }

    for (int i = startIndex; i < candidates.size(); i++) {
      path.push_back(candidates[i]);
      backtrack(candidates, target, path, pathSum + candidates[i], res, i);
      path.pop_back();
    }
  }

 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> path;
    vector<vector<int>> res;
    backtrack(candidates, target, path, 0, res, 0);
    return res;
  }
};