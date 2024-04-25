#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestIdealString(string s, int k)
    {
        vector<int> dp(26, 0);
        for (char c : s)
        {
            vector<int> dp2 = dp;
            for (int i = max(0, c - 'a' - k); i <= min(25, c - 'a' + k); ++i)
            {
                dp2[c - 'a'] = max(dp2[c - 'a'], dp[i] + 1);
            }
            dp = dp2;
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{
    string s = "acfgbd";
    int k = 2;
    Solution sol;
    cout << sol.longestIdealString(s, k) << endl;
}

/*
用一個dp陣列紀錄每個字母的最長連續字串長度（長度26）
每次遍歷字串時，對於每個字母，更新dp陣列
更新方法：
    對於字母c，找到字母c-k到字母c+k之間的字母，因為這個區段的字母才可以當作c的上一個字母，然後找到接續哪個字母可以得到最長的連續字串
*/