#include <vector>
using namespace std;

class BacktrackingTemplates {
 public:
  void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& path,
                 vector<vector<int>>& res) {
    if (path.size() == nums.size()) {
      res.push_back(path);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (used[i]) continue;

      // --- A. 做選擇 (記錄狀態) ---
      used[i] = true;
      path.push_back(nums[i]);

      // --- B. 遞迴進入下一層 ---
      backtrack(nums, used, path, res);

      // --- C. 撤銷選擇 (還原狀態，準備走另一個分支) ---
      path.pop_back();
      used[i] = false;
    }
  }

  // 2D
  // 方向陣列：上、下、左、右
  int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  void gridDFS(vector<vector<char>>& grid, int r, int c) {
    // 1. 越界檢查與狀態檢查 (撞牆、越界、或已經走過，直接 return)
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() ||
        grid[r][c] == '0') {
      return;
    }

    // 2. 標記為已訪問 (可以直接修改原陣列省下 visited 空間)
    grid[r][c] = '0';

    // 3. 往四個方向延伸
    for (auto& d : dirs) {
      gridDFS(grid, r + d[0], c + d[1]);
    }
  }
};