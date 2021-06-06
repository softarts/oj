//
// Created by rui zhou on 2019-09-18.
//

/*
 * Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks. Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.



Example:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.


Note:

The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].

// 数学解法
(最多的task的个数-1)*(n+1)+ (有多少个task的计数都为最多)


比如对于测试用例["A","A","A","B","B","B"]，0，公式求得是(3-1)*(0+1)+2=4，而事实上，任务最少都要被调度一遍的，所以必须对任务个数求个最大值。
为什么会出现这种情况呢？很简单的解释就是当n很小（0）的时候，这个时候n要求两个相同任务调度之间的间隔可以很小，但是事实上，相同任务间隔不可能完全按照n来确定，因为其他的任务也要插在中间。综上，必须要对任务总个数求个最大值。

 */

#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {
            int counter[26]={0};
            int maxCount = INT_MIN;
            for (auto ch:tasks) {
                counter[ch-'A'] += 1;
                maxCount = max(counter[ch-'A'], maxCount);
            }

            int count2 = 0;
            for (auto c:counter) {
                if (c==maxCount) count2++;
            }

            return max(int(tasks.size()),(maxCount-1)*(n+1) + count2);

        }
    };
}