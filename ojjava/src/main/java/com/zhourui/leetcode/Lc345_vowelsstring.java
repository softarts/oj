package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import java.util.Arrays;
import java.util.HashSet;
import java.lang.Character.*;

public class Lc345_vowelsstring extends BaseSolution {
    class Solution {
        public String reverseVowels(String s) {
            StringBuilder sbt= new StringBuilder(s);

            HashSet<Character> vowels = new HashSet(Arrays.asList('a','e','i','o','u'));

            int start=0,end=s.length()-1;
            while (start<end) {
                //toUpperCase()
                //char Character.toLowerCase();
                while (start<s.length() && !vowels.contains(Character.toLowerCase(s.charAt(start)))) {
                    start++;
                }
                while (end>0 && !vowels.contains(Character.toLowerCase(s.charAt(end)))) {
                    end--;
                }
                if (start<end) {
                    sbt.setCharAt(start,s.charAt(end));
                    sbt.setCharAt(end,s.charAt(start));
                }
                start++;end--;
            }
            return sbt.toString();
        }
    }
}
