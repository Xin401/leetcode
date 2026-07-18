#include <vector>
using namespace std;

class Solution {
 private:
  int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

 public:
  int findGCD(vector<int>& nums) {
    int min = INT_MAX;
    int max = INT_MIN;
    for (auto& n : nums) {
      min = n < min ? n : min;
      max = n > max ? n : max;
    }
    return gcd(min, max);
  }
};