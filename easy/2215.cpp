#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        set<int> first(nums1.begin(), nums1.end());
        set<int> second(nums2.begin(), nums2.end());
        vector<vector<int>> ret(2);
        for (auto it : first)
        {
            if (second.find(it) == second.end())
            {
                ret[0].push_back(it);
            }
        }
        for (auto it : second)
        {
            if (first.find(it) == first.end())
            {
                ret[1].push_back(it);
            }
        }
        return ret;
    }
};

int main()
{
    int n = 3;
    vector<int> nums1(n), nums2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> nums2[i];
    }
    Solution sol;
    vector<vector<int>> ret = sol.findDifference(nums1, nums2);
    for (auto &v : ret)
    {
        for (auto &n : v)
        {
            cout << n << ',';
        }
        cout << '\n';
    }
}