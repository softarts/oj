//
// Created by rui zhou on 13/03/19.
//

/*
 * Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2  capacity  );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
 */

#include <codech/codech_def.h>
using namespace std;

namespace lc146 {
    class LRUCache {
    private:
        using data_t = pair<int,int>;
        list<data_t> timeList_;
        int sz_;
        unordered_map<int,int> cache_;
        unordered_map<int,list<data_t>::iterator> keyToList_;
        //头部是最新update的数据
    public:
        LRUCache(int capacity) {
            sz_=capacity;
        }

        int get(int key) {
            auto iter=cache_.find(key);
            if (iter!=cache_.end()) {
                auto &listIter=keyToList_[key];
                timeList_.splice(timeList_.begin(),timeList_,listIter);
                return iter->second;
            } else {
                return -1;
            }
        }

        void put(int key, int value) {
            auto ktl= keyToList_.find(key);
            if (ktl==keyToList_.end()) {
                timeList_.push_front({key,value});
                auto iter=timeList_.begin();
                keyToList_[key]=iter;
            } else {
                auto &iter=keyToList_[key];
                timeList_.splice(timeList_.begin(),timeList_,iter);
            }

            cache_[key]=value;
            if (cache_.size()>sz_) {
                int rmKey;
                std::tie(rmKey,std::ignore) = timeList_.back();
                timeList_.pop_back();
                keyToList_.erase(rmKey);
                cache_.erase(rmKey);
            }
        }
    };

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
}