#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    long long count(long long length)
    {
        return (1 + length) * length / 2;
    }
    long long countSubarrays(vector<int> &nums, long long k)
    {
        int ptr1 = 0, ptr2 = 0, last_ptr2 = -1;
        long long current_sum = nums[0], result = 0;
        while (ptr2 <= nums.size())
        {
            if (ptr2 == nums.size())
            {
                result += count(ptr2 - ptr1);
                if (last_ptr2 >= ptr1)
                {
                    result -= count(last_ptr2 - ptr1 + 1);
                }
                break;
            }
            if (current_sum * (ptr2 - ptr1 + 1) >= k)
            {
                result += count(ptr2 - ptr1);
                if (last_ptr2 >= ptr1)
                {
                    result -= count(last_ptr2 - ptr1 + 1);
                }
                last_ptr2 = ptr2 - 1;
                if (ptr1 == ptr2)
                {
                    ptr2 += 1;
                    if (ptr2 < nums.size())
                    {
                        current_sum += nums[ptr2];
                    }
                }
                current_sum -= nums[ptr1];
                ptr1 += 1;
            }
            else
            {
                ptr2 += 1;
                if (ptr2 < nums.size())
                {
                    current_sum += nums[ptr2];
                }
            }
        }
        return result;
    }
};