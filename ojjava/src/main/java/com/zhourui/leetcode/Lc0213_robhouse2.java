package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import static java.lang.Math.max;
//[1,2,3,1]
// 分别计算
// 0..N-1   表示ROB第一家
// 和 1..N  表示ROB最后一家  // 所能取到的最大值
//但问题在于 0..N-1 并不一定就是ROB了第一家，这样有没可能rob了2,4...然后再加上第二个range里的最后一家；而不是取两者最大值
// 不可能，如果去掉了第一家，加上最后一家，那么还是第二种RANGE的结果

public class Lc0213_robhouse2 extends BaseSolution {
    class Solution {
        public int rob(int[] nums) {
            int n = nums.length;
            if (n == 0) return 0;
            if (n == 1) return nums[0];
            int[][] dp = new int[2][nums.length];

            dp[0][0] = nums[0];  // pick 0
            dp[0][1] = max(nums[0],nums[1]);

            dp[1][0] = 0;  //dont pick 0
            dp[1][1] = nums[1];

            for (int i=2; i<n; i++) {
                if (i!=n-1) {
                    dp[0][i] = max(dp[0][i-2]+nums[i],dp[0][i-1]);
                    dp[1][i] = max(dp[1][i-2]+nums[i],dp[1][i-1]);
                } else { // 最后一个元素
                    //dp[0][i] = max(dp[0][i-2]+nums[i],dp[0][i-1]); // 可能带了nums[0]
                    dp[0][i]=0;  // do nothing
                    dp[1][i] = max(dp[0][i-2]+nums[i],dp[0][i-1]); // OK 肯定不带 nums[0]
                }
            }
            return Math.max(dp[0][n-2],dp[1][n-1]);
        }

        //by leetcode
        public int rob1(int[] nums) {
            int n = nums.length;
            if(n==0||nums==null){
                return 0;
            }
            if(n==1){
                return nums[0];
            }

            int[][] dp = new int[n][2]; //1 present contains head , 0 no contains

            dp[0][0] = 0;
            dp[1][0] = nums[1];

            dp[0][1] = nums[0];
            dp[1][1] = nums[0];

            for(int i =2;i<nums.length;i++){
                if(i==nums.length-1){
                    dp[i][0] = Math.max(dp[i-2][0]+nums[i],dp[i-1][0]);
                    dp[i][1] = 0;
                }else{
                    dp[i][0] = Math.max(dp[i-2][0]+nums[i],dp[i-1][0]);
                    dp[i][1] = Math.max(dp[i-2][1]+nums[i],dp[i-1][1]);
                }
            }
            return Math.max(Math.max(dp[n-2][1],dp[n-1][0]),dp[n-2][0]);
        }
    }

    @Override
    public boolean test() {
        boolean ret = true;
        //ret &= (new Solution().rob(new int[]{1, 2, 3, 1})==4);
        ret &= (new Solution().rob(new int[]{2, 1, 3, 5})==6);
        return ret;
    }

}
