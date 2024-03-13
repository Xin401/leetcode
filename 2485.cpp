#include <iostream>
using namespace std;

class Solution
{
public:
    int pivotInteger(int n)
    {
        for (int i = n; i >= 1; i--)
        {
            if ((1 + i) * i / 2 == (i + n) * (n - i + 1) / 2)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    int input;
    cin >> input;
    cout << sol.pivotInteger(input);
}