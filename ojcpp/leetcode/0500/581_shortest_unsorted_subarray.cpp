//
// Created by rui.zhou on 6/18/2019.
//

/*
 *
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
 * Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,0000].
The input array may contain duplicates, so ascending order here means <=.
最小需要调整多少个元素，使整个数组有序
 1。sort之后比较  O(nlogN)
 */
#include <codech/codech_def.h>
using namespace std;

namespace {

    class Solution0 {
    public:
        int findUnsortedSubarray(vector<int> &nums) {
            vector<int> clone = nums;
            sort(clone.begin(),clone.end());
            int start =clone.size(),end=0;
            for (int i=0;i<clone.size();i++) {
                if (clone[i]!=nums[i]) {
                    end = i;
                    start = min(start,i);
                }
            }
            return end>start?(end-start+1):0;
        }
    };

    class Solution {
    public:
        int findUnsortedSubarray(vector<int> &nums) {
            stack<int> st;
            int left = nums.size(),right = 0;
            for (int i=0;i<nums.size();i++) {
                while (!st.empty() && nums[st.top()]> nums[i]) {
                    left = min(left, st.top());
                    st.pop();
                }
                st.push(i);
            }
            stack<int> tmp;
            st.swap(tmp);
            for (int i=nums.size()-1;i>=0;i--) {
                while (!st.empty() && nums[st.top()] < nums[i]) {
                    right = max(right, st.top());
                    st.pop();
                }
                st.push(i);
            }

            return right>left?(right-left+1):0;
        }
    };
}

/*
if (nums.empty()) return 0;
int start = INT_MIN, end = -1;
int maxNum = nums[0];
for (int i=1;i<nums.size();i++) {
if (nums[i]<=maxNum) {
if (start==INT_MIN)
start = i-1;
//start = (start==INT_MIN?i-1:start);
end = i;
} else {
maxNum = nums[i];
}
}
if (start==INT_MIN) return 0;
return end-start+1;
*/

DEFINE_CODE_TEST(581_shortest_unsorted_array)
{
    Solution obj;
    {
        vector<int> nums{2,3,3,2,4};
        VERIFY_CASE(obj.findUnsortedSubarray(nums),3);
    }
    {
        vector<int> nums{1,2,3,3,3};
        VERIFY_CASE(obj.findUnsortedSubarray(nums),0);
    }
    {
        vector<int> nums{9,8,7,6,5,4,3,2,1};
        VERIFY_CASE(obj.findUnsortedSubarray(nums),9);
    }
    {
        vector<int> nums{2,6,4,8,10,9,15};
        VERIFY_CASE(obj.findUnsortedSubarray(nums),5);
    }
    {
        vector<int> nums{2,6,4,8,10,15};
        VERIFY_CASE(obj.findUnsortedSubarray(nums),2);
    }
    {
        vector<int> nums{2,4,6,8,10,15};
        VERIFY_CASE(obj.findUnsortedSubarray(nums),0);
    }
    {
        vector<int> nums{};
        VERIFY_CASE(obj.findUnsortedSubarray(nums),0);
    }

}