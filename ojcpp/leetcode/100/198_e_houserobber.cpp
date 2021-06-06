//
// Created by rui.zhou on 1/26/2019.
//

/*
 * https://leetcode.com/problems/house-robber/
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
 * the only constraint stopping you from robbing each of them is that adjacent houses have security system connected
 * and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.

抢房子，不能抢连续的，否则会出动警察，如何使得抢到的价值最大
判断，使用递归的办法,O(N^2)
memo 的解法?
 */

#include <codech/codech_def.h>
using namespace std;
namespace {
    class Solution {
    public:
        // TLE
        int dfs(vector<int> &nums, int pos) {
            if (pos > nums.size() - 1)
                return 0;
            return max(nums[pos] + dfs(nums, pos + 2), dfs(nums, pos + 1));
        }

        int rob(vector<int> &nums) {
            if (nums.empty())
                return 0;
            return dfs(nums, 0);
        }
    };

    // dp(n+1)，对于每个元素，可以选择
    // dp[i-1]+nums[i],
    // 或者跳过本身, dp[i]
    //多了dp[0]是因为第一个元素要处理
    class Solution1 {
    public:
        int rob(vector<int> &nums) {
            if (nums.empty())
                return 0;
            vector<int> memo(nums.size() + 1);
            memo[0] = 0;
            memo[1] = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                int val = nums[i];
                memo[i + 1] = max(memo[i], memo[i - 1] + val);
            }
            return memo[nums.size()];
        }
    };
};

    // dp + memo solution
    /*
     * public int rob(int[] nums) {
    if (nums.length == 0) return 0;
    int[] memo = new int[nums.length + 1];
    memo[0] = 0;
    memo[1] = nums[0];
    for (int i = 1; i < nums.length; i++) {
        int val = nums[i];
        memo[i+1] = Math.max(memo[i], memo[i-1] + val);
    }
    return memo[nums.length];
}
     */



DEFINE_CODE_TEST(198_houserobber)
{
    Solution1 obj;
    {
        vector<int> nums{2,7,9,3,1,};
        VERIFY_CASE(obj.rob(nums),12);
    }
    {
        vector<int> nums{2,9,6,3,4};
        VERIFY_CASE(obj.rob(nums),13);
    }
    {
        vector<int> nums{};
        VERIFY_CASE(obj.rob(nums),0);
    }
    {
        vector<int> nums{114,117,207,117,235,82,90,67,143,146,53,108,200,91,80,223,58,170,110,236,81,90,222,160,165,195,187,199,114,235,197,187,69,129,64,214,228,78,188,67,205,94,205,169,241,202,144,240};
        VERIFY_CASE(obj.rob(nums),989);
    }

}
