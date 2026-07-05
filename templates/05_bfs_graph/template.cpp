
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class BFSGeneralTemplates {
 public:
  // 抽象圖 BFS (給定 Adjacency List)
  int abstractGraphBFS(int startNode, unordered_map<int, vector<int>>& adj) {
    queue<int> q;
    unordered_set<int>
        visited;  // 若節點是 0~N 的連續數字，用 vector<bool> 效能更好

    // 1. 初始化起點
    q.push(startNode);
    visited.insert(startNode);
    int steps = 0;  // 記錄層數

    // 2. 開始擴散
    while (!q.empty()) {
      int size = q.size();  // 鎖定當前層級的節點數

      for (int i = 0; i < size; i++) {
        int curr = q.front();
        q.pop();

        // 處理當前節點，或判斷是否抵達終點
        // if (curr == target) return steps;

        // 3. 走訪所有相鄰節點
        for (int neighbor : adj[curr]) {
          if (visited.find(neighbor) == visited.end()) {  // 若沒走過
            visited.insert(neighbor);  // 加入 queue 的同時立刻標記
            q.push(neighbor);
          }
        }
      }
      steps++;  // 這一層全部擴散完畢，步數 +1
    }
    return -1;  // 找不到目標，或已走遍所有連通節點
  }

  // 二維網格 BFS
  int gridBFS(vector<vector<int>>& grid, int startR, int startC) {
    int rows = grid.size();
    int cols = grid[0].size();

    queue<pair<int, int>> q;
    // 如果可以，直接把 grid[r][c] 改成特殊值當作 visited 省下空間
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  // 上下左右

    // 1. 初始化起點
    q.push({startR, startC});
    visited[startR][startC] = true;
    int steps = 0;

    // 2. 開始擴散
    while (!q.empty()) {
      int size = q.size();

      for (int i = 0; i < size; i++) {
        auto [r, c] = q.front();
        q.pop();

        // 判斷是否抵達終點
        // if (r == targetR && c == targetC) return steps;

        // 3. 往四個方向探測
        for (auto& d : dirs) {
          int nr = r + d[0];
          int nc = c + d[1];

          // 檢查邊界條件
          if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
            // 檢查是否可走 且 未走過
            if (/* grid[nr][nc] 是合法的路 */ true && !visited[nr][nc]) {
              visited[nr][nc] = true;  // 立刻標記
              q.push({nr, nc});
            }
          }
        }
      }
      steps++;
    }
    return -1;
  }
};