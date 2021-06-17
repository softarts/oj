// Given a string s of '(' , ')' and lowercase English characters.

// Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

// Formally, a parentheses string is valid if and only if:

// It is the empty string, contains only lowercase characters, or
// It can be written as AB (A concatenated with B), where A and B are valid strings, or
// It can be written as (A), where A is a valid string.

// Example 1:

// Input: s = "lee(t(c)o)de)"
// Output: "lee(t(c)o)de"
// Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
// Example 2:

// Input: s = "a)b(c)d"
// Output: "ab(c)d"
// Example 3:

// Input: s = "))(("
// Output: ""
// Explanation: An empty string is also valid.
// 思路 只要使()成对即可
package leetcode

import (
	// "fmt"
	// "reflect"
	"strings"
)

func minRemoveToMakeValid(s string) string {
	//fmt.Println(reflect.TypeOf(s[0]))	==>uint8
	// 一个stack
	left := []int{}

	// 使用一个数组，绝,这样可以方便的remove和join
	out := make([]string, len(s))

	for i, r := range s {
		c := string(r)
		switch c {
		case "(":
			left = append(left, i)
			out[i] = c
		case ")":
			if len(left) > 0 {
				left = left[:len(left)-1] // pair, pop
				out[i] = c
			} else {
				out[i] = "" // remove
			}
		default:
			out[i] = c
		}
	}
	for _, idx := range left {
		out[idx] = "" // remove
	}
	return strings.Join(out, "")
}
