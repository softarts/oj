/*
You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.



Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
Example 3:

Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.


Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of lowercase English letters.

*/

package leetcode

import (
	//"fmt"
	//"reflect"
	//"testing"
)

// 思路 建立2个map,一个是key为长度，value为list of words,另一个是每个word的计数(m2)
// 然后从小到大检查每个长度的word列表，取各种substr,如果在m2中找到，则更新计数

func longestStrChain(words []string) int {
	lenMap := make(map[int][]string)
	m := make(map[string]int)
	maxLen := 0
	minLen := 1000

	for _, s := range words {
		sl := len(s)
		var arr []string
		var found bool
        if arr, found = lenMap[sl]; found {            
			arr = append(arr, s)
            // lenMap[sl] = arr
            // fmt.Println("add",s,arr)
		} else {
			arr = []string{s}
            // lenMap[sl] = arr
            // fmt.Println("not found",s,arr)
		}
		lenMap[sl] = arr
		
		if sl > maxLen {
			maxLen = sl
		}
		if sl < minLen {
			minLen = sl
		}
		
	}
    // for i:=minLen;i<=maxLen;i++ {
    //     fmt.Println(lenMap[i])
    // }
	ans := 1
	// 从小到大检查每个长度
    //fmt.Println(minLen,maxLen)
	for i:=minLen;i<=maxLen;i++ {
        arr, found := lenMap[i]
        //fmt.Println(arr)
		if !found {
			continue	
		} 		

		for _, s := range(arr) {			
			if _, found := lenMap[i-1]; !found {
				m[s] = 1
			} else {
				count := 1
				for j:=0;j<i;j++ {
					pre := s[:j] + s[j+1:]
					// fmt.Println(pre)
					if _, hasPre := m[pre];hasPre {
						if m[pre]+1 > count {
							count = m[pre]+1
						}
					} 
				}
				m[s] = count
				if count > ans {
					ans = count
				}

			}
		}
	}
	return ans
}