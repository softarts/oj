//
// Created by rui.zhou on 2/17/2019.
//

/*
 * Given n non-negative integers representing an elevation map where the width of
 * each bar is 1, compute how much water it is able to trap after raining.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 In this case, 6 units of rain water (blue section) are being trapped.
 Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
 */

#include <codech/codech_def.h>
using namespace std;

// 还是要提炼出一个解法呢，才能编码实现。从图上看，就是左右高，中间形成一个低洼才能积水，对于阶梯型的，则一直
// 找到最高的为止，如何用算法实现？
//对于每个点，都记录其leftamx和rightmax，然后在第二次遍历的时候从再比较两者的最小者中
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty())
            return 0;
        vector<int> left(height.size(),0);
        int leftMax = 0;
        left[0]=0;
        for (int i=1;i<height.size();i++) {
            if (leftMax < height[i-1]) {
                leftMax = height[i-1];
            }
            left[i]=leftMax;
        }

        vector<int> right(height.size(),0);
        int rightMax = 0;
        for (int i=height.size()-2;i>=0;i--) {
            if (rightMax < height[i+1]) {
                rightMax = height[i+1];
            }
            right[i]=rightMax;
        }
        int ans = 0;
        for (int i=1;i<height.size()-1;i++) {
            int h = max(min(left[i],right[i]),height[i]);
            ans += h - height[i];
        }
        return ans;
    }
};

DEFINE_CODE_TEST(042_traprainwater)
{
    Solution obj;
    {
        vector<int> h{0,1,0,2,1,0,1,3,2,1,2,1};
        VERIFY_CASE(obj.trap(h),6);
    }
}