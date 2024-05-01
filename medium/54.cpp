#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int r = matrix.size(), c = matrix[0].size();
        vector<int> result;
        int top = 0, right = c - 1, bottom = r - 1, left = 0;
        while (true)
        {
            for (int i = left; i <= right; i++)
            {
                result.push_back(matrix[top][i]);
            }
            if (result.size() == r * c)
            {
                break;
            }
            top++;
            for (int i = top; i <= bottom; i++)
            {
                result.push_back(matrix[i][right]);
            }
            if (result.size() == r * c)
            {
                break;
            }
            right--;
            for (int i = right; i >= left; i--)
            {
                result.push_back(matrix[bottom][i]);
            }
            if (result.size() == r * c)
            {
                break;
            }
            bottom--;
            for (int i = bottom; i >= top; i--)
            {
                result.push_back(matrix[i][left]);
            }
            if (result.size() == r * c)
            {
                break;
            }
            left++;
        }
        return result;
    }
};
int main()
{
    int n = 3, m = 3;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (auto &r : matrix)
    {
        for (auto &c : r)
        {
            cin >> c;
        }
    }
    Solution sol;
    vector<int> ret = sol.spiralOrder(matrix);
    for (auto n : ret)
    {
        cout << ' ' << n;
    }
}