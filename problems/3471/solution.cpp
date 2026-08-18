#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int largestInteger(vector<int>& nums, int k) {
    int cnt[51] = {0};
    int ret = -1;
    for (int i = 0; i <= nums.size() - k; i++) {
      bool has[51] = {false};
      for (int j = i; j < i + k; j++) {
        if (!has[nums[j]]) {
          cnt[nums[j]]++;
          has[nums[j]] = true;
        }
      }
    }
    for (int i = 0; i < 51; i++) {
      if (cnt[i] == 1) {
        ret = i;
      }
    }
    return ret;
  }
};

// int main() {
//   Solution sol;
//   vector<int> nums = {3, 9, 2, 1, 7};
//   sol.largestInteger(nums, 3);
// }