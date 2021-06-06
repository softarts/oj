/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
这题是一个DP题·，但却不需要用dp，只要用一个来memo即可
*/
package leetcode
import (	
	"reflect"
	"testing"
)

func maxSubArray(nums []int) int {
	if len(nums)==0  {
		return 0
	}
    maxSum := nums[0]
	curSum := nums[0]
	for i:=1;i<len(nums);i++ {
		if curSum+nums[i] < nums[i] || curSum+nums[i]<0 {
			curSum = nums[i]
		} else {
			curSum += nums[i]
		}
		if curSum > maxSum {
			maxSum = curSum
		}
	}
	return maxSum
}

func Test053(t *testing.T) {
	var ret1 = maxSubArray([]int{-2,1,-3,4,-1,2,1,-5,4})
	var exp1 = 6
	if !reflect.DeepEqual(ret1, exp1) {
		t.Errorf("Not Passed, got %v", ret1)
	}
}


