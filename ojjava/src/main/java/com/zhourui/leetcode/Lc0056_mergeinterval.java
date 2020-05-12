package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

import static java.lang.Integer.max;

// 这道题和57 很像
//Input: [[1,3],[2,6],[8,10],[15,18]]
//Output: [[1,6],[8,10],[15,18]]
//Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
public class Lc0056_mergeinterval extends BaseSolution {
    class Solution {
        public int[][] merge(int[][] intervals) {
            if (intervals.length==0) return intervals;
            Arrays.sort(intervals, new Comparator<int[]>() {
                @Override
                public int compare(int[] o1, int[] o2) {
                    if (o1[0]<o2[0]) return -1;
                    if (o1[0]>o2[0]) return 1;
                    return 0;
                }
            });

            ArrayList<int[]> lst = new ArrayList();
            lst.add(intervals[0]);

            for (int i=1;i<intervals.length;i++) {
                int []a = lst.get(lst.size()-1);
                int []b = intervals[i];

                if (b[0]<=a[1]) {
                    a[1] = max(a[1],b[1]);
                } else {
                    lst.add(b); // no overlap
                }
            }
//            二维数组的第2个维度为什么可以不填？因为源码里给出了，我们只需要a.getClass()得到泛型，也就是得到int[]，并不需要这个数组的长度
//            二维数组的第1个维度为什么可以填0？上面源码分析的第1点已经提到了，传入数组的长度小于list的元素个数size时，是默认使用size作为数组复制的长度
            return lst.toArray(new int[0][]);
        }


    }
}
