//
// Created by rui.zhou on 5/20/2020.
//

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'segment' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER x
 *  2. INTEGER_ARRAY space
 */

// segments size = 3
// space size = 5
//array [2,5,4,6,8]
// 意思是每3个元素找出最小值，然后再把这些最小值合并找出最大值
//答案是2,4,4->4
// x = segments size
//lc 239 hard
//使用一个deque，作为slide windows,保证deque里2个元素，头部是最小元素（目的元素），尾部是第二小的元素
// 每当deq满了，而且头部的元素正好是窗口之外的数字，pop出
#include <codech/codech_def.h>

namespace {
    int segment(int x, vector<int> space) {
        std::deque<int> deq;
        int ans = INT_MIN;
        for (int i=0;i<space.size();i++) {
            while (!deq.empty() && space[i]<deq.back()) {
                deq.pop_back();
            }
            deq.emplace_back(space[i]);

            if (i>=x && deq.front() == space[i-x]) {
                deq.pop_front();
            }

            if (i>=x-1) {
                ans = max(ans,deq.front());
            }
        }
        return ans;
    }
}

DEFINE_CODE_TEST(blockone_diskspace) {
    VERIFY_CASE(segment(3,{2,5,4,6,8}),4);
}