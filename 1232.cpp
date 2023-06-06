#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(vector<int> &v1, vector<int> &v2)
{
    return (v1[1] < v2[1]);
}
class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        sort(coordinates.begin(), coordinates.end(), cmp);
        double coeff;
        if ((coordinates[0][0] - coordinates[1][0]) != 0)
        {
            coeff = (double)(coordinates[0][1] - coordinates[1][1]) / (double)(coordinates[0][0] - coordinates[1][0]);
            double inter = coordinates[0][1] - coeff * coordinates[0][0];
            for (int i = 2; i < coordinates.size(); i++)
            {
                if (coordinates[i][1] - coordinates[i][0] * coeff != inter)
                {
                    return false;
                }
            }
        }
        else
        {
            cout << (coordinates[2][0] == coordinates[0][0] ? "t" : "f");
            for (int i = 2; i < coordinates.size(); i++)
            {
                if (coordinates[i][0] != coordinates[0][0])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<int>> coordinates = {{0, 0}, {0, 1}, {0, -1}};
    Solution sol;
}