class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret=0;
        int cheapest = INT_MAX;
        for(auto p:prices)
        {
            if(p<cheapest)
            {
                cheapest = p;
            }
            if(p-cheapest>ret)
            {
                ret = p-cheapest;
            }
        }
        return ret;
    }
};