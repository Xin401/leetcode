class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int sum=0;
        int biggest=0;
        int mid;
        for(const auto &v : nums)
        {
            sum +=v;
            biggest=max(v,biggest);
        }
        while(biggest<sum)
        {
            mid = (biggest+sum)/2;
            int total = 0;
            int count = 1;
            for(const auto &v:nums)
            {
                if(total+v<=mid)
                {
                    total+=v;
                }
                else
                {
                    total=v;
                    count++;
                }
            }
            if(count>m)
            {
                biggest = mid+1;
            }
            else
            {
                sum = mid;
            }
        }
        return sum;
    }
};