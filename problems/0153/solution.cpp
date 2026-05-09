#include <iostream>
using namespace std;

class Solution {
 public:
  int findMin(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
      int mid = (left + right) / 2;
      cout << left << ',' << mid << ',' << right << endl;
      // at left
      if ((nums[mid] < nums[right] && nums[right] < nums[left]) or
          (nums[left] <= nums[mid] && nums[mid] < nums[right])) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return nums[left];
  }
};

int main() {
  Solution sol;
  vector<int> nums = {3, 4, 5, 1, 2};
  cout << sol.findMin(nums);
}
// At left
// 1 2 3 4 5
// 5 1 2 3 4
// 4 5 1 2 3

// At right
// 3 4 5 1 2
// 2 3 4 5 1