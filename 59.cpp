#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n));
        int top = 0, right = n - 1, bottom = n - 1, left = 0;
        int ptr = 1;
        while (true)
        {
            for (int i = left; i <= right; i++)
            {
                matrix[top][i] = ptr++;
            }
            if (ptr == n * n + 1)
            {
                break;
            }
            top++;
            for (int i = top; i <= bottom; i++)
            {
                matrix[i][right] = ptr++;
            }
            if (ptr == n * n + 1)
            {
                break;
            }
            right--;
            for (int i = right; i >= left; i--)
            {
                matrix[bottom][i] = ptr++;
            }
            if (ptr == n * n + 1)
            {
                break;
            }
            bottom--;
            for (int i = bottom; i >= top; i--)
            {
                matrix[i][left] = ptr++;
            }
            if (ptr == n * n + 1)
            {
                break;
            }
            left++;
        }
        return matrix;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution sol;
    vector<vector<int>> matrix = sol.generateMatrix(n);
    for (auto i : matrix)
    {
        for (auto j : i)
        {
            cout << j << ' ';
        }
        cout << '\n';
    }
}