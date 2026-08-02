#include <vector>
using namespace std;

class Solution {
 private:
  void backtrack(vector<int>& piles, int sum_a, int sum_b, bool& a_win,
                 int left, int right, bool a_turn) {
    if (left > right) {
      a_win = (a_win || sum_a > sum_b);
      return;
    }
    if (a_turn) {
      sum_a += piles[left];
      left++;
      backtrack(piles, sum_a, sum_b, a_win, left, right, false);
      left--;
      sum_a -= piles[left];
      sum_a += piles[right];
      right--;
      backtrack(piles, sum_a, sum_b, a_win, left, right, false);
      right++;
      sum_a -= piles[right];
    } else {
      sum_b += piles[left];
      left++;
      backtrack(piles, sum_a, sum_b, a_win, left, right, true);
      left--;
      sum_b -= piles[left];
      sum_b += piles[right];
      right--;
      backtrack(piles, sum_a, sum_b, a_win, left, right, true);
      right++;
      sum_b -= piles[right];
    }
  }

 public:
  bool stoneGame(vector<int>& piles) {
    int sum_a = 0;
    int sum_b = 0;
    bool a_win = false;
    int left = 0;
    int right = piles.size() - 1;
    backtrack(piles, sum_a, sum_b, a_win, left, right, true);
    return a_win;
  }
};
