class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        bool ans = true;
        int base;
        for(int i =0;i<matrix.size();i++)
        {
            base=matrix[i][0];
            for(int j=1;j<matrix[i].size()&&i+j<matrix.size();j++)
            {
                if(matrix[i+j][j]!=base)
                {
                    ans=false;
                    break;
                }
            }
            if(!ans)
            {
                break;
            }
        }
        for(int i =0;i<matrix[0].size();i++)
        {
            base=matrix[0][i];
            for(int j=1;i+j<matrix[0].size()&&j<matrix.size();j++)
            {
                if(matrix[j][i+j]!=base)
                {
                    ans=false;
                    break;
                }
            }
            if(!ans)
            {
                break;
            }
        }
        return ans;
    }
};