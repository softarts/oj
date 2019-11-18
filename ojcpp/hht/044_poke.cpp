//
// Created by rui zhou on 2019-11-15.
//

#include <codech/codech_def.h>

using namespace std;


// 扑克牌抽5张，看看是不是顺子
//J-K = 11-13
// joke - any (0)
// A,2,3...10 ->10

namespace {
    class Solution {
    public:
        bool isContinuous(vector<int> &arr) {
            int zero = 0;
            for (auto &it:arr) {
                if (it == 0)
                    zero++;
            }
            sort(arr.begin(),arr.end());

            for (int i=1;i<arr.size();i++) {
                if (arr[i]==0) continue;
                if (arr[i]==arr[i-1]) return false;
                zero -= arr[i]-arr[i-1]-1;
                if (zero<0) return false;
            }
            return true;
        }
    };
}

DEFINE_CODE_TEST(hht_044_poke_shunzi) {
    Solution obj;
    {
        vector<int> nums{0,1,3,4,5};
        VERIFY_CASE(obj.isContinuous(nums),true);
    }
    {
        vector<int> nums{0,0,3,4,5};
        VERIFY_CASE(obj.isContinuous(nums),true);
    }
    {
        vector<int> nums{0,0,13,4,5};
        VERIFY_CASE(obj.isContinuous(nums),false);
    }
    {
        //vector<int> nums{6,7,0,4,5};
        //VERIFY_CASE(obj.isContinuous({6,7,0,4,5}),true);
    }
}

