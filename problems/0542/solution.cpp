#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (mat[i][j] == 0) {
          q.push({i, j});
          visited[i][j] = true;
        }
      }
    }
    int distance = 0;
    while (!q.empty()) {
      distance++;
      int size = q.size();
      for (int i = 0; i < size; i++) {
        auto [r, c] = q.front();
        q.pop();

        for (auto& d : dirs) {
          int nr = r + d[0];
          int nc = c + d[1];
          if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
            if (!visited[nr][nc]) {
              q.push({nr, nc});
              visited[nr][nc] = true;
              mat[nr][nc] = distance;
            }
          }
        }
      }
    }
    return mat;
  }
};