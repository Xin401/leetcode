#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> myStack;
        int t1, t2;
        for (const auto &t : tokens)
        {
            if (t == "+")
            {
                t1 = myStack.top();
                myStack.pop();
                t2 = myStack.top();
                myStack.pop();
                myStack.push(t2 + t1);
            }
            else if (t == "-")
            {
                t1 = myStack.top();
                myStack.pop();
                t2 = myStack.top();
                myStack.pop();
                myStack.push(t2 - t1);
            }
            else if (t == "*")
            {
                t1 = myStack.top();
                myStack.pop();
                t2 = myStack.top();
                myStack.pop();
                myStack.push(t2 * t1);
            }
            else if (t == "/")
            {
                t1 = myStack.top();
                myStack.pop();
                t2 = myStack.top();
                myStack.pop();
                myStack.push(int(t2 / t1));
            }
            else
            {
                myStack.push(stoi(t));
            }
        }
        return myStack.top();
    }
};