package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import static java.lang.Math.*;

//Input: [1,8,6,2,5,4,8,3,7]
//Output: 49
//找出能容纳最多水的两根柱子
//滑动窗口，如何移动？ 必须选择较矮的一侧移动，因为x轴缩小了，较高的一侧移动必然只能得到更差的结果

public class Lc0011_mostwater extends BaseSolution {
    class Solution {
        public int maxArea(int[] height) {
            int maxArea = 0;
            int i=0,j=height.length-1;
            while (i<j) {
                int h = min(height[i],height[j]);
                maxArea = max(maxArea, h*(j-i));
                while (h>=height[i] && i<j) i++;
                while (h>=height[j] && i<j) j--;
            }
            return maxArea;

        }
    }
}
