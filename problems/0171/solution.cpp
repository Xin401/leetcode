#include<cmath>
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        char temp;
        vector<int> cal;
        for(int i = 0;i<columnTitle.length();i++)
        {
            temp = columnTitle[i];
            cal.push_back(static_cast<int>(temp)-64);
        }
        for(int i = 0;i<cal.size();i++)
        {
            ans += (pow(26,cal.size()-i-1)*cal[i]);
        }
        return ans;
    }
};