#include <cmath>
#include <iostream>
using namespace std;
class Solution {
 public:
  int maxProduct(int n) {
    int m1 = INT_MIN;
    int m2 = INT_MIN;
    while (n != 0) {
      if (n % 10 >= m1) {
        m2 = m1;
        m1 = n % 10;
      } else if (n % 10 >= m2) {
        m2 = n % 10;
      }
      n /= 10;
    }
    return m1 * m2;
  }
};

// int main() {
//   Solution sol;
//   cout << sol.maxProduct(124);
// }