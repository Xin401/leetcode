#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool checkDivisibility(int n) {
    string n_string = to_string(n);
    int sum = 0;
    int product = 1;
    for (const char d : n_string) {
      int digit = d - '0';
      sum += digit;
      product *= digit;
    }
    return n % (sum + product) == 0;
  }
};