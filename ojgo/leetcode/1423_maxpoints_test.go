package leetcode

/*
Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
思路
这也是一个滑动窗口，不过很难把头尾放到一起滑动,因此，先对左侧k个数做一个presum,然后再和另一侧逐个替换

*/

import (
	"reflect"
	"testing"
)

func maxScore(cardPoints []int, k int) int {
	curSum := 0
	for i := 0; i < k; i++ {
		curSum += cardPoints[i]
	}
	maxSum := curSum
	n := len(cardPoints)
	right := 1
	for k > 0 {
		curSum = curSum - cardPoints[k-1] + cardPoints[n-right]
		if curSum > maxSum {
			maxSum = curSum
		}
		right++
		k--
	}
	return maxSum
}

func Test1423(t *testing.T) {
	ret1 := maxScore([]int{1, 2, 3, 4, 5, 6, 1}, 3)
	exp1 := 12
	if !reflect.DeepEqual(ret1, exp1) {
		t.Errorf("Not Passed, got %v", ret1)
	}

	ret2 := maxScore([]int{2, 2, 2}, 2)
	exp2 := 4
	if !reflect.DeepEqual(ret2, exp2) {
		t.Errorf("Not Passed, got %v", ret1)
	}

	ret3 := maxScore([]int{1, 1000, 1}, 1)
	exp3 := 1
	if !reflect.DeepEqual(ret3, exp3) {
		t.Errorf("Not Passed, got %v", ret1)
	}
}
