#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  int minimumPushes(string word) {
    int cnt[26] = {0};
    for (auto& c : word) {
      cnt[c - 'a']++;
    }
    vector<int> freq;
    for (int& f : cnt) {
      if (f != 0) {
        freq.push_back(f);
      }
    }
    sort(freq.begin(), freq.end(), greater<int>());
    int ret = 0;
    for (int i = 0; i < freq.size(); i++) {
      ret += freq[i] * ((i / 8) + 1);
    }
    return ret;
  }
};