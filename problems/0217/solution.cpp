#include <iostream>
#include <map>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        map<int, bool> myMap;
        for (const auto &n : nums)
        {
            if (myMap.find(n) == myMap.end())
            {
                myMap[n] = true;
            }
            else
            {
                return true;
            }
        }
        {
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    cout << boolalpha << sol.containsDuplicate(nums);
}