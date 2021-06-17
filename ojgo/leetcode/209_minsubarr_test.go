package leetcode

/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
这题应该是
*/

import (
	"math"
)
func minSubArrayLen0(target int, nums []int) int {
	curSum := 0
	start:=0
	minLen := 100000
    for idx, v := range(nums) {
		curSum += v
		for curSum>= target && start <= idx{
			if idx-start+1 < minLen {
				minLen = idx - start +1
			}			
			curSum -= nums[start]
			start+=1			
		}
	}
	if minLen == 100000 {
		return 0
	} else {
		return minLen
	}
}

func minSubArrayLen(target int, nums []int) int {
	curSum := 0
	minLen := math.MaxInt32
	start:=0
    for cur:=0;cur<len(nums);cur++ {
		curSum += nums[cur]
		for curSum>= target && start <= cur {
			if cur-start+1 < minLen {
				minLen = cur - start +1
			}			
			curSum -= nums[start]  // ++ not for statement
			start+=1 // ++ only for this, 			
		}
	}
	if minLen == math.MaxInt32 {
		return 0
	} else {
		return minLen
	}
}