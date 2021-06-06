/*
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.



Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:

Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [[1,3],[2,3]]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]

这题还是需要一个pq,很难对所有情况进行追踪

*/

package leetcode

import (
	"container/heap"
	"fmt"
)

type PriorityQueue373 [][3]int

func (pq PriorityQueue373) Len() int            { return len(pq) }
func (pq PriorityQueue373) Less(i, j int) bool  { return pq[i][0] < pq[j][0] }
func (pq PriorityQueue373) Swap(i, j int)       { pq[i], pq[j] = pq[j], pq[i] }
func (pq *PriorityQueue373) Push(x interface{}) { *pq = append(*pq, x.([3]int)) }
func (pq *PriorityQueue373) Pop() interface{} {
	v := (*pq)[len(*pq)-1]
	*pq = (*pq)[:len(*pq)-1]
	return v
	// v := (*pq)[0]
	// *pq = (*pq)[1:]
	// return v
}

// top is at the end
// 这题的妙处在于，根据pop出的值，决定下一个取哪个
func kSmallestPairs(nums1 []int, nums2 []int, k int) [][]int {
	if len(nums1) == 0 || len(nums2) == 0 || k <= 0 {
		return nil
	}
	minHeap := PriorityQueue373{}
	for i, v := range nums1 {
		// sum, id1, id2
		minHeap = append(minHeap, [3]int{v + nums2[0], i, 0})
	}
	heap.Init(&minHeap)
	//minHeap.Init()
	ans := make([][]int, 0, k)
	if k > len(nums1)*len(nums2) {
		k = len(nums1) * len(nums2)
	}
	for i := 1; i <= k; i++ {
		//item := minHeap.Pop().([3]int) //这样写的话顺序完全错乱
		item := heap.Pop(&minHeap).([3]int)
		ans = append(ans, []int{nums1[item[1]], nums2[item[2]]})
		fmt.Println(item[0], nums1[item[1]], nums2[item[2]])
		// 由于之前先push了nums1[0..n]+nums2[0]，因此下一个要尝试的应是nums2[0+1] + nums[pop]
		if item[2] < len(nums2)-1 {
			//minHeap.Push([3]int{nums1[item[1]] + nums2[item[2]+1], item[1], item[2] + 1})
			heap.Push(&minHeap, [3]int{nums1[item[1]] + nums2[item[2]+1], item[1], item[2] + 1})
		}
	}
	return ans
}
