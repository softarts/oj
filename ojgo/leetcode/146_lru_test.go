package leetcode

import (
	"container/list"
	"reflect"
	"testing"
)

type LRUCache0 struct {
	cache    map[int]*Data
	ll       *list.List
	capacity int
}

type Data struct {
	value  int
	llNode *list.Element
}

func Constructor0(capacity int) LRUCache0 {
	return LRUCache0{
		cache:    make(map[int]*Data),
		ll:       list.New(),
		capacity: capacity,
	}
}

func (this *LRUCache0) Get(key int) int {
	if data, found := this.cache[key]; found {
		this.ll.MoveToBack(data.llNode)
		return data.value
	} else {
		return -1
	}
}

func (this *LRUCache0) Put(key int, value int) {
	if data, found := this.cache[key]; found {
		data.value = value
		this.ll.MoveToBack(data.llNode)
		return
	}

	if len(this.cache) == this.capacity {
		todel := this.ll.Front()
		delete(this.cache, todel.Value.(int))
		this.ll.Remove(todel)
	}

	newElement := this.ll.PushBack(key)
	this.cache[key] = &Data{
		value:  value,
		llNode: newElement,
	}
}

func Test146(t *testing.T) {
	obj := Constructor0(2)
	obj.Put(2, 1)
	obj.Put(2, 2)
	ret := obj.Get(2)
	exp := 2
	if !reflect.DeepEqual(ret, exp) {
		t.Errorf("Not Passed, got %v", ret)
	}

}
