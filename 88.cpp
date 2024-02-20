#include <iostream>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> tmp(nums1.begin(), nums1.begin() + m);
        // for (auto i : tmp)
        // {
        //     cout << i << " ";
        // }
        int p1 = 0, p2 = 0;
        for (int i = 0; i < n + m; i++)
        {
            if (p1 == m)
            {
                nums1[i] = nums2[p2];
                p2++;
                continue;
            }
            else if (p2 == n)
            {
                nums1[i] = tmp[p1];
                p1++;
                continue;
            }
            else if (tmp[p1] < nums2[p2])
            {
                nums1[i] = tmp[p1];
                p1++;
            }
            else
            {
                nums1[i] = nums2[p2];
                p2++;
            }
        }
    }
};
int main()
{
    Solution s;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    s.merge(nums1, 3, nums2, 3);
    for (auto i : nums1)
    {
        cout << i << " ";
    }
    return 0;
}