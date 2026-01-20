class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        unordered_map<int,long> dict;
        long long sum =0;
        for(auto key:A)
        {
            dict[key]++;
        }
        for(auto i:dict)
        {
            for(auto j :dict)
            {
                long num1 = i.first;
                long num2 = j.first;
                long find = target-num1-num2;
                if(!dict.count(find))
                {
                    continue;
                }
                if(num1==num2&&num2==find)
                {
                    sum+=(dict[num1]*(dict[num1]-1)*(dict[num1]-2))/6;
                }
                else if(num1==num2&&num2!=find)
                {
                    sum+=dict[num1]*(dict[num1]-1)/2*dict[find];
                }
                else if(num1<num2&&num2<find)
                {
                    sum+=dict[num1]*dict[num2]*dict[find];
                }
            }
        }
        return sum % int(1e9 + 7);
    }
};