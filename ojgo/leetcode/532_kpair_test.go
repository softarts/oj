package leetcode

/*
Input: nums = [1,2,4,4,3,3,0,9,2,3], k = 3
Output: 2
相差3个的pair为 [1,4] [0,3],
注意
1. 有1,4,1的话，不能重复1,4
2. [0 3 6 3] ==> [0 3] [6 3]
10:38
*/

import (
	"reflect"
	"testing"
)

func findPairs(nums []int, k int) int {
	ans := make(map[int]int)
	m := make(map[int]int)

	for i := 0; i < len(nums); i++ {
		n1 := nums[i] - k
		n2 := nums[i] + k
		if _, found := m[n1]; found {
			answer(n1, nums[i], ans)
		}
		if _, found := m[n2]; found {
			answer(nums[i], n2, ans)
		}
		m[nums[i]] = 0
	}
	return len(ans)
}

func answer(p1, p2 int, ans map[int]int) {
	if p1 > p2 {
		answer(p2, p1, ans)
	} else {
		if _, found := ans[p1]; !found {
			ans[p1] = p2
		}
	}
}

func Test532(t *testing.T) {
	type Pair struct {
		test string
		ret  interface{}
		exp  interface{}
	}

	result := []*Pair{}
	result = append(result,
		&Pair{
			test: "findPairs([]int{-1, -2, -3}, 1)",
			ret:  findPairs([]int{-1, -2, -3}, 1),
			exp:  2,
		},
		&Pair{
			test: "findPairs([]int{1,2,4,4,3,3,0,9,2,3}, 3)",
			ret:  findPairs([]int{1, 2, 4, 4, 3, 3, 0, 9, 2, 3}, 3),
			exp:  2,
		},
		&Pair{
			test: "findPairs([]int{1,3,1,5,4}, 0)",
			ret:  findPairs([]int{1, 3, 1, 5, 4}, 0),
			exp:  1,
		},
	)

	for _, r := range result {
		if !reflect.DeepEqual(r.ret, r.exp) {
			t.Errorf("Not Passed, test %s, got %v", r.test, r.ret)
		}
	}
}
