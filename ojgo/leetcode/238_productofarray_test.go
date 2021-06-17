package leetcode

/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

IBM apple考题
使用O(1) space
1,2,3,4

*/
func productExceptSelf(nums []int) []int {
	ans:=make([]int, len(nums))
	prod:=1
    for i:=0;i<len(nums);i++ {		
		ans[i] = prod
		prod = prod * nums[i]
	}

	prod=1
	for i:=len(nums)-1;i>=0;i-- {
		ans[i] = ans[i]*prod
		prod = prod * nums[i]
	}
	return ans
}