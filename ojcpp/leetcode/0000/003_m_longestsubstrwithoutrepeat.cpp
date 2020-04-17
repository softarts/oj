//
// Created by rui.zhou on 2/13/2019.
//

/*
 *Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

找出最长不含重复字符的字串
 用hashmap记录每一个字符的所在位置，如果碰到一个字符在map中已存在，那么以前一个字符作为终点更新长度，
新的起点移到重复字符之后的下一个字符。当更新起点后，在起点之前的map中的字符在比较长度时可以忽略掉


 陷阱，当遇到重复字符后，有几种情况
 要从上一次重复字符所在的位置开始计算，而不是当前位置

 */

#include <codech/codech_def.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxl = 0;
        unordered_map<char, int> map;//not existing key will have default value initial to 0
        int start = 0;
        for (int i=0;i<s.length();i++) {
            if (map.find(s[i])==map.end()) {
                maxl=max(i-start+1, maxl);
                map.insert(make_pair(s[i],i));
            } else {
                if (map[s[i]] < start)
                    maxl = max(i-start+1, maxl);
                else
                    maxl = max(i-start, maxl);
                    start = map[s[i]]+1;
                //map = {{s[i],i}};//[s[i]] = i;
                map[s[i]] = i;
            }
        }
        return maxl;

    }
};



DEFINE_CODE_TEST(003_longestsubstrworepeat) {
    Solution obj;
    {
        string s="tmmzuxt";
        VERIFY_CASE(obj.lengthOfLongestSubstring(s),5);
    }
    {
        string s="abcabcbb";
        VERIFY_CASE(obj.lengthOfLongestSubstring(s),3);
    }
    {
        string s="bbbbb";
        VERIFY_CASE(obj.lengthOfLongestSubstring(s),1);
    }
    {
        string s="pwwkew";
        VERIFY_CASE(obj.lengthOfLongestSubstring(s),3);
    }
    {
        string s="";
        VERIFY_CASE(obj.lengthOfLongestSubstring(s),0);
    }
    {
        string s="abcdbef";
        VERIFY_CASE(obj.lengthOfLongestSubstring(s),5);
    }


}
