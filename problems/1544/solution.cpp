class Solution {
public:
    string makeGood(string s) {
        bool flag = true;
        while(flag)
        {
            flag=false;
            for(int i = 1;i<s.size();i++)
            {
                if(abs(s[i]-s[i-1])==32)
                {
                    s.erase(i-1,2);
                    flag=true;
                    break;
                }
            }
        }
        return s;
    }
};