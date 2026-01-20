class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        while(stones.size()>1)
        {
            int a = *(stones.end()-1);
            int b = *(stones.end()-2);
            int num = a-b;
            if(num==0)
            {
                stones.pop_back();
                stones.pop_back();
            }
            else
            {
                stones.pop_back();
                stones[stones.size()-1]=num;
                sort(stones.begin(),stones.end());
            }
        }
        if(stones.size()==1)
        {
            return stones[0];
        }
        return 0;
    }
};