package leetcode

/*
就是快慢指针*/

type ListNode struct {
	Val int
	Next *ListNode
}

	
func hasCycle(head *ListNode) bool {
	if (head==nil) {
		return false;
	}
    slow := head
	fast := head
	for fast.Next!=nil && fast.Next.Next!=nil && slow.Next!=nil {
		fast = fast.Next.Next
		slow = slow.Next
		if fast==slow {
			return true
		}
	}
	return false
}


