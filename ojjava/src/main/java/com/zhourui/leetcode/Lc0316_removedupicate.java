package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import java.util.Stack;

//Input: "bcabc"    Output: "abc"
//Input: "cbacdcbc"   Output: "acdb"
//思路 遍历，
//子过程 - 每发现一个重复字符，搜索前面所有字符c，如果c<重复字符，并且在c之前，则把该c删掉
// 一个例子,从尾部逐个删除,如果删除过一次，就不再删除(不应存在此情况，因为保证每个字符只出现一次)
//https://leetcode.com/problems/remove-duplicate-letters/discuss/76762/Java-O(n)-solution-using-stack-with-detail-explanation
//这个解释写得好,bca....我先保存b,c到stack,然后对于当前处理字符a,满足, stack.peek()>a,并且count(b/c)>0(即后面还有),所以pop stack
//为什么st.pop的时候不减count[c],因为前面加入stack的时候已经减过count了
//只pop stack 的顶，因为保证stack 里的字符已经满足上面的条件，不会出现[g,a], f, g的情况(即嘉可以删除第一个g而未删)，否则g在前一步就要被去掉
//同时需要visited保证该c没有被加入到stack里
// 使用stringbuilder作为stack
//for(char c : chars) {
//        count[c-'a']--;
//        if(visited[c-'a']) {
//        continue;
//        }
//        while(sb.length() > 0 && c <= sb.charAt(sb.length() - 1) && count[sb.charAt(sb.length() - 1)-'a'] > 0) {
//        visited[sb.charAt(sb.length() - 1)-'a'] = false;
//        sb.deleteCharAt(sb.length() - 1);
//        }
//        sb.append(c);
//        visited[c-'a'] = true;
//        }

public class Lc0316_removedupicate extends BaseSolution {
    class Solution {
        public String removeDuplicateLetters(String s) {
            int[] count = new int[26];
            char[] chars = s.toCharArray();
            Stack<Character> st = new Stack<>();

            for(char c : chars) {
                count[c-'a']++;
            }

            boolean[] visited = new boolean[26];
            for (char c: chars) {
                if (--count[c - 'a'] == 0) continue;
                if (visited[c - 'a']) continue;
                while (!st.isEmpty() && st.peek() > c && count[st.peek() - 'a'] > 0) {
                    visited[st.peek() - 'a'] = false;
                    st.pop();
                }
                //stack 已被处理完，加入当前的char
                st.push(c);
                visited[c - 'a'] = true;
            }
            StringBuilder sb = new StringBuilder();
            for(char c : st) {
                sb.append(c);
            }
            return sb.toString();
        }
    }
}
