//
// Created by rui zhou on 2020-06-18.
//

#include <codech/codech_def.h>
//#include <format>
using namespace CODECH;
using namespace std;

// 这题没啥特别的，就是数组处理
// 跟上一个比较，如果连续，就递增end
// 否则输出
namespace {
    class Solution {
    public:
        vector<string> summaryRanges(vector<int>& nums) {
            vector<string> ret;
            if (nums.empty()) return ret;
            int start=nums[0],end=nums[0];
            auto addFunc = [&]() {
                if (start==end) {
                    ret.emplace_back(to_string(start));
                } else {
                    //ret.emplace_back(std::format("{}->{}", start,end));
                    ret.emplace_back(to_string(start)+"->"+to_string(end));
                }
            };

            for (int i=1;i<nums.size();i++) {
                if (nums[i]==nums[i-1]+1) {
                    end = nums[i];
                } else {
                    addFunc();
                    start = nums[i];
                    end = start;
                }
            }
            addFunc();
            return ret;
        }
    };
}

DEFINE_CODE_TEST(228_summaryrange)
{
    Solution obj;
    {
        vector<int> arr = {0,1,2,4,5,7};
        VERIFY_CASE(PRINT_STRVEC(obj.summaryRanges(arr)),"0->2 4->5 7 ");
    }
    {
        vector<int> arr = {0};
        VERIFY_CASE(PRINT_STRVEC(obj.summaryRanges(arr)),"0 ");
    }

    {
        vector<int> arr = {};
        VERIFY_CASE(PRINT_STRVEC(obj.summaryRanges(arr)),"");
    }



}

