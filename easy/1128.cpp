#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        unordered_map<int, int> myMap;
        int domino;
        int result = 0;
        for (const auto &d : dominoes)
        {
            if (d[0] > d[1])
            {
                domino = d[1] * 10 + d[0];
            }
            else
            {
                domino = d[0] * 10 + d[1];
            }
            if (myMap.find(domino) != myMap.end())
            {
                result += myMap[domino];
                myMap[domino] += 1;
            }
            else
            {
                myMap[domino] = 1;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> dominos = {{1, 2}, {2, 1}, {3, 4}, {5, 6}};
    cout << sol.numEquivDominoPairs(dominos);
}