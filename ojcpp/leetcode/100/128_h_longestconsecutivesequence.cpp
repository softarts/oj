//
// Created by Rui Zhou on 15/3/18.
//

/*
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

hard->
 I only know O(N*LogN)
-> use ordered_map to remember each num's consecutive length
 5:32
 思路：使用hash表来保存数组中的每一个数，每次遍历到一个数的时候看往上找到所有连续的数最多有几个，往下找比他小的数最多有几个．
 为了避免连续的序列中的数重复查找，在找到一个相邻的数之后就把他从hash表中删除，也就是一个连续的序列只会被查找一次．
 因此时间复杂度为O(n)．

 一个无序数组，找出最大的连续长度
 [100, 4, 200, 1, 3, 2]-> 1,2,3,4 长度为4
 */

#include <codech/codech_def.h>
#include <unordered_set>

using namespace std;

namespace {
    class Solution1 {
    public:
        int longestConsecutive(vector<int>& nums) {
            unordered_map<int, int> map;
            int maxLength = 0;
            for (auto &n : nums) {
                if (map.find(n)!=map.end())
                    continue;
                // 一个不存在的数,例如 3->map[3]=1
                // 接下来看到1 ->map[1]=1
                //然后看到2 ->上下都存在 map[2]=3,map[1]=3,map[3]=3
                //总的来说代码没有下面漂亮
                int left = 0, right = 0;
                auto ir = map.find(n+1);
                if (ir!=map.end()) {
                    right = ir->second;
                }

                auto il = map.find(n-1);
                if (il!=map.end()) {
                    left = il->second;
                }
                int sum = left + right + 1; //将左右的sum传递到自身
                map[n] = sum;
                map[n+right] = sum;  // 扩张, important to spread the result to the rightest item
                map[n-left] = sum;
                maxLength = max(maxLength, sum);
            }
            return maxLength;
        }
    };

    //其实道理很简单,先把所有的数导入set
    // 然后在second pass中，找到了某个数，就把他从map中删除，然后上下寻找扩大范围
    class Solution {
    public:
        int longestConsecutive(vector<int> &nums) {
            unordered_set<int> record(nums.begin(),nums.end());
            int res = 0;
            for(int n : nums){
                if(record.find(n)==record.end()) continue;
                record.erase(n);  //erase the item to avoid visit again.
                int prev = n-1,next = n+1;
                while(record.find(prev)!=record.end()) record.erase(prev--);
                while(record.find(next)!=record.end()) record.erase(next++);
                res = max(res,next-prev-1);
            }
            return res;
        }
    };
}


DEFINE_CODE_TEST(128_longest_consecutive_sequence)
{

    Solution obj;
    {
        vector<int> nums {};
        VERIFY_CASE(obj.longestConsecutive(nums),0);
    }
    {
        vector<int> nums {100,4,200,1,3,2};
        VERIFY_CASE(obj.longestConsecutive(nums),4);
    }
    {
        vector<int> nums {100,4,200,1,3,2,5};
        VERIFY_CASE(obj.longestConsecutive(nums),5);
    }
    {
        vector<int> nums {100,4,200,1,3,2,101,102,102,103,104};
        VERIFY_CASE(obj.longestConsecutive(nums),5);
    }
    {
        vector<int> nums {1,2,0,1};
        VERIFY_CASE(obj.longestConsecutive(nums),3);
    }

}


