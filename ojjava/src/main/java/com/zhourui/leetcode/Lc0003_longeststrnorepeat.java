package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import java.util.Arrays;
import static java.lang.Integer.max;

// 用map记录每个char的计数，遇到重复字符，计算最大长度(start->当前),
// 1.然后重新设置从start到上一个重复字符之间的所有count>0的计数 tmmzuxt   (t->m之间清除计数)
// 2. 或者
public class Lc0003_longeststrnorepeat extends BaseSolution {
    class Solution {
        public int lengthOfLongestSubstring(String s) {
            int []m = new int[256];
            Arrays.fill(m,-1);
            char []chars = s.toCharArray();
            int maxl = 0;
            int start = 0;
            for (int pos=0;pos<chars.length;pos++) {
                if (m[chars[pos]]==-1) { //not in map
                    m[chars[pos]] = pos;
                } else { // int the map
                    if (m[chars[pos]] < start) { // should ignore it
                        maxl = max(maxl,pos-start+1);//start pos no change,update the maxl
                    } else {
                        maxl = max(maxl, pos-start);
                        start = m[chars[pos]]+1;
                    }
                    m[chars[pos]] = pos;
                }
            }
            return maxl;
        }
    }
}
