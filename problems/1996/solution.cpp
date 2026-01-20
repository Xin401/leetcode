class Solution {
public:
    static bool minesort(vector<int>&v1,vector<int>&v2)
    {
        if(v1[0]==v2[0])
        {
            return v1[1]<v2[1];
        }
        return v1[0]>v2[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int ret = 0;
        sort(properties.begin(),properties.end(),minesort);
        int maxi = INT_MIN;
        for(auto p:properties)
        {
            if(p[1]<maxi)
            {
                ret++;
            }
            else 
            {
                maxi = p[1];
            }
        }
        return ret;
    }
};