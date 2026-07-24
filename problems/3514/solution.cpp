#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int uniqueXorTriplets(vector<int>& nums) {
    int ret = 0;
    vector<bool> level2(2049, false);
    vector<bool> level3(2049, false);
    for (auto& n : nums) {
      for (auto& m : nums) {
        level2[n ^ m] = true;
      }
    }
    for (int i = 0; i < level2.size(); i++) {
      if (!level2[i]) {
        continue;
      }
      for (auto& n : nums) {
        if (!level3[i ^ n]) {
          ret++;
          level3[i ^ n] = true;
        }
      }
    }
    return ret;
  }
};