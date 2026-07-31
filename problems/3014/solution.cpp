#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int minimumPushes(string word) {
    int ret = 0;
    int cnt[26] = {0};
    for (auto& c : word) {
      cnt[c - 'a']++;
    }
    vector<int> frequency;
    for (auto& f : cnt) {
      if (f > 0) {
        frequency.push_back(f);
      }
    }
    sort(frequency.begin(), frequency.end(), greater<int>());
    for (int i = 0; i < frequency.size(); i++) {
      ret += frequency[i] * (i / 8) + 1;
    }
    return ret;
  }
};