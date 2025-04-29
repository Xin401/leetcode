#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<set<char>> row_check(9), column_check(9);
        vector<vector<set<char>>> grid_check(3, vector<set<char>>(3));
        char c;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                c = board[i][j];
                if (c != '.')
                {
                    if (row_check[i].find(c) != row_check[i].end() || column_check[j].find(c) != column_check[j].end() || grid_check[floor(i / 3)][floor(j / 3)].find(c) != grid_check[floor(i / 3)][floor(j / 3)].end())
                    {
                        return false;
                    }
                    else
                    {
                        row_check[i].insert(c);
                        column_check[j].insert(c);
                        grid_check[floor(i / 3)][floor(j / 3)].insert(c);
                    }
                }
            }
        }
        return true;
    }
};
