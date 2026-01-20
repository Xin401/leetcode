class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(1);
        vector<int>temp(1);
        if(n!=0)
        {
            ans[0]=0;
            temp[0] = 1;
        }
        while(ans.size()<n+1)
        {
            int digit = temp.size();
            for(int i = 0;i<digit ;i++)
            {
                if(ans.size()==n+1)
                {
                    break;
                }
                ans.push_back(temp[i]);
            }
            for(int i = 0;i<digit;i++)
            {
                temp.push_back(temp[i]+1);
            }
        }
        return ans;
    }
};