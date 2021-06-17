package leetcode

/*
这题想不出什么O(1)的做法,其实仔细做下去正好是O(1)，也是看了别人的答案，惭愧
用stack来实现队列
*/
type MyQueue struct {
    s1 []int
	s2 []int
}


/** Initialize your data structure here. */
func Constructor232() MyQueue {
    return MyQueue{
		s1: []int{},
		s2: []int{},
	}
}


/** Push element x to the back of queue. */
func (this *MyQueue) Push(x int)  {
    this.s1 = append(this.s1, x)
}


/** Removes the element from in front of queue and returns that element. */
func (this *MyQueue) Pop() int {
	// 只有s2为空了才从s1倒东西过来
	if len(this.s2) == 0 {
		for i:=len(this.s1)-1;i>=0;i-- {
			this.s2 = append(this.s2, this.s1[i])
		}
		this.s1 = []int{}
	}

	ret := this.s2[len(this.s2)-1]
	this.s2 = this.s2[:len(this.s2)-1]
	return ret
}


/** Get the front element. */
func (this *MyQueue) Peek() int {
	if len(this.s2) == 0 {
		for i:=len(this.s1)-1;i>=0;i-- {
			this.s2 = append(this.s2, this.s1[i])
		}
		this.s1 = []int{}
	}

	ret := this.s2[len(this.s2)-1]	
	return ret
}


/** Returns whether the queue is empty. */
func (this *MyQueue) Empty() bool {
    return len(this.s1)==0 && len(this.s2)==0
}


/**
 * Your MyQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Peek();
 * param_4 := obj.Empty();
 */