#include <vector>
using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int min_val = nums[0];
    int min_pos = 0;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] < min_val) {
        min_val = nums[mid];
        min_pos = mid;
      }

      if (nums[mid] < nums[right]) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    if (nums[min_pos] <= target && target <= nums[nums.size() - 1]) {
      left = min_pos;
      right = nums.size() - 1;
    } else {
      left = 0;
      right = min_pos - 1;
    }
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return -1;
  }
};