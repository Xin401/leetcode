#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
    // binary search
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        sort(piles.begin(), piles.end());
        int ret;
        int l = 1, r = piles[piles.size() - 1];
        int k;   // bananas per hour
        int cnt; // hour for current k
        while (l <= r)
        {
            cnt = h;
            k = (l + r) / 2;
            for (auto &v : piles)
            {
                cnt -= ceil(v / static_cast<double>(k));
            }
            cout << '\n';
            if (cnt >= 0)
            {
                ret = k;
                r = k - 1;
            }
            else
            {
                l = k + 1;
            }
        }
        return ret;
    }
};
int main()
{
    int h;
    int N = 4;
    vector<int> piles(N);
    for (int i = 0; i < N; i++)
    {
        cin >> piles[i];
    }
    cin >> h;
    Solution sol;
    cout << sol.minEatingSpeed(piles, h);
}