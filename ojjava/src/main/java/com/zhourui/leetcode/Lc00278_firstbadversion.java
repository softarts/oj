package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import static java.lang.Integer.min;

public class Lc00278_firstbadversion extends BaseSolution {
    class VersionControl {
        boolean isBadVersion(int version) {
            return true;
        }
    }
    public class Solution extends VersionControl {
        public int firstBadVersion(int n) {
            int start=1,end=n;
            while (start<end) {
                int mid = (start+end)/2;
                if (isBadVersion(mid)) {
                    end=mid-1;
                } else {
                    start=mid+1;
                }
            }
            boolean b0=isBadVersion(start);
            boolean b1=isBadVersion(end);
            if (b0&&b1) {
                return min(start,end);
            } else if (b0) {
                return start;
            } else if (b1) {
                return end;
            } else {
                return -1;
            }
        }
    }
}
