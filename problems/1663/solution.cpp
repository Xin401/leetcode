class Solution {
public:
    string getSmallestString(int n, int k) {
        vector<int> ans(n);
        string ansstring;
        for(int i = 0;i<n;i++)
        {
            ans[i] = 1;
        }
        k-=n;
        int mark = n-1;
        while(k>0)
        {
            if(ans[mark]==26)
            {
                mark--;
            }
            ans[mark]++;
            k--;
        }
        for(int i = 0;i<n;i++)
        {
            ansstring.push_back(static_cast<char>(ans[i]+96));
        }
        return ansstring;
    }
};