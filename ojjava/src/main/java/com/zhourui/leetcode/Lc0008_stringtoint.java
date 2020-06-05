/**
 * Created by rui.zhou on 04 Jun, 2020
 */
package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

public class Lc0008_stringtoint extends BaseSolution {
    class Solution {
        public int myAtoi(String str) {
            // +-[space], allow  "4193 with words"
            // 超过intmax,min则返回边界,所以需要long 作为ret
            // first not space
            int start = 0;
            while (start<str.length()) {
                if (str.charAt(start)!=' ')
                    break;
                start++;
            }
            if (start>=str.length()) return 0;

            int sign = 1;
            if (str.charAt(start)=='+') {
                sign = 1; start++;
            }  else if (str.charAt(start)=='-') {
                sign = -1; start++;
            }

            long ret = 0;
            for (int i=start;i<str.length();i++) {
                char c = str.charAt(i);
                if (c < '0' || c > '9' )
                    break;
                ret = ret*10+ c-'0';
                if (ret * sign >= Integer.MAX_VALUE) return Integer.MAX_VALUE;
                if (ret * sign <= Integer.MIN_VALUE) return Integer.MIN_VALUE;
            }
            return (int)ret*sign;
        }
    }

    @Override
    public boolean test() {
        Solution slu = new Solution();
        boolean ret = true;
        ret &= slu.myAtoi("-91283472332")==-2147483648;
        ret &= slu.myAtoi("   -42")==-42;
        return ret;
    }
}
