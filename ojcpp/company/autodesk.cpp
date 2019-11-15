//
// Created by rui zhou on 2019-11-06.
//

// 打印最大值
#include <codech/codech_def.h>

using namespace std;
using namespace CODECH;


// 找出最大值的连续子序列,累加元素，当小于0的时候重新开始
// 变种，找出子序列

namespace {
    // 打印连续子array
    class Solution {
    public:
        int findMaxSum(vector<int>&arr) {
            int cursum = arr[0];
            int maxsum = cursum;

            for (int i=1;i<arr.size();i++) {
                cursum = max(cursum+arr[i],arr[i]);
                maxsum = max(maxsum, cursum);
            }
            return maxsum;

        }
    };


    class Solution1 {
    public:
        vector<int> findMaxSumSubarr(vector<int>&arr) {
            vector<int> ans;
            int begin=0,end=0,curpos=0;

            int cursum = arr[0];
            int maxsum = cursum;

            for (int i=1;i<arr.size();i++) {
                if (arr[i] > (cursum+arr[i])) {
                    curpos = i;
                }

                cursum = max(cursum+arr[i],arr[i]);

                if (cursum > maxsum) {
                    begin = curpos;
                    end = i;

                }
                maxsum = max(maxsum, cursum);
            }
            copy(arr.begin()+begin,arr.begin()+end+1,back_inserter(ans));


            return ans;
        }
    };

//[7, 9, 5, 6, 3, 2]
//7, 9 -> 2

//[2, 3, 10, 6, 4, 8, 1]
//10, 2 -> 8
//
//[22, 3, 10, 16, 4, 8, 1]
//->16 , 3

    class Solution2 {
    public:
        int findpeak(vector<int>&arr) {
            int mx = INT_MIN;
            int mi = arr[0];
            for (int i=1;i<arr.size();i++) {
                mx = max(arr[i]-mi,mx);
                mi = min(mi,arr[i]);
            }
            return mx;
        }
    };
}




//
//
// https://www.geeksforgeeks.org/maximum-difference-between-two-elements/
//int diff(vector<int> &arr) {
//    int mi = INT_MAX;
//    int mm = INT_MAX;
//    int maxdiff = INT_MIN;
//
//    for (int i=0;i<arr.size();i++) {
////       mi = min(mi,arr[i]);
//
//        if (arr[i] > mi) {
//            mm = min(arr[i],mi);
//        }
//    }
//}

DEFINE_CODE_TEST(autodesk_maxsumarr)
{
//    {
//        vector<int> ans = findMaxsumArr({0,-1,6,7,8,-3,7,9});
//        cout << PRINT_VEC(move(ans));
//    }
    Solution1 obj;
    {
        vector<int> arr = {0,-1,6,7,8,-3,7,9};
        VERIFY_CASE(VERIFY_VEC(obj.findMaxSumSubarr(arr),{6,7,8,-3,7,9}),true);
        //cout << PRINT_VEC(obj.findMaxSumSubarr(arr)) << endl;
    }
    {
        vector<int> arr = {-2,-3,-4,0,-1,-6,-7,-8,-3,-7,-9};
        cout << PRINT_VEC(obj.findMaxSumSubarr(arr)) << endl;
    }
}