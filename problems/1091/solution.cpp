#include <queue>
#include <vector>
using namespace std;

class Solution {
 private:
  int gridBFS(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    queue<pair<int, int>> q;
    int dirs[8][2] = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                      {1, 0},  {1, -1}, {0, -1}, {-1, -1}};

    q.push({0, 0});
    grid[0][0] = -1;
    int steps = 1;

    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        auto [r, c] = q.front();
        q.pop();

        if (r == rows - 1 && c == cols - 1) return steps;

        for (auto& d : dirs) {
          int nr = r + d[0];
          int nc = c + d[1];

          if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
            if (grid[nr][nc] == 0) {
              grid[nr][nc] = -1;
              q.push({nr, nc});
            }
          }
        }
      }
      steps++;
    }
    return -1;
  }

 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if (grid[0][0] == 1) return -1;
    return gridBFS(grid);
  }
};