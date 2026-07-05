#include <vector>
using namespace std;

class Solution {
 private:
  int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  void gridDFS(vector<vector<char>>& board, int r, int c, string word,
               int currentIndex, bool& res) {
    if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() ||
        board[r][c] == '.' || res) {
      return;
    }

    char tmp = board[r][c];
    if (tmp == word[currentIndex]) {
      if (currentIndex == word.size() - 1) {
        res = true;
        return;
      }
      board[r][c] = '.';
      for (auto& d : dirs) {
        gridDFS(board, r + d[0], c + d[1], word, currentIndex + 1, res);
      }
      board[r][c] = tmp;
    }
  }

 public:
  bool exist(vector<vector<char>>& board, string word) {
    bool res = false;
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] == word[0]) {
          gridDFS(board, i, j, word, 0, res);
        }
        if (res) {
          return res;
        }
      }
    }
    return res;
  }
};