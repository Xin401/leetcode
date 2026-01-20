int calculate(int left,int right,int bottom)
{
    return min(left,right)*bottom;
}
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int left = 0;
        int right = height.size()-1;
        while(left<right)
        {
            ans = max(ans,calculate(height[left],height[right],right-left));
            if(height[left]>height[right])
            {
                right--;
            }
            else if(height[right]>height[left])
            {
                left++;
            }
            else
            {
                right--;
                left++;
            }
        }
        return ans;
    }
};