#include <iostream>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int count = 0;
        bool flag = true;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == ' ' && flag)
            {
                continue;
            }
            else if (s[i] == ' ' && !flag)
            {
                break;
            }
            else
            {
                count++;
                flag = false;
            }
        }
        return count;
    }
};

int main()
{
    Solution solution;
    cout << solution.lengthOfLastWord("Hello World") << endl;
    return 0;
}