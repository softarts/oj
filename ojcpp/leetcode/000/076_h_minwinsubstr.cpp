//
// Created by rui.zhou on 2/13/2019.
//

/*
 * Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
 假设T中允许重复字符串

 1.使用移动窗口方法，先找到窗口的右侧，即index=5处， "ADOBEC"，然后缩减窗口的左侧，得到此时的substr len
 2.接着继续往右查找下一个窗口，index=10位置，"ADOBECODEBA"，从上一次的窗口左侧开始缩减
 技巧在于1,2步之间的状态转换，

窗口滑动
 http://www.cnblogs.com/grandyang/p/4340948.html
1.使用t.length()来表示找到了t中的所有字符，每找到一个字符就把对应的hashmap value-1,当到达窗口右侧的时候，
所有的value都应该是0
2.此时开始查找窗口左侧，窗口应在到达t中的任一个字符时停止移动.记下此时的start,计算出len


1.使用hash, key=t中每个char的个数，value=该字符在t中的个数, t的长度为n，用value来表示当前的搜索substr中还差几个该字符
2.然后从头开始遍历，每看到一个T中的字符，hashmap中value如果大于0，n--， 然后value-1, (把value--,n--，注意不能减过头:value<=0)
3,当所有的T中字符都找到，n=0，此时指向为窗口的右侧，
4.
  unordered_map<char, int> hash;
        int num = t.size(), len=INT_MAX, start =0, left = 0;
        for(auto val: t) hash[val]++;
        for(int i =0; i < s.size(); i++)
        {
            if(hash[s[i]]-- >0) num--;
            while(num ==0)
            {
                len = (i-left+1)<len?(i-(start=left)+1):len;
                if(hash[s[left++]]++ ==0) num++;
            }
        }
        return len==INT_MAX?"":s.substr(start, len);
 */
#include <codech/codech_def.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> hm;
        for (auto c : t) {
           hm[c]++;
        }
        int num = t.length();
        int left = 0;
        int minlen = INT_MAX;
        int start = 0;

        for (int i=0;i<s.length();i++) {
            auto iter = hm.find(s[i]);
            if (iter!=hm.end() && iter->second-- >0) {
                num--;
            }
            //move left window
            while (num==0) {
                minlen = (i-left+1)<minlen?(i-(start=left)+1):minlen;
                auto iter = hm.find(s[left++]);
                if (iter!=hm.end() && iter->second++ ==0) {
                    num++;
                }


            }
        }
        return minlen==INT_MAX?"":s.substr(start, minlen);

    }
};


DEFINE_CODE_TEST(076_minwindowsubstr)
{
    Solution obj;
    {
        VERIFY_CASE(obj.minWindow("ADOBECODEBANC","ABC"),"BANC");
    }
    {
        VERIFY_CASE(obj.minWindow("AABCDOBECODEBANC","ABC"),"ABC");
    }
    {
        VERIFY_CASE(obj.minWindow("ABC","B"),"B");
    }

}