#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int binary_search(vector<int> nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[mid] < target) {
        left = mid + 1;
      } else if (nums[mid] == target) {
        return mid;
      } else {
        right = mid - 1;
      }
    }
    return -1;
  }
  int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
      int mid = (left + right) / 2;
      if ((nums[mid] < nums[right] && nums[right] < nums[left]) or
          (nums[left] <= nums[mid] && nums[mid] < nums[right])) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    // cout << left;
    vector<int> left_part(nums.begin(), nums.begin() + left);
    vector<int> right_part(nums.begin() + left, nums.end());
    int left_result = this->binary_search(left_part, target);
    int right_result = this->binary_search(right_part, target);
    if (left_result != -1) {
      return left_result;
    } else if (right_result != -1) {
      return right_result + left;
    }
    return -1;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {5, 1, 3};
  cout << sol.search(nums, 1);
}
// find cut point
// At left
// 1 2 3 4 5
// 4 5 1 2 3
// 5 1 2 3 4

// At right
// 2 3 4 5 1
// 3 4 5 1 2