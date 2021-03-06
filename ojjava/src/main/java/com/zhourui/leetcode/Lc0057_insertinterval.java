package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import java.util.ArrayList;

import static java.lang.Integer.max;
import static java.lang.Integer.min;

// 这题一眼看上去有类似的,
public class Lc0057_insertinterval extends BaseSolution {
    class Solution {
        public int[][] insert(int[][] intervals, int[] newInterval) {
            ArrayList<int[]> lst= new ArrayList();

            for (int i=0;i<intervals.length;i++) {
                int []tmp = merge(intervals[i],newInterval);
                if (tmp==null) { // no overlap
                    lst.add(intervals[i]);
                } else {
                    newInterval = tmp;
                }
            }
            lst.add(newInterval);
            lst.sort(
                    (p1,p2)-> {
                        if (p1[0]<p2[0]) return -1;
                        if (p1[0]>p2[0]) return 1;
                        return 0;
                    }
            );
            // list 转换为 array
            var ret = lst.toArray(new int[0][]);
            return ret;
        }

        int[] merge(int[] a, int[] b) {
            //这里保证b一定在a后面
            if (a[0]>b[0]) {
                return merge(b,a);
            }
            // 该元素并不一定落在a0,a1之间，那么b在a1之后，无重叠
            if (b[0]>=a[0] && b[0]<=a[1]) {
                return new int[]{a[0],max(a[1],b[1])};
            } else {
                return null;// no overlap
            }
        }
    }

    @Override
    public boolean test() {
        var input=new int[][]{{1,3},{6,9}};
        int[] insert={2,5};
        new Solution().insert(input,insert);
        return true;
    }
}
