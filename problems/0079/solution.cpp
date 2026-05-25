#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool dfs(vector<vector<bool>> traveled, vector<vector<char>>& board, int i,
           int j, string word) {
    if (word.size() == 0) {
      return true;
    }
    if (i != 0 && board[i - 1][j] == word[0] && !traveled[i - 1][j]) {
      // up
      vector<vector<bool>> tmp = traveled;
      tmp[i - 1][j] = true;
      if (dfs(tmp, board, i - 1, j, string(word.begin() + 1, word.end()))) {
        cout << "up" << endl;
        cout << i << j << endl;
        return true;
      }
    }
    // down
    if (i != board.size() - 1 && board[i + 1][j] == word[0] &&
        !traveled[i + 1][j]) {
      vector<vector<bool>> tmp = traveled;
      tmp[i + 1][j] = true;
      if (dfs(tmp, board, i + 1, j, string(word.begin() + 1, word.end()))) {
        cout << "down" << endl;
        cout << i << j << endl;
        return true;
      }
    }
    if (j != 0 && board[i][j - 1] == word[0] && !traveled[i][j - 1]) {
      vector<vector<bool>> tmp = traveled;
      tmp[i][j - 1] = true;
      if (dfs(tmp, board, i, j - 1, string(word.begin() + 1, word.end()))) {
        cout << "left" << endl;
        cout << i << j << endl;
        return true;
      }
    }
    if (j != board[0].size() - 1 && board[i][j + 1] == word[0] &&
        !traveled[i][j + 1]) {
      vector<vector<bool>> tmp = traveled;
      tmp[i][j + 1] = true;
      if (dfs(tmp, board, i, j + 1, string(word.begin() + 1, word.end()))) {
        cout << "right" << endl;
        cout << i << j << endl;
        return true;
      }
    }
    return false;
  }
  bool exist(vector<vector<char>>& board, string word) {
    int height = board.size();
    int width = board[0].size();
    vector<vector<bool>> traveled(height, vector<bool>(width, false));
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        if (board[i][j] == word[0]) {
          vector<vector<bool>> tmp = traveled;
          tmp[i][j] = true;
          if (dfs(tmp, board, i, j, string(word.begin() + 1, word.end()))) {
            cout << i << j;
            return true;
          }
        }
      }
    }
    return false;
  }
};

int main() { return 0; }