/*
We write the integers of nums1 and nums2 (in the order they are given) on two separate horizontal lines.

Now, we may draw connecting lines: a straight line connecting two numbers nums1[i] and nums2[j] such that:

nums1[i] == nums2[j];
The line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting lines cannot intersect even at the endpoints: each number can only belong to one connecting line.

Return the maximum number of connecting lines we can draw in this way.

Input: nums1 = [2,5,1,2,5], nums2 = [10,5,2,1,5,2]
Output: 3
这道题很新颖, 如何建立模型？
貌似一个最大公共子序列的问题...这也太吊了，一次通过
12:00
*/
package leetcode

func maxUncrossedLines(nums1 []int, nums2 []int) int {
	//建立dp
	dp := make([][]int, len(nums1)+1)
	for i := 0; i < len(dp); i++ {
		dp[i] = make([]int, len(nums2)+1)
	}
	//子状态
	//s1[i]==s2[j] ,dp[i][j] = dp[i-1][j-1]+1
	//s1[i]!=s2[j], dp[i][j] = max(dp[i-1][j],dp[i][j-1])
	for i := 1; i <= len(nums1); i++ {
		for j := 1; j <= len(nums2); j++ {
			if nums1[i-1] == nums2[j-1] {
				dp[i][j] = dp[i-1][j-1] + 1
			} else {
				if dp[i-1][j] > dp[i][j-1] {
					dp[i][j] = dp[i-1][j]
				} else {
					dp[i][j] = dp[i][j-1]
				}
			}
		}
	}
	return dp[len(nums1)][len(nums2)]
}
