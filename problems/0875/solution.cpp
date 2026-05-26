#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  long long count_hour(const vector<int>& piles, const int speed) {
    long long h = 0;
    for (const auto& p : piles) {
      h += (p + speed - 1) / speed;
    }
    return h;
  }
  int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1;
    int right = piles[0];
    for (auto& p : piles) {
      right = max(right, p);
    }
    while (left <= right) {
      int mid = left + (right - left) / 2;
      long long hours = this->count_hour(piles, mid);

      if (hours <= h) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};

int main() {
  vector<int> piles = {805306368, 805306368, 805306368};
  Solution sol;
  cout << sol.minEatingSpeed(piles, 1000000000);
}