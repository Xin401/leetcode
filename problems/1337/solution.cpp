class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> indice(mat.size());
        for(int i = 0;i<mat.size();i++)
        {
            indice[i]=i;
        }
        for(int i = mat.size()-1;i>0;i--)
        {
            for(int j = 0;j<i;j++)
            {
                if(mat[j]>mat[j+1])
                {
                    swap(mat[j],mat[j+1]);
                    swap(indice[j],indice[j+1]);
                }
            }
        }
        indice.resize(k);
        return indice;
    }
};