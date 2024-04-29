#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        bitset<20> target(k);
        vector<bitset<20>> nums_bs;
        vector<int> sum(20);
        for (auto n : nums)
        {
            nums_bs.push_back(bitset<20>(n));
            for (auto i = 0; i < 20; i++)
            {
                sum[i] += nums_bs.back()[i];
            }
        }
        int res = 0;
        for (auto i = 0; i < 20; i++)
        {
            if ((sum[i] % 2) == target[i])
            {
                continue;
            }
            res++;
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {2, 0, 2, 0};
    int k = 0;
    cout << s.minOperations(nums, k) << endl;
}

/*
觀察結果：有奇數個1 xor 結果就是1，偶數個 xor 就是0，所以只要計算每個bit有幾個1，最後和k比較
*/