//
// Created by Rui Zhou on 29/3/18.
//

/*
 * https://leetcode.com/problems/maximum-subarray/description/
 * Find the contiguous subarray within an array (containing at least one number)
 * which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
max sum subarray
click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer
 approach, which is more subtle.

 HHT031
遍历的方法:一旦累计sum为负数，就需要放弃，否则都能对maxsum有正影响
 DP
f(i)=
 (a) data[i] (f(i-1)<0)
 (b) f(i-1)+data(i) f(i-1)>0




 */
#include <codech/codech_def.h>

using namespace std;
namespace {
    class Solution {
    public:
        //iterate
        int maxSubArray(vector<int> &nums) {
            int maxsum = nums[0], cursum = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                cursum = max(nums[i], cursum + nums[i]);
                maxsum = max(cursum, maxsum);
            }
            return maxsum;
        }
    };

    class Solution1 {
    public:
        // dp 记住当前最大值,实际上我们只需要上一个dp[i-1]，所以用变量取代
        int maxSubArray(vector<int> &nums) {
            vector<int> dp(nums.size(), 0);
            int maxsum = nums[0];
            dp[0] = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                dp[i] = max(dp[i - 1] + nums[i], nums[i]);
                maxsum = max(dp[i], maxsum);
            }
            return maxsum;
        }
    };
}


    // divide and conquer
//    int maxSubArray(vector<int>& nums) {
//        int maxsum = nums[0],cursum = nums[0];
//        for (int i=1;i<nums.size();i++) {
//            cursum = max(nums[i],cursum+nums[i]);
//            maxsum = max(cursum, maxsum);
//        }
//        return maxsum;
//    }


DEFINE_CODE_TEST(053_maximum_subarray)
{
    Solution obj;
    {
        vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
        VERIFY_CASE(obj.maxSubArray(nums),6);
    }
}