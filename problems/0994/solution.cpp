#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int steps = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (grid[i][j] == 2) {
          q.push({i, j});
          steps = -1;
        }
      }
    }
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        auto [r, c] = q.front();
        q.pop();
        for (auto& d : dirs) {
          int nr = r + d[0];
          int nc = c + d[1];
          if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
            if (grid[nr][nc] == 1) {
              q.push({nr, nc});
              grid[nr][nc] = 2;
            }
          }
        }
      }
      steps++;
    }

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (grid[i][j] == 1) {
          return -1;
        }
      }
    }

    return steps;
  }
};