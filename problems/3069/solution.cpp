#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> resultArray(vector<int>& nums) {
    vector<int> arr1(1, nums[0]), arr2(1, nums[1]);
    for (int i = 2; i < nums.size(); i++) {
      if (arr1.back() > arr2.back()) {
        arr1.push_back(nums[i]);
      } else {
        arr2.push_back(nums[i]);
      }
    }
    for (auto& n : arr2) {
      arr1.push_back(n);
    }
    return arr1;
  }
};