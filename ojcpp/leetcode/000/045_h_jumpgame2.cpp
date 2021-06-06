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

// 思路， 和055有些类似，需要判断每个位置能否走的更远，同时需要记录每一个位置所需要的最少steps

#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        int jump(vector<int>& nums) {
            int minsteps=INT_MAX;

            if (nums.size()==1)
                return 0;

            vector<int> dp(nums.size(),INT_MAX);
            dp[0]=0;
            int end = nums.size()-1;
            int maxDistance = 0;//nums[0];

            for (int i=0;i<nums.size();i++) {
                auto distance = nums[i]+i;

                //如果走得更远，就记录
                if (distance > maxDistance) {
                    //这里更新当前能走到的范围内的，数组每个位置上所需的的最少步数，如果比现有的多，就不更新
                    for (int j=i+1;j<=min(end,distance) ;j++) {
                        dp[j] = min(dp[j],dp[i]+1);
                    }
                }

                maxDistance = max(maxDistance,distance);
                //如果到达终点，需要刷新一下最少步数
                if (maxDistance>=end) {
                    minsteps = min(minsteps,dp[i]+1);
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
