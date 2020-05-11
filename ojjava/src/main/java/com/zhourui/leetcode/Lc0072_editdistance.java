package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

//Insert a character
//        Delete a character
//        Replace a character
//        Example 1:
//
//        Input: word1 = "horse", word2 = "ros"
//        Output: 3
//        Explanation:
//        horse -> rorse (replace 'h' with 'r')
//        rorse -> rose (remove 'r')
//        rose -> ros (remove 'e')

// 和wodladder类似?
// 还是有差异的，因为需要考虑每个字符之间的差异


public class Lc0072_editdistance extends BaseSolution {
    class Solution {
        public int minDistance(String word1, String word2) {
            //insert
            int level=0;
            if (word1.length()<word2.length()) {
                //if ((word1))
                word2.
                int pos = word1.length();

                String insWord = new StringBuilder(word).append(target.charAt(pos)).toString();
                if (!words.contains(insWord)) {
                    queue.offer(insWord);
                }
                return;
            }


            LinkedList<String>  todo = new LinkedList<>();
            HashSet<String> words = new HashSet<>();
            todo.add(word1);
            int level=1;
            while (!todo.isEmpty()) {
                int count = todo.size();
                for (int i=0;i<count;i++) {
                    String word = todo.pop();
                    if (word.equals(word2)) {
                        return level;
                    }
                    addNextWord(word, words, todo,word2);
                }
                level++;
            }
            return 0;
        }

        private void replace(String word, HashSet<String> words, Queue<String> queue,String target) {
            if (word.length() == target.length()) {
                char []buf=word.toCharArray();
                for (int i=0;i<word.length();i++) {
                    if (buf[i]!=target.charAt(i)) {
                        char old = buf[i];
                        buf[i] = target.charAt(i);
                        String replWord = String.valueOf(buf);
                        if (!words.contains(replWord)) {
                            queue.offer(replWord);
                        }
                        buf[i] = old;
                    }
                }

            }
        }

        private void addNextWord(String word, HashSet<String> words, Queue<String> queue,String target) {


            for (int i=0;i<word.length();i++) {
                // delete a character
                if (word.length() > target.length()) {
                    String delWord = new StringBuilder(word).deleteCharAt(i).toString();
                    if (!words.contains(delWord)) {
                        queue.offer(delWord);
                    }
                }




            }
            if (word.length()<target.length()) {
                for (int j = 0; j < 26; j++) {
                    String insWord = new StringBuilder(word).append('a' + j).toString();
                    if (!words.contains(insWord)) {
                        queue.offer(insWord);
                    }
                }
            }
        }
    }

    @Override
    public boolean test() {
        var slu=new Solution();
        return slu.minDistance("horse","ros")==3;
    }
}
