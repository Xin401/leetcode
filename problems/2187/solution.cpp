#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    // tle
public:
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        sort(time.begin(), time.end());
        int t = 1;
        long long trip = 0;
        bool flag = true, exc = false, les = false;
        while (flag)
        {
            trip = 0;
            for (auto &v : time)
            {
                if (v > t)
                {
                    break;
                }
                trip += t / v;
            }
            if (exc && trip < totalTrips)
            {
                les = true;
            }
            else if (!exc && trip > totalTrips)
            {
                exc = true;
            }

            // cout << t << ',' << trip << endl;
            if (!exc)
            {
                t *= 2;
            }
            else if (exc && !les)
            {
                t--;
            }
            else
            {
                t++;
                flag = false;
            }
        }
        return t;
    }
};

int main()
{
    int N = 7;
    vector<int> time(N);
    int totalTrips;
    for (int i = 0; i < N; i++)
    {
        cin >> time[i];
    }
    cin >> totalTrips;
    Solution sol;
    cout << sol.minimumTime(time, totalTrips);
}