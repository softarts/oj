package leetcode

import (
	"reflect"
	"testing"
	"strconv"
	//"github.com/softarts/ojgo/ojcommon"
)

/*
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
*/

// 逆波兰式

func evalRPN(tokens []string) int {
	stack := []int{}  // implement stack with slice 
	for _, s := range(tokens) {
		if (s=="+" || s=="-" || s=="*" || s=="/") {
			n:=len(stack)
			rhs := stack[n-1]
			lhs := stack[n-2]
			switch (s) {
			case "+":
				stack[n-2] = lhs + rhs
			case "-":
				stack[n-2] = lhs - rhs
			case "*":
				stack[n-2] = lhs * rhs
			case "/":
				stack[n-2] = lhs / rhs				
			}
			stack = stack[:n-1]
		} else {
			val,err:=strconv.Atoi(s)
			if err==nil {
				stack = append(stack, val)
			}
		}
	}
	return stack[0]
}

func Test150(t *testing.T) {
	var ret = evalRPN([]string{"2","1","+","3","*"})
	var exp = 1
	if !reflect.DeepEqual(ret, exp) {
		t.Errorf("Not Passed, got %v", ret)
	}
}

