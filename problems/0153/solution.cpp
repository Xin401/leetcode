#include <vector>
using namespace std;

class Solution {
 public:
  int findMin(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    int ans = nums[0];

    while (left <= right) {
      int mid = left + (right - left) / 2;
      ans = min(ans, nums[mid]);
      if (nums[mid] < nums[right]) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return ans;
  }
};
// At left
// 1 2 3 4 5
// 5 1 2 3 4
// 4 5 1 2 3

// At right
// 3 4 5 1 2
// 2 3 4 5 1