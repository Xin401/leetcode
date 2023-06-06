#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int de = arr[1] - arr[0];
        bool flag = true;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] - arr[i - 1] != de)
            {
                flag = false;
                break;
            }
        }
        return flag;
    }
};