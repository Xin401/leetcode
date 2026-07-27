#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m1 = INT64_MIN;
        int m2 = INT64_MIN;
        for(auto& n : nums){
            if (n >= m1){
                m2 = m1;
                m1 = n;
            }
            else if(n >= m2){
                m2 = n;
            }
        }
        return (m1-1)*(m2-1);
    }
};