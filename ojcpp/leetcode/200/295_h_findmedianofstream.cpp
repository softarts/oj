//
// Created by rui.zhou on 2019/12/18.
//

// goldman sachs 2019
#include <codech/codech_def.h>
using namespace std;

namespace {
    class MedianFinder0 {
    public:
        vector<int> arr;
        priority_queue<int> pq0,pq1;
        int pqId = 0;
        /** initialize your data structure here. */
        MedianFinder0() {

        }

        void addNum(int num) {
            if (pqId==0) {
                pq0.push(num);
            } else {
                pq1.push(num);
            }
        }

        // COMPLEXITY: pop = log(N), iterate = N
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

        priority_queue<int, vector<int>, greater<int>> mn;
        priority_queue<int, vector<int>, less<int>> mx;  //max heap
        int median;

        /** initialize your data structure here. */
        MedianFinder() {
            mx.emplace(INT_MIN);
            mn.emplace(INT_MAX);
        }

        void addNum(int num) {
            int smx = mx.size();
            int smn = mn.size();

            int p0 = mx.top();
            int p1 = mn.top();

            if (smx > smn) {
                if (num>p0) {
                    mn.emplace(num);
                } else {
                    mn.emplace(mx.top());
                    mx.pop();
                    mx.emplace(num);
                }
            } else if (smx < smn) {
                if (num>p1) {
                    mn.emplace(num);
                    mx.emplace(mn.top());
                    mn.pop();
                } else {
                    mx.emplace(num);
                }
            } else {  //equal
                if (num <p1) {
                    mx.emplace(num);
                } else {
                    mn.emplace(num);
                }
            }
        }

        double findMedian() {
            int smx = mx.size();
            int smn = mn.size();

            if (smx ==smn) {
                int p0=mx.top();
                int p1=mn.top();
                if (p0!=INT_MIN && p1!=INT_MAX) {
                    return ((p0+p1))/2.0;
                } else {
                    return 0.0F;
                }
            } else if (smx < smn){
                return mn.top();
            } else {
                return mx.top();
            }
        }
    };
}

DEFINE_CODE_TEST(295_findmediannumber)
{
    {
        MedianFinder obj;
        obj.addNum(1);
        obj.addNum(2);
        VERIFY_CASE(obj.findMedian(),1.5);
    }


}