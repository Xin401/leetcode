class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> temp;
        int sum=0;
        for(int i = 0;i<ops.size();i++)
        {
            if(ops[i].find_first_of("-0123456789")!=string::npos)
            {
                temp.push_back(stoi(ops[i]));
                sum+=stoi(ops[i]);
            }
            if(ops[i]=="C")
            {
                sum-=temp.back();
                temp.pop_back();
            }
            if(ops[i]=="D")
            {
                sum+=2*temp.back();
                temp.push_back(2*temp.back());
            }
            if(ops[i]=="+")
            {
                sum+=temp.back()+temp[temp.size()-2];
                temp.push_back(temp.back()+temp[temp.size()-2]);
            }  
        }
        return sum;
    }
};