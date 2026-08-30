#include <vector>
using namespace std;

class Solution {
 public:
  int minimumDeletions(vector<int>& nums) {
    int size = nums.size();
    int maximum = INT_MIN;
    int minimum = INT_MAX;
    int max_index = -1;
    int min_index = -1;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > maximum) {
        maximum = nums[i];
        max_index = i;
      }
      if (nums[i] < minimum) {
        minimum = nums[i];
        min_index = i;
      }
    }
    int ptr1 = min(max_index, min_index);
    int ptr2 = max(max_index, min_index);
    return min(size - ptr1, min(ptr2 + 1, ptr1 + 1 + size - ptr2));
  }
};