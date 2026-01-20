class Solution {
    int dp[111][111];
    int find(int r,int c ,const vector<vector<int>>& matrix)
    {
        if(r==matrix[0].size()-1)
        {
            dp[r][c]=matrix[r][c];
        }
        else if(dp[r][c]==0)
        {
            dp[r][c]=min(min(find(r+1,c-1<0?c:c-1,matrix),find(r+1,c,matrix)),find(r+1,c+1>matrix[0].size()-1?c:c+1,matrix))+matrix[r][c];
        }
        return dp[r][c];
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        for(int i=0;i<matrix[0].size();i++)
        {
            ans=min(ans,find(0,i,matrix));
        }
        return ans;
    }
};