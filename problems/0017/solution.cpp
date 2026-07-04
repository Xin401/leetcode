#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 private:
  unordered_map<char, vector<char>> mp = {
      {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
      {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
      {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
      {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}};
  void backtrack(string& digits, int startIndex, string& path,
                 vector<string>& res) {
    if (startIndex == digits.size()) {
      res.push_back(path);
      return;
    }
    for (int i = 0; i < mp[digits[startIndex]].size(); i++) {
      path += mp[digits[startIndex]][i];
      backtrack(digits, startIndex + 1, path, res);
      path.erase(path.end() - 1);
    }
  }

 public:
  vector<string> letterCombinations(string digits) {
    string path = "";
    vector<string> res;
    backtrack(digits, 0, path, res);
    return res;
  }
};

// int main() {
//   string digits = "23";
//   Solution sol;
//   sol.letterCombinations(digits);
// }