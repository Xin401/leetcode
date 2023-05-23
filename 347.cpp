#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second > b.second;
}

class Solution
{
private:
    map<int, int> m;
    map<int, int>::iterator it;
    int kth;

public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        for (auto i : nums)
        {
            this->it = this->m.find(i);
            if (this->it != this->m.end())
            {
                m[i]++;
            }
            else
            {
                this->m.insert(pair<int, int>(i, 1));
            }
        }
        vector<pair<int, int>> vec(this->m.begin(), this->m.end());
        sort(vec.begin(), vec.end(), comp);
        vector<int> ret(k);
        for (int i = 0; i < k; i++)
        {
            ret[i] = vec[i].first;
        }
        return ret;
    }
};

int main()
{
}