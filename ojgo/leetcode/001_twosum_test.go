package leetcode

import (
	"reflect"
	"testing"
)



func twoSum(nums []int, target int) []int {
	tmpMap := make(map[int]int)
	for i, num := range nums {
		if _, ok := tmpMap[target-num]; ok {
			return []int{tmpMap[target-num], i}
		}
		tmpMap[num] = i
	}
	return []int{}
}



func Test001(t *testing.T) {
	var ret = twoSum([]int{2, 7, 11, 15},9)
	var exp = []int{0,1}
	if !reflect.DeepEqual(ret, exp) {
		t.Errorf("Not Passed, got %v", ret)
	}
}
