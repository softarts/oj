package leetcode

import (
	"container/heap"
	"fmt"
	"reflect"
	"testing"
)

// priority queue
// 顶在尾部
type PriorityQueue []int

func (pq PriorityQueue) Len() int {
	return len(pq)
}

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i] < pq[j]
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	*pq = append(*pq, x.(int))
}

func (pq *PriorityQueue) Pop() interface{} {
	n := (*pq)[len(*pq)-1]
	*pq = (*pq)[:len(*pq)-1] // pop the last one, it is the root of heap
	return n
}

// 这个实现太慢了
func findKthLargest0(nums []int, k int) int {
	pq := PriorityQueue(nums) // init with slice
	heap.Init(&pq)
	for pq.Len() > k {
		ele := heap.Pop(&pq) // 就是这么做,pop 出pq里最小的那个
		fmt.Println(ele.(int))
	}
	return heap.Pop(&pq).(int)
}

// =============================================================
// func partition(data []int, low, high int) int {
// 	pivot := data[high] //选最后一个元素作为枢纽元
// 	loc := low - 1      //location指向比pivot小的元素段的尾部
// 	for i := low; i < high; i++ {
// 		if data[i] < pivot { //比枢纽元小的元素依次放在前半部分
// 			loc++
// 			data[i], data[loc] = data[loc], data[i]
// 		}
// 	}
// 	data[high], data[loc+1] = data[loc+1], data[high]
// 	return loc + 1
// }

//更好的方法是使用nth_element O(N)
//partition 将所有大于pivot的数都放在右边，小于的都在左边
func partition(data []int, low, high int) int {
	pivot := data[low]
	for low < high {
		for low < high && data[high] >= pivot {
			// fmt.Printf("high=%d, data=%d", high, data[high])
			high--
		}
		data[low] = data[high] // 第一个小于pivot的元素，放到low位置
		for low < high && data[low] <= pivot {
			low++
		}
		data[high] = data[low]
		//fmt.Printf("low=%d, high=%d", low, high)
	}
	data[low] = pivot //high==low
	return low        // 返回low 位置
}

// func partition2(nums []int, start, end int) int {
// 	pivot := nums[start]
// 	left, right := start+1, end

// 	for left <= right {
// 		for left <= right && nums[left] <= pivot {
// 			left++
// 		}
// 		for left <= right && nums[right] > pivot {
// 			right--
// 		}
// 		if left <= right {
// 			nums[left], nums[right] = nums[right], nums[left]
// 		}
// 	}
// 	nums[right], nums[start] = nums[start], nums[right]
// 	return right
// }

func findKthLargest(nums []int, k int) int {
	low := 0
	n := len(nums)
	high := n - 1

	for {
		cut := partition(nums, low, high)
		if cut == n-k {
			return nums[cut]
		} else if cut > n-k {
			high = cut - 1
		} else {
			low = cut + 1
		}
	}
}

func Test215(t *testing.T) {
	var ret = findKthLargest([]int{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4)
	var exp = 4
	if !reflect.DeepEqual(ret, exp) {
		t.Errorf("Not Passed, got %v", ret)
	}
}
