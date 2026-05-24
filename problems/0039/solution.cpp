#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
 public:
  void backtrack(set<vector<int>>& ret, vector<int>& candidates,
                 int current_val, vector<int> current_vec, int target) {
    if (current_val == target) {
      sort(current_vec.begin(), current_vec.end());
      ret.insert(current_vec);
      return;
    } else if (current_val > target) {
      return;
    } else {
      for (auto& v : candidates) {
        vector<int> tmp = current_vec;
        tmp.push_back(v);
        backtrack(ret, candidates, current_val + v, tmp, target);
      }
    }
  }
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    set<vector<int>> ret;
    vector<vector<int>> uni_ret;
    backtrack(ret, candidates, 0, {}, target);
    for (auto& vec : ret) {
      uni_ret.push_back(vec);
      for (auto& v : vec) {
        cout << v << ',';
      }
      cout << endl;
    }

    return uni_ret;
  }
};

int main() {
  Solution sol;
  vector<int> candidates = {2, 5, 6, 9};
  sol.combinationSum(candidates, 9);
}
