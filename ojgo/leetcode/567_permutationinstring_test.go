package leetcode

/*
Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
12:02
lc76?
submit 4 times xxxxx
*/

import (
	"fmt"
	"reflect"
	"testing"
)

func checkInclusion(s1 string, s2 string) bool {
	m := make(map[byte]int)
	for i := 0; i < len(s1); i++ {
		m[s1[i]] += 1
	}
	left := 0
	w := len(s1)
	count := w
	for i := 0; i < len(s2); i++ {
		c := s2[i]
		if _, found := m[c]; found {
			//if m[c] > 0 {
			m[c]--
			if m[c] >= 0 {
				count--
			}
		}
		fmt.Println(left, i, count)
		if i-left+1 > w {
			if _, found := m[s2[left]]; found {
				m[s2[left]] += 1
				if m[s2[left]] > 0 {
					count++
				}
			}
			left++
			fmt.Println("move lft")
		}

		if count == 0 { //found
			return true
		}

	}
	return false
}

func Test567(t *testing.T) {
	type Pair struct {
		test string
		ret  interface{}
		exp  interface{}
	}

	result := []*Pair{}
	result = append(result,
		// &Pair{
		// 	test: "",
		// 	ret:  checkInclusion("adc", "dcda"),
		// 	exp:  true,
		// },
		// &Pair{
		// 	test: "",
		// 	ret:  checkInclusion("ab", "eidbaooo"),
		// 	exp:  true,
		// },
		// &Pair{
		// 	test: "",
		// 	ret:  checkInclusion("ab", "eidboaooo"),
		// 	exp:  false,
		// },
		// &Pair{
		// 	test: "4",
		// 	ret:  checkInclusion("hello", "ooolleoooleh"),
		// 	exp:  false,
		// },
		&Pair{
			test: "5",
			ret:  checkInclusion("abcdxabcde", "abcdeabcdx"),
			exp:  true,
		},
	)

	for _, r := range result {
		if !reflect.DeepEqual(r.ret, r.exp) {
			t.Errorf("Not Passed, test %s, got %v", r.test, r.ret)
		}
	}
}
