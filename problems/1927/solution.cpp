#include <iostream>
#include <string>
using namespace std;
class Solution {
 public:
  bool sumGame(string num) {
    int left_sum = 0;
    int left_qu = 0;
    int right_sum = 0;
    int right_qu = 0;
    for (int i = 0; i < num.size() / 2; i++) {
      if (num[i] == '?') {
        left_qu += 1;
      } else {
        left_sum += int(num[i]) - int('0');
      }
    }
    for (int i = num.size() / 2; i < num.size(); i++) {
      if (num[i] == '?') {
        right_qu += 1;
      } else {
        right_sum += int(num[i]) - int('0');
      }
    }

    if ((left_qu + right_qu) % 2 == 1) {
      return true;
    } else if ((left_sum - right_sum) == 4.5 * (right_qu - left_qu)) {
      return false;
    } else {
      return true;
    }
  }
};