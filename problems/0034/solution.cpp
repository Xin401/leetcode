#include <vector>
using namespace std;

class Solution {
 public:
  int searchLeftBond(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] >= target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    if (left > nums.size() - 1 || nums[left] != target) {
      return -1;
    }
    return left;
  }
  int searchRightBond(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (nums[mid] <= target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    if (right < 0 || nums[right] != target) {
      return -1;
    }
    return right;
  }
  vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.size() == 0) {
      return vector<int>{-1, -1};
    }
    int leftBond = this->searchLeftBond(nums, target);
    int rightBond = this->searchRightBond(nums, target);
    return vector<int>{leftBond, rightBond};
  }
};