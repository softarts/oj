package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import java.util.*;

//@FunctionalInterface
//public interface ConsumerInterface<T>{
//    void accept(T t);
//}
//    ConsumerInterface<String> func = word -> {
//        System.out.println(word);
//    };

// 思路 6:32
// 因为只需要知道level,考虑BFS的方法，把一个单词每个可能的变化都作为下一层,
// 如果找到存在于列表中，就把放入queue
// 遍历的时候如果修改了容器，iterator可能会失效, 避免使用iterator
public class Lc0127_wordladder extends BaseSolution {
    class Solution {
        // 这个方式比不上for loop的简洁
        public int ladderLength0(String beginWord, String endWord, List<String> wordList) {
            ArrayDeque<String> todo = new ArrayDeque<>();
            HashSet<String> words = new HashSet<>(wordList);
            todo.add(beginWord);
            int level=1;
            while (!todo.isEmpty()) {
                int count = todo.size();
                var iter = todo.iterator();
                int idx=0;
                while (iter.hasNext() && idx < count) {
                    var word = iter.next();
                    if (word.equals(endWord)) {
                        return level;
                    }
                    addNextWord(word, words, todo);
                    idx++;
                    iter.remove();
                    System.out.printf("remove %s", word);
                }
                level++;
            }
            return 0;

        }

        public int ladderLength(String beginWord, String endWord, List<String> wordList) {
            ArrayDeque<String> todo = new ArrayDeque<>();
            HashSet<String> words = new HashSet<>(wordList);
            todo.add(beginWord);
            int level=1;
            while (!todo.isEmpty()) {
                int count = todo.size();
                for (int i=0;i<count;i++) {
                    String word = todo.pop();
                    if (word.equals(endWord)) {
                        return level;
                    }
                    addNextWord(word, words, todo);
                }
                level++;
            }
            return 0;

        }

        private void addNextWord(String word, HashSet<String> words, Queue<String> queue) {
            words.remove(word);
            char []buf=word.toCharArray();
            for (int i=0;i<buf.length;i++) {
                char old = buf[i];
                for (int j=0;j<26;j++) {
                    if (old!='a'+ j ) {
                        buf[i] = (char) ('a' + j);
                        String nextWord = String.valueOf(buf);
                        if (words.contains(nextWord)) {
                            queue.offer(nextWord);
                            words.remove(nextWord);
                        }
                    }
                }
                buf[i] = old;
            }
        }
    }



    @Override
    public boolean test() {
//        List<String> wordList = Arrays.asList("hot","dot","dog","lot","log","cog");
//        String begin="hit";
//        String endWord = "cog";
//        return new Solution().ladderLength(begin,endWord,wordList)==5;

        String begin="qa";
        String endWord = "sq";
        List<String> wordList = Arrays.asList("si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye");
        return new Solution().ladderLength0(begin,endWord,wordList)==5;
    }
}
