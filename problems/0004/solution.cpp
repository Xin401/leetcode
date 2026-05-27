#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int mid_length = (m + n + 1) / 2;
    if (m > n) return findMedianSortedArrays(nums2, nums1);
    if (m == 0) return (double)(nums2[(n - 1) / 2] + nums2[n / 2]) / 2;

    int left = 0;
    int right = m;
    while (left <= right) {
      int nums1_cut = left + (right - left) / 2;
      int nums2_cut = mid_length - nums1_cut;
      int nums1_left_max = nums1_cut == 0 ? INT_MIN : nums1[nums1_cut - 1];
      int nums1_right_min = nums1_cut == m ? INT_MAX : nums1[nums1_cut];
      int nums2_left_max = nums2_cut == 0 ? INT_MIN : nums2[nums2_cut - 1];
      int nums2_right_min = nums2_cut == n ? INT_MAX : nums2[nums2_cut];
      // cout << nums1_cut << ',' << nums2_cut << endl;
      // cout << nums1_left_max << ',' << nums1_right_min << endl;
      // cout << nums2_left_max << ',' << nums2_right_min << endl;
      if (nums1_left_max <= nums2_right_min &&
          nums2_left_max <= nums1_right_min) {
        if ((m + n) % 2) {
          return max(nums1_left_max, nums2_left_max);
        } else {
          return (double)(max(nums1_left_max, nums2_left_max) +
                          min(nums1_right_min, nums2_right_min)) /
                 2;
        }
      } else if (nums1_right_min < nums2_left_max) {
        left = nums1_cut + 1;
      } else {
        right = nums1_cut - 1;
      }
    }
    return -1;
  }
};

// int main() {
//   Solution sol;
//   vector<int> nums1 = {1, 2, 3, 5, 6};
//   vector<int> nums2 = {4};
//   cout << sol.findMedianSortedArrays(nums1, nums2);
// }