#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int n = dominoes.size();
        vector<int> right_force(n, 0), left_force(n, 0);
        int right = 0, left = 0;
        string result = "";
        for (int i = 0; i < n; i++)
        {
            if (dominoes[i] == '.')
            {
                right -= (right > 0 ? 1 : 0);
            }
            else if (dominoes[i] == 'R')
            {
                right = n;
            }
            else
            {
                right = 0;
            }
            if (dominoes[n - i - 1] == '.')
            {
                left -= (left > 0 ? 1 : 0);
            }
            else if (dominoes[n - i - 1] == 'L')
            {
                left = n;
            }
            else
            {
                left = 0;
            }
            right_force[i] = right;
            left_force[n - i - 1] = left;
        }
        for (int i = 0; i < n; i++)
        {
            if (right_force[i] > left_force[i])
            {
                result += 'R';
            }
            else if (right_force[i] < left_force[i])
            {
                result += 'L';
            }
            else
            {
                result += '.';
            }
        }
        return result;
    }
};