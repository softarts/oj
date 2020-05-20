//
// Created by rui.zhou on 5/20/2020.
//

// 删除上升序列，保证剩下的元素都是唯一元素
// 2,1,3,1,4,1,3, 删掉 1,1,3,剩下2,3,4,1都是唯一元素
//返回被删除的序列
//思路 就是找出那些数量多于1的序列，然后排序，逐个和原有序列进行对比
#include <codech/codech_def.h>

using namespace std;

namespace {
    vector<int> findSubsequence(vector<int> arr) {
        unordered_map<int,int> m;
        vector<int> ans;
        for (auto &iter:arr) {
            m[iter]+=1;
        }

        // min heap
        priority_queue<int,vector<int>, greater<int>> pq;
        for (auto &&iter:m){
            if (iter.second>1) {
                pq.push(iter.first);
            }
        }

        for (auto &iter:arr) {
            if (pq.empty())
                return ans;
            if (pq.top() == iter) {
                m[iter] -=1;
                ans.emplace_back(iter);
                if (m[iter] == 1) pq.pop();
            }
        }

        return pq.empty()?ans:vector<int>{-1};

    }

}