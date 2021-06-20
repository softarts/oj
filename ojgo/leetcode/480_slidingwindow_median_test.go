package leetcode

import (
	"container/heap"
	"fmt"
	"reflect"
	"testing"
)

//lc290 goldman sachs
// 这题用golang做起来有点麻烦，不过可以试一下
// heap只保证顶是最大或最小值，其它节点是无法保证的，因此无法用heap来实现
type MaxHeap480 []int

func (pq MaxHeap480) Len() int           { return len(pq) }
func (pq MaxHeap480) Less(i, j int) bool { return pq[i] > pq[j] }
func (pq MaxHeap480) Swap(i, j int)      { pq[i], pq[j] = pq[j], pq[i] }
func (pq *MaxHeap480) Push(x interface{}) {
	*pq = append(*pq, x.(int))
	//fmt.Println("Push")
	//pq.Debug()
	//fmt.Printf("Pop %d\n", )

}
func (pq *MaxHeap480) Pop() interface{} {
	v := (*pq)[len(*pq)-1]
	// fmt.Printf("Pop %d\n", v)
	//诡异，在这里的顺序和直接访问pq的顺序不一样
	*pq = (*pq)[:len(*pq)-1]
	fmt.Println("Pop")
	pq.Debug()
	return v
}
func (pq *MaxHeap480) Mid() float64 {
	l := len(*pq)
	if l%2 == 0 {
		return float64((*pq)[(l-1)/2]+(*pq)[l/2]) / 2.0
	} else {
		return float64((*pq)[l/2])
	}
}

func (pq *MaxHeap480) Remove(x interface{}) {
	toBeRemoved := x.(int)
	for j := 0; j < pq.Len(); j++ {
		if (*pq)[j] == toBeRemoved {
			(*pq) = append((*pq)[:j], (*pq)[j+1:]...)
			//heap.Init(pq)
			break
		}
	}
}

func (pq *MaxHeap480) Debug() {
	fmt.Printf(" %d =>", (*pq)[len(*pq)-1])
	for j := 0; j < pq.Len(); j++ {
		fmt.Printf(" %d ", (*pq)[j])
	}
	fmt.Println("")
}

func medianSlidingWindow(nums []int, k int) []float64 {
	ans := []float64{}
	if len(nums) == 0 {
		return ans
	}
	ma := MaxHeap480(nums[:k])
	heap.Init(&ma)
	ma.Debug()
	for i := k; ; i++ {
		if i == len(nums) {
			return ans
		}
		v := nums[i]
		fmt.Printf("Add %f\n", ma.Mid())
		ans = append(ans, ma.Mid())
		heap.Push(&ma, v)
		ma.Remove(nums[i-k])
		heap.Init(&ma)
		ma.Debug()
	}

}
func testheap(nums []int, k int) int {
	ma := MaxHeap480(nums)
	heap.Init(&ma)
	ma.Debug()
	heap.Pop(&ma)
	ma.Debug()
	return 0
}

func Test480(t *testing.T) {
	type Pair struct {
		test string
		ret  interface{}
		exp  interface{}
	}

	result := []*Pair{}
	result = append(result,
		&Pair{
			test: "1",
			ret:  medianSlidingWindow([]int{1, 3, -1, -3, 5, 3, 6, 7}, 3),
			exp:  []float64{1.00000, -1.00000, -1.00000, 3.00000, 5.00000, 6.00000},
		},
		// &Pair{
		// 	test: "1",
		// 	ret:  testheap([]int{1, 3, -1, -3, 5, 3, 6, 7}, 3),
		// 	exp:  0,
		// },
	)

	for _, r := range result {
		if !reflect.DeepEqual(r.ret, r.exp) {
			t.Errorf("Not Passed, test %s, got %v", r.test, r.ret)
		}
	}
}
