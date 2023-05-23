#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class KthLargest
{
    multiset<int> ms;
    int kth;

public:
    KthLargest(int k, vector<int> &nums)
    {
        this->kth = k;
        this->ms.insert(nums.begin(), nums.end());
    }
    int add(int val)
    {
        if (this->ms.size() < kth)
        {
            this->ms.insert(val);
            multiset<int>::iterator it = this->ms.begin();
            for (int i = 0; i < this->ms.size() - kth; i++)
                it++;
            return *it;
        }
        multiset<int>::iterator it = ms.begin();
        for (int i = 0; i < this->ms.size() - kth; i++)
            it++;
        if (val > *it)
        {
            this->ms.insert(val);
            it++;
        }
        return *it;
    }
};

int main()
{
}
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */