#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution
{
public:
    // int tribonacci(int n)
    // {
    //     deque<long> trib = {0, 1, 1};
    //     if (n < 3)
    //     {
    //         return trib[n];
    //     }
    //     for (int i = 2; i < n; i++)
    //     {
    //         trib.push_back(trib[0] + trib[1] + trib[2]);
    //         trib.pop_front();
    //     }
    //     return trib.back();
    // }
    int tribonacci(int n)
    {
        vector<long> trib = {0, 1, 1};
        if (n < 3)
        {
            return trib[n];
        }
        vector<vector<int>> mul = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}};
        vector<vector<int>> scalar = multiply(mul, n - 2);
        return scalar[2][0] * trib[0] + scalar[2][1] * trib[1] + scalar[2][2] * trib[2];
    }
    vector<vector<int>> multiply(vector<vector<int>> &mul, int times)
    {
        vector<vector<int>> res(3, vector<int>(3, 0));
        if (times == 1)
        {
            return mul;
        }
        else if (times == 2)
        {
            res[0][0] = mul[0][0] * mul[0][0] + mul[0][1] * mul[1][0] + mul[0][2] * mul[2][0];
            res[0][1] = mul[0][0] * mul[0][1] + mul[0][1] * mul[1][1] + mul[0][2] * mul[2][1];
            res[0][2] = mul[0][0] * mul[0][2] + mul[0][1] * mul[1][2] + mul[0][2] * mul[2][2];
            res[1][0] = mul[1][0] * mul[0][0] + mul[1][1] * mul[1][0] + mul[1][2] * mul[2][0];
            res[1][1] = mul[1][0] * mul[0][1] + mul[1][1] * mul[1][1] + mul[1][2] * mul[2][1];
            res[1][2] = mul[1][0] * mul[0][2] + mul[1][1] * mul[1][2] + mul[1][2] * mul[2][2];
            res[2][0] = mul[2][0] * mul[0][0] + mul[2][1] * mul[1][0] + mul[2][2] * mul[2][0];
            res[2][1] = mul[2][0] * mul[0][1] + mul[2][1] * mul[1][1] + mul[2][2] * mul[2][1];
            res[2][2] = mul[2][0] * mul[0][2] + mul[2][1] * mul[1][2] + mul[2][2] * mul[2][2];
            return res;
        }
        else if (times % 2 == 0)
        {
            res = multiply(mul, times / 2);
            return multiply(res, 2);
        }
        else
        {
            vector<vector<int>> tmp1 = multiply(mul, times / 2);
            vector<vector<int>> tmp = multiply(tmp1, 2);
            res[0][0] = tmp[0][0] * mul[0][0] + tmp[0][1] * mul[1][0] + tmp[0][2] * mul[2][0];
            res[0][1] = tmp[0][0] * mul[0][1] + tmp[0][1] * mul[1][1] + tmp[0][2] * mul[2][1];
            res[0][2] = tmp[0][0] * mul[0][2] + tmp[0][1] * mul[1][2] + tmp[0][2] * mul[2][2];
            res[1][0] = tmp[1][0] * mul[0][0] + tmp[1][1] * mul[1][0] + tmp[1][2] * mul[2][0];
            res[1][1] = tmp[1][0] * mul[0][1] + tmp[1][1] * mul[1][1] + tmp[1][2] * mul[2][1];
            res[1][2] = tmp[1][0] * mul[0][2] + tmp[1][1] * mul[1][2] + tmp[1][2] * mul[2][2];
            res[2][0] = tmp[2][0] * mul[0][0] + tmp[2][1] * mul[1][0] + tmp[2][2] * mul[2][0];
            res[2][1] = tmp[2][0] * mul[0][1] + tmp[2][1] * mul[1][1] + tmp[2][2] * mul[2][1];
            res[2][2] = tmp[2][0] * mul[0][2] + tmp[2][1] * mul[1][2] + tmp[2][2] * mul[2][2];
            return res;
        }
    }
};

int main()
{
    Solution s;
    cout << s.tribonacci(25);
}

/*
和費氏數列相同，但改成3*3的矩陣相乘

費氏數列：
[0,1][F(0)]
[1,1][F(1)]
只要先算
[0,1]
[1,1]
的n次方，再乘上
[F(0)]
[F(1)]
，算n次方的方法是先算n/2次方然後相乘，如果n是奇數，再乘上一次自己=>O(logn) < 原本的作法O(n)
*/