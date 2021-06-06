package leetcode

/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
Input: x = 123
Output: 321
*/

import (
	"reflect"
	//"fmt"
	"testing"
	"math"
)

func reverse(x int) int {
	ans := 0
	//fmt.Println(len(ans))  // reflect.TypeOf(ans),
	for ;x!=0;x=x/10 {
		ans = ans*10+x%10
	}
	if ans>math.MaxInt32 || ans<math.MinInt32{
		return 0
	} else {
		return int(ans)
	}
	return ans
}

func Test007(t *testing.T) {
	ret1 := reverse(321)
	exp1 := 123
	if !reflect.DeepEqual(ret1, exp1) {
		t.Errorf("Not Passed, got %v", ret1)
	}

	ret2 := reverse(-321)
	exp2 := -123
	if !reflect.DeepEqual(ret2, exp2) {
		t.Errorf("Not Passed, got %v", ret2)
	}

	// 需要处理这个超范围
	ret3 := reverse(1534236469)
	exp3 := 0
	if !reflect.DeepEqual(ret3, exp3) {
		t.Errorf("Not Passed, got %v", ret3)
	}
}




