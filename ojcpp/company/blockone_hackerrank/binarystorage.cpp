//
// Created by rui.zhou on 5/20/2020.
//

//input {{0,2},{2,3},{2,1}}
//表示哪一位是1，所以上面的数组是 5,12,6
//排序后返回12,6,5  ->对应的数组序号是1,2,0
//思路，先对每个内部vec排序，最后在外层在进行一次排序，参考lc953
#include <codech/codech_def.h>

using namespace std;

namespace {
    vector<int> sortBinaryNumbers(vector<vector<int>> bitArrays) {
        for (size_t i=0;i < bitArrays.size();i++) {
            auto &vec = bitArrays[i];
            sort(vec.begin(),vec.end(),greater<int>());
            vec.emplace_back(i);  // last element as the origin index
        }
        auto comp = [](const vector<int>&a, const vector<int>&b) ->bool{
            int mlen = min(a.size(),b.size()) - 1;
            for (int i=0;i<mlen;i++) {
                if (a[i]>b[i]) return true;
                else if (a[i]<b[i]) return false;
            }
            if (a.size() >=b.size()) return true;
            else return false;
        };

        sort(bitArrays.begin(),bitArrays.end(),comp);
        vector<int> ans;
        for (auto &vec:bitArrays) {
            ans.emplace_back(*vec.rbegin());
        }
        return ans;
    }
};