//
// Created by rui zhou on 2020-01-02.
//

/*
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
Note:

You can assume that you can always reach the last index.
 */
#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        int jump(vector<int>& nums) {
            int minsteps=INT_MAX;

            if (nums.size()==1)
                return 0;

            vector<int> dp(nums.size(),0);
            dp[0]=1;
            int end = nums.size()-1;
            int reach = nums[0];

            for (int i=1;i<nums.size();i++) {
                if (nums[i]+i > reach) {
                    dp[i]=dp[i-1]+1;
                } else {
                    dp[i]=dp[i-1];
                }
                reach = max(reach,nums[i]+i);
                if (reach>=end) {
                    minsteps = min(minsteps,dp[i-1]+1);
                }
            }
            return minsteps;
        }
    };
}


DEFINE_CODE_TEST(045_jumpgame2)
{
    Solution obj;
    {
        vector<int> arr{2,3,1,1,4};
        VERIFY_CASE(obj.jump(arr),2);
    }

    {
        vector<int> arr{0};
        VERIFY_CASE(obj.jump(arr),0);
    }

    {
        vector<int> arr{2,3,3,1,1,5};
        VERIFY_CASE(obj.jump(arr),2);
    }

}
