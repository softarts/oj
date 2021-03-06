package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.LinkedList;

// 特点, 最近访问过的排在前面，容量满的时候先删除未被访问的数据
// get(key) 是O(1)操作
// 缺点 linkedlist 的iterator是否失效，感觉在重新插入元素的时候,iterator会失效
//public class Lc0146_lrucache extends BaseSolution {
//    class LRUCache {
//        class Node {
//            public int value;
//            public Iterator iter;
//        }
//        private HashMap<Integer,Node> cache = new HashMap();
//        private LinkedList<Integer> tsl = new LinkedList<>();
//        private int cs = 0;
//        public LRUCache(int capacity) {
//            cs = capacity;
//        }
//
//        public int get(int key) {
//            var node = cache.get(key);
//            if (node==null) return -1;
//            else {
//                node.iter.next();
//                node.iter.remove();//delete node
//                tsl.addFirst(node.value);
//                node.iter = tsl.listIterator(0);
//                cache.put(key,node);
//                return node.value;
//            }
//        }
//
//        public void put(int key, int value) {
//            var node=cache.get(key);
//            if (node!=null) {
//                node.iter.next();
//                node.iter.remove();//delete node
//                tsl.addFirst(node.value);
//                node.iter = tsl.listIterator(0);
//                cache.put(key,node);
//            } else {
//                if (cache.size()>=cs) {
//                    //remove the last one
//                    var keydel = tsl.getLast();
//                    var nodedel = cache.get(keydel);
//                    nodedel.iter.next();
//                    nodedel.iter.remove();//delete node
//                    tsl.removeLast();
//                }
//                var newnode = new Node();
//                newnode.value = value;
//                tsl.addFirst(newnode.value);
//                newnode.iter = tsl.listIterator();
////                if (newnode.iter.hasNext()) {
////                    System.out.println(newnode.iter.next());
////                }
//                cache.put(key,newnode);
//            }
//        }
//    }
//
//    @Override
//    public boolean test() {
//        var lru = new LRUCache(2);
//        lru.put(1,1);
//        System.out.println(lru.get(1));
//        return true;
//    }
//}

// lany modification  of list after listiterator create will fail the operation
// because listiterarot use internal lastreturn to remember the order

class Lc0146_lrucache0 extends BaseSolution {
    class LRUCache {
        class Node {
            public int value,key;
            public Node prev=null,next=null;
        }
        private int cap = 0;
        private HashMap<Integer, Node> cache = new HashMap();
        Node head=null,tail=null;

        public LRUCache(int capacity) {
            cap = capacity;
        }
        private void addNode(Node node) {
            if (head==null) {
                head = node;
                tail = node;
            } else {
                tail.next = node;
                node.prev = tail;
                tail = node;
            }
        }

        private void removeNode(Node node) {
            Node prev = node.prev;
            if (prev!=null) {//not head
                prev.next = node.next;
            } else {
                head = node.next;
            }

            Node next = node.next;
            if (next!=null) {// not tail
                next.prev = prev;
            } else {
                tail = prev;
            }

            node.prev = null;
            node.next = null;
        }



        public int get(int key) {
            if (cache.containsKey(key)) {
                Node node = cache.get(key);
                removeNode(node);
                addNode(node);
                return node.value;
            } else {
                return -1;
            }
        }

        public void put(int key, int value) {
            if (cache.containsKey(key)) {
                Node node = cache.get(key);
                removeNode(node);
                addNode(node);
                node.value = value;
            } else {
                if (cache.size()==cap) {
                    if (head != null) {
                        int hk = head.key;
                        removeNode(head);
                        cache.remove(hk);
                    }
                }
                Node newNode = new Node();
                newNode.value = value;
                newNode.key = key;
                addNode(newNode);
                cache.put(key,newNode);
            }
        }

    }

}
// 使用linkedHashmap是很好的办法，因为它带有顺序
public class Lc0146_lrucache extends BaseSolution {
    class LRUCache {
        private LinkedHashMap<Integer,Integer> cache=new LinkedHashMap<>();
        private int cs = 0;
        public LRUCache(int capacity) {
            cs = capacity;
        }

        public int get(int key) {
            var v = cache.get(key);
            if (v!=null) {
                cache.remove(key);
                cache.put(key,v);
                return v;
            } else {
                return -1;
            }
        }

        public void put(int key, int value) {
            var v=cache.get(key);
            if (v==null) {
                if (cache.size()>=cs) {
                    var oldest = cache.keySet().iterator().next();
                    cache.remove(oldest);
                }
                cache.put(key,value);
            } else {
                cache.remove(key);
                cache.put(key,value);
            }
        }
    }
}
