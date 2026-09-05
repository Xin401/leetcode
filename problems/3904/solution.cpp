#include <vector>
using namespace std;

class Solution {
 public:
  int firstStableIndex(vector<int>& nums, int k) {
    vector<int> preMax(nums.size(), 0);
    vector<int> suMin(nums.size(), 0);
    int M = nums[0];
    int m = nums[nums.size() - 1];
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] >= M) {
        M = nums[i];
      }
      preMax[i] = M;
      if (nums[nums.size() - 1 - i] <= m) {
        m = nums[nums.size() - 1 - i];
      }
      suMin[nums.size() - 1 - i] = m;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (preMax[i] - suMin[i] <= k) {
        return i;
      }
    }
    return -1;
  }
};