package leetcode

/*
按照使用频率来evict
思路
map[key]*Node
map[count] *list.List，默认使用interface{}作为value
这题足足写了半个多小时

*/

import (
	"container/list"
)
type DataNode struct {	
	key int
	val int
	count int
	llNode *list.Element
}


type LFUCache struct {
	cache map[int]*DataNode
	freq  map[int]*list.List
	capacity int
	minCount int
}


func Constructor460(capacity int) LFUCache {
    return LFUCache{
		cache: make(map[int]*DataNode),
		freq:  make(map[int]*list.List),
		capacity: capacity,
		minCount: 0,
	}
}

func (this *LFUCache) change(node *DataNode) {
	curCount := node.count
    newCount := node.count+1
    node.count++
	this.freq[curCount].Remove(node.llNode)
	if this.freq[curCount].Len() == 0 && this.minCount == curCount {
		delete(this.freq, curCount)
		this.minCount = newCount
	}

	this.addFreq(newCount,node)
}

func (this *LFUCache) addFreq(newCount int, node *DataNode) {
	// add
	if lst, found := this.freq[newCount];found {
		node.llNode = lst.PushBack(node.key)		
	} else {
		newLst := list.New()
		this.freq[newCount] = newLst 
		node.llNode = newLst.PushBack(node.key)	
	}	
}


func (this *LFUCache) Get(key int) int {
    if node, found := this.cache[key]; found {		
		this.change(node)
		return node.val
	} else {
		return -1
	}
}


func (this *LFUCache) Put(key int, value int)  {
	if (this.capacity == 0) {
		return
	}

    if node, found := this.cache[key]; found {
		node.val = value
		this.change(node)
		return
	}

	if this.capacity == len(this.cache) {
		ele := this.freq[this.minCount].Front()
		delete(this.cache, ele.Value.(int))  // 注意点
		this.freq[this.minCount].Remove(ele)		
	}

	this.minCount = 1
	node:= &DataNode{
		key: key,
		val: value,
		count: 1,		
	}
	
	this.addFreq(this.minCount,node)
	this.cache[key] = node
}

