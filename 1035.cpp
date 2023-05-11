#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> matrix(nums2.size(), vector<int>(nums1.size()));
        // init
        bool flag = false;
        for (int i = 0; i < nums1.size(); i++)
        {
            if (nums1[i] == nums2[0])
            {
                flag = true;
            }
            matrix[0][i] = flag ? 1 : 0;
        }
        flag = false;
        for (int i = 0; i < nums2.size(); i++)
        {
            if (nums2[i] == nums1[0])
            {
                flag = true;
            }
            matrix[i][0] = flag ? 1 : 0;
        }
        for (int i = 1; i < nums1.size(); i++)
        {
            for (int j = 1; j < nums2.size(); j++)
            {
                matrix[j][i] = nums2[j] == nums1[i] ? max(matrix[j - 1][i - 1] + 1, max(matrix[j][i - 1], matrix[j - 1][i])) : max(matrix[j][i - 1], matrix[j - 1][i]);
            }
        }
        return matrix[nums2.size() - 1][nums1.size() - 1];
    }
};
int main()
{
    vector<int> nums1(5), nums2(6);
    for (auto &v : nums1)
    {
        cin >> v;
    }
    for (auto &v : nums2)
    {
        cin >> v;
    }
    Solution sol;
    cout << sol.maxUncrossedLines(nums1, nums2);
}