//
// Created by zhou rui on 19/6/20.
//

#include <codech/codech_def.h>
using namespace CODECH;
using namespace std;

// O(n) 时间 O(1) 空间找出所有的重复元素
// 条件是 范围在1..n之间，
// [4,3,2,7,8,2,3,1]
// 思路  在循环中检查每个元素，将其放置到正确位置，注意，加入ans后，需要将该位置置0，避免后面交换时污染
namespace {
    class Solution {
    public:
        vector<int> findDuplicates(vector<int>& nums) {
            vector<int> ans;
            for (int i=0;i<nums.size();i++) {
                // find right place
                while (true) {
                    if (nums[i] == i+1 || nums[i]==0) {
                        break;
                    }
                    int pos = nums[i] - 1;

                    // duplicated?
                    if (nums[pos] == nums[i]) {
                        ans.emplace_back(nums[i]);
                        nums[i]=0;
                        //nums[pos] = 0;
                        break;
                    } else { // not in right place
                        swap(nums[i],nums[pos]);
                    }
                }

            }
            return ans;
        }
    };
}

DEFINE_CODE_TEST(0442_findduplicatearr)
{
    Solution obj;
    {
        vector<int> nums{4,3,2,7,8,2,3,1};
        VERIFY_CASE(PRINT_VEC(obj.findDuplicates(nums)),"3 2");
    }

}