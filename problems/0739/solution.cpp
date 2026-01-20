#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<pair<int, int>> myStack;
        for (int i = 0; i < n; i++)
        {
            while (!myStack.empty() && (temperatures[i] > myStack.top().second))
            {
                result[myStack.top().first] = i - myStack.top().first;
                myStack.pop();
            }
            myStack.push({i, temperatures[i]});
        }
        return result;
    }
};