#include <iostream>
using namespace std;

class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        int idx = word.find(ch);
        if (idx == string::npos)
            return word;
        string prefix = word.substr(0, idx + 1);
        string suffix = word.substr(idx + 1);
        reverse(prefix.begin(), prefix.end());
        return prefix + suffix;
    }
};
int main()
{
    Solution s;
    cout << s.reversePrefix("abcdef", 'd') << endl;
    cout << s.reversePrefix("xyxzxe", 'z') << endl;
    cout << s.reversePrefix("abcd", 'z') << endl;
    return 0;
}