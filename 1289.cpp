#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        if (grid.size() == 1)
        {
            return *min_element(grid[0].begin(), grid[0].end());
        }
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        dp[0] = grid[0];
        for (int i = 1; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                int min = INT_MAX;
                for (int k = 0; k < grid[0].size(); k++)
                {
                    if (k == j)
                    {
                        continue;
                    }
                    if (dp[i - 1][k] < min)
                    {
                        min = dp[i - 1][k];
                    }
                }
                dp[i][j] = min + grid[i][j];
            }
        }
        return *min_element(dp[grid.size() - 1].begin(), dp[grid.size() - 1].end());
    }
};

int main()
{
    // vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> grid = {{-73, 61, 43, -48, -36}, {3, 30, 27, 57, 10}, {96, -76, 84, 59, -15}, {5, -49, 76, 31, -7}, {97, 91, 61, -46, 67}};
    Solution s;
    cout << s.minFallingPathSum(grid) << endl;
}

/*
Let dp[i][j] be the answer for the first i rows such that column j is chosen from row i.
Note. Choose 'any' column not above the current column, not just the adjacent ones.
*/