#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int> (k + 1, -1)));
        if(grid[0][0] == 0) dp[0][0][0] = 0;
        else if (k >= 1) dp[0][0][1] = grid[0][0];
        else return -1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 and j == 0) continue;
                for(int K = 0; K <= k; K++) {
                    if(grid[i][j] == 0) {
                        dp[i][j][K] = max(dp[i - 1 >= 0 ? i - 1:0][j][K], dp[i][j - 1 >= 0 ? j-1:0][K]);
                    }
                    else{
                        if (k == K) continue;
                        if (i > 0 and dp[i - 1][j][K] != -1) dp[i][j][K+1] = dp[i-1][j][K]+ grid[i][j];
                        if (j > 0 and dp[i][j - 1][K] != -1) dp[i][j][K+1] = max(dp[i][j][K+1], dp[i][j - 1][K]+ grid[i][j]);
                    }
                }
            }
        }
        // for (int K = 0; K <= k; K++){
        //     for (int i = 0; i < m; i++) {
        //         for (int j = 0; j < n; j++) {
        //             cout << dp[i][j][K] << ',';
        //         }
        //         cout << endl;
        //     }
        //     cout << endl;
        // }
        int res = -1;
        for(int K = 0; K <= k; K++) {
            res = max(res, dp[m - 1][n - 1][K]);
        }
        
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{0,2,2},{1,1,1},{0,2,2}};
    cout << sol.maxPathScore(grid, 3);
}