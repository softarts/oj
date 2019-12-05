//
// Created by rui.zhou on 5/6/2019.
//

//LC169

//O(N)算法得到任意第K大的数字

#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int count = 0;
            int prev = nums[0];
            for (int i=1;i<nums.size();i++) {
                if (nums[i]==prev) {
                    count++;
                } else {
                    if (--count == 0) {
                        prev = nums[i];
                        count=1;
                    }
                }
            }
            return prev;
        }
    };
}



DEFINE_CODE_TEST(hht_029_majority_element)
{
    Solution obj;
    {
        vector<int> nums{3,3,2,3,1,3,2,3};
        VERIFY_CASE(obj.majorityElement(nums),3);
    }

    {
        vector<int> nums{3,2,3};
        VERIFY_CASE(obj.majorityElement(nums),3);
    }
}