#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        this->first_rotate(matrix);
        this->second_rotate(matrix);
    }
private:
    void print_matrix(vector<vector<int>>& matrix) {
        for(const auto & v : matrix) {
            for(const auto & n : v) {
                cout << n << ',';
            }
            cout << endl;
        }
    }
    void first_rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < m; j ++)
            {
                if( i == j ) break;
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    void second_rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int mid = m / 2;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < m; j ++)
            {
                if( j == mid ) break;
                swap(matrix[i][j], matrix[i][m - 1 - j]);
            }
        }
    }
};

int main() {
    Solution sol;
    // vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> matrix = {{5,1,9,11}, {2,4,8,10}, {13,3,6,7},{15,14,12,16}};
    sol.rotate(matrix);
}