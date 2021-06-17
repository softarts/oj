package leetcode

import (
	"math"
	"reflect"
	"testing"
)

// func shortestSubarray(nums []int, k int) int {
// 	curSum := 0
// 	start := 0
// 	minLen := math.MaxInt32
// 	for cur := start; cur < len(nums); cur++ {
// 		if curSum+nums[cur] < 0 {
// 			curSum = 0
// 			start = cur + 1 // ???
// 		} else {
// 			curSum += nums[cur]
// 		}

// 		for curSum >= k && start <= cur {
// 			if cur-start+1 < minLen {
// 				minLen = cur - start + 1
// 			}
// 			curSum -= nums[start]
// 			start += 1 // inc
// 		}
// 	}
// 	if minLen == math.MaxInt32 {
// 		return -1
// 	} else {
// 		return minLen
// 	}
// }
/*

原先参照209的这个算法有问题，因为中途有负数，子循环无法处理,必须要去掉curSum>=k这个条件，那么复杂度就是N^2
84, -37, 32, 40, 95

lc76类似,要灵活运用queue sliding window
1.先计算presum,
2.往queue中放入idx, 为了计算方便，在前面放入一个0，将presum第一个元素(id=0)移位为1, 如果第一个元素就满足>=k，那么长度=1-0=1，即为1
3.如何维护这个queue，
	(a) 假如中途有负数,会导致presum后来的元素小于前面的，这个时候需要移除前面的元素，只保留最小的。因为前面大的元素对判断已无意义。 如果presum[0]>presum[p1]<presum[2],那么presum[2]-presum[1]为更优解
	(b) 如果presum递增，那就继续添加到queue中
4 找到符合条件的最小长度，首先判断当前idx和queue[0]的presum的差值，如果满足，再把queue popup,由于queue是有序，所以pop后存在退出条件
*/
func shortestSubarray(nums []int, k int) int {
	presum := make([]int, len(nums)+1)

	for i := 1; i <= len(nums); i++ {
		presum[i] = presum[i-1] + nums[i-1]
	}

	q := []int{0}
	minLen := math.MaxInt32
	for i := 1; i < len(presum); i++ {
		curSum := presum[i]
		for len(q) != 0 && curSum-presum[q[0]] >= k {
			if minLen >= (i - q[0]) {
				minLen = i - q[0]
			}
			q = q[1:]
		}

		for len(q) != 0 && curSum < presum[q[len(q)-1]] {
			q = q[:len(q)-1]
		}
		q = append(q, i)
	}

	if minLen == math.MaxInt32 {
		return -1
	} else {
		return minLen
	}

}

func Test862(t *testing.T) {
	ret1 := shortestSubarray([]int{1}, 1)
	exp1 := 1
	if !reflect.DeepEqual(ret1, exp1) {
		t.Errorf("Not Passed, got %v", ret1)
	}

	// ret1 := shortestSubarray([]int{84, -37, 32, 40, 95}, 167)
	// exp1 := 3
	// if !reflect.DeepEqual(ret1, exp1) {
	// 	t.Errorf("Not Passed, got %v", ret1)
	// }
}
