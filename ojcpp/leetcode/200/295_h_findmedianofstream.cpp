//
// Created by rui.zhou on 2019/12/18.
//
#include <codech/codech_def.h>
using namespace std;

namespace {
    class MedianFinder0 {
    public:
        vector<int> arr;
        priority_queue<int> pq0,pq1;
        int pqId = 0;
        /** initialize your data structure here. */
        MedianFinder() {

        }

        void addNum(int num) {
            if (pqId==0) {
                pq0.push(num);
            } else {
                pq1.push(num);
            }
        }

        double findMedian() {
            auto find = [](auto &src,auto &dest) {
                double ans =0.0;
                size_t sz = src.size();
                int idx = 0;
                while (!src.empty()) {
                    auto elem = src.top();
                    if (sz%2==1) {
                        if (idx==sz/2) {
                            ans = elem;
                        }
                    } else {
                        if (idx==sz/2) {
                            ans += elem;
                            ans /=2;
                        }
                        if (idx==sz/2-1) {
                            ans += elem;
                        }
                    }
                    src.pop();
                    dest.push(elem);
                    idx++;
                }
                return ans;
            };

            if (pqId==0) {
                pqId = 1;
                return find(pq0,pq1);
            } else {
                pqId=0;
                return find(pq1,pq0);
            }
        }
    };

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

    class MedianFinder {
    public:
        vector<int> arr;
        priority_queue<int> pq0,pq1;
        int pqId = 0;
        /** initialize your data structure here. */
        MedianFinder() {

        }

        void addNum(int num) {
            if (pqId==0) {
                pq0.push(num);
            } else {
                pq1.push(num);
            }
        }

        double findMedian() {

        }
    };
}