class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        int min = 0;
        vector<vector<int>> ans;
        vector<int> ds;
        for(int i = 1;i==k;i++)
        {
            min+=i;
        }
        if(min>n)
        {
            return ans;
        }
        solve(1,k,n,ds,ans);
        return ans;
    }
    void solve(int st,int k,int n,vector<int>&ds,vector<vector<int>> &ans)
    {
        if(k<=0)
        {
            if(n==0)
                ans.push_back(ds);
            return;
        }
        for(int i = st;i<=9;i++)
        {
            ds.push_back(i);
            solve(i+1,k-1,n-i,ds,ans);
            ds.pop_back();
        }
    }
};