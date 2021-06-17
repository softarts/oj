package leetcode


/*
这个做法更好，不要container/list那些依赖
*/
import (
	"fmt"
	"reflect"
	"testing"
)

// use doubly linked list
type Node struct {
	key  int
	val  int
	prev *Node
	next *Node
}

type DoublyLinkedList struct {
	head *Node
	tail *Node
}

func (ll *DoublyLinkedList) Remove(node *Node) {
	if node.prev == nil { // head
		ll.head = node.next
	} else {
		node.prev.next = node.next
	}

	if node.next == nil { // tail
		ll.tail = node.prev
	} else {
		node.next.prev = node.prev
	}
}

func (ll *DoublyLinkedList) Front() *Node {
	//fmt.Println(ll.head)
	return ll.head
}

func (ll *DoublyLinkedList) PushBack(node *Node) {
	if ll.tail != nil { // not empty
		ll.tail.next = node
		node.prev = ll.tail
	} else { // empty
		ll.head = node
		node.prev = nil
	}
	node.next = nil
	ll.tail = node
	//fmt.Println(ll.head)
}

type LRUCache struct {
	cache    map[int]*Node
	ll       *DoublyLinkedList
	capacity int
}

func Constructor(capacity int) LRUCache {
	return LRUCache{
		cache: make(map[int]*Node),
		ll: &DoublyLinkedList{
			head: nil,
			tail: nil,
		},
		capacity: capacity,
	}
}

func (this *LRUCache) Get(key int) int {
	if node, found := this.cache[key]; found {
		this.ll.Remove(node)
		this.ll.PushBack(node)
		return node.val
	} else {
		return -1
	}
}

func (this *LRUCache) Put(key int, value int) {
	if node, found := this.cache[key]; found {
		node.val = value
		node.key = key
		this.ll.Remove(node)
		this.ll.PushBack(node)
		return
	}

	if len(this.cache) == this.capacity {
		todel := this.ll.Front()
		fmt.Println(todel)
		delete(this.cache, todel.key)
		this.ll.Remove(todel)
	}

	node := &Node{
		val: value,
		key: key,
	}

	this.ll.PushBack(node)
	this.cache[key] = node
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */

func Test146a(t *testing.T) {
	obj := Constructor(1)
	obj.Put(1, 1)
	obj.Put(2, 1)
	obj.Put(2, 2)
	ret := obj.Get(2)
	exp := 2
	if !reflect.DeepEqual(ret, exp) {
		t.Errorf("Not Passed, got %v", ret)
	}

}
