package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

//[1,1,1,2,2,3],
// 保证每个元素不超过2个,有点混乱
// 遍历每个元素，
public class Lc0080_removeduplicate extends BaseSolution {
    class Solution {
        //如何解决那种前一个元素已经前往填补w位置了，再比较 i-1 没有意义了那种做法？
        //0,0,1,1,1,1,2,3,3 例如2已经往前填补了，比较后面2个3有何意义
//        public int removeDuplicates(int[] nums) {
//            int w = 1;
//            int count = 1;
//            for (int i=1;i<nums.length;i++) {
//                if (nums[i]==nums[i-1]) {
//                    if (count<2) {
//                        count++;
//                        w++;
//                    }
//                }
//                nums[w++] = nums[i];
//            }
//            return w;
//        }

        //思路是需要往w位置写入nums[i],超过COUNT时仍在写入，同时避免前面已经有相同字符了仍在写入（应当跳过）
        // 这个相当于对 同一个位置进行2次处理，1.先看要不要更新count,2,再把它写到w位置
        // 数组的套路就是
        public int removeDuplicates(int[] nums) {
            int w = 1;
            int count = 1;

            for (int i=1;i<nums.length;i++) {
                if (nums[i]!=nums[i-1]) {
                    count = 0;
                }
                if (count<2) {
                    nums[w++] = nums[i];
                    count++;
                }
            }
            return w;
        }
    }

    @Override
    public boolean test() {
        Solution slu = new Solution();
        int arr[] = new int[]{1,1,1,2,2,3};
        int arr2[] = new int[]{0,0,1,1,1,1,2,3,3};
        boolean ret = true;
        ret &= slu.removeDuplicates(arr)==5;
        ret &= slu.removeDuplicates(arr2)==7;
        return ret;
    }
}
