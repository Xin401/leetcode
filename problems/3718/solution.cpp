#include <vector>
using namespace std;

class Solution {
 public:
  int missingMultiple(vector<int>& nums, int k) {
    bool rec[101] = {false};
    for (auto& n : nums) {
      rec[n] = true;
    }
    int ptr = k;
    while (ptr <= 100) {
      if (!rec[ptr]) {
        return ptr;
      }
      ptr += k;
    }
    return ptr;
  }
};