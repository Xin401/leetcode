#include <iostream>
#include <vector>
using namespace std;

/*
Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.
*/

/*
    use kadane to find the max subarray and the min subarray

    why min subarray?

    Because it is a circular array, and we can get the max subarray by compare (the subarray without circular) and (the sum of the array - min subarray)

    Remember to check whether the array contains all negative elements, if so, return the max element of the array

    Complexity:
        time complexity:O(n)
        space complexity:O(1)
*/
class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int size = nums.size();
        bool isPos = false;
        int cur_pos = 0, max_pos = 0, sum = 0, cur_neg = 0, max_neg = 0;
        int M = INT_MIN;
        for (int i = 0; i < size; i++)
        {
            if (!isPos && nums[i] > 0)
            {
                isPos = true;
            }
            cur_pos = (cur_pos + nums[i] < 0 ? 0 : cur_pos + nums[i]);
            max_pos = (max_pos > cur_pos ? max_pos : cur_pos);
            cur_neg = (cur_neg - nums[i] < 0 ? 0 : cur_neg - nums[i]);
            max_neg = (max_neg > cur_neg ? max_neg : cur_neg);
            sum += nums[i];
            M = max(M, nums[i]);
        }
        return isPos ? max(max_pos, sum + max_neg) : M;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    Solution sol;
    cout << sol.maxSubarraySumCircular(nums);
}