//
// Created by rui.zhou on 3/2/2019.
//

/*
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/
 * You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

Example 1:

Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.
Example 2:

Input:
  s = "wordgoodgoodgoodbestword",
  words = ["word","good","best","word"]
Output: []
 由于允许本字符串的一部分作为另一个字符串的开始，所以每次判断完的暴力方法是字符串向前移动一位，
 理想的情况是找出本字符串是否有一部分作为另一个字符串的开始.
 这个还是很老的思路，即

 2:30PM
 */

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace lc030 {
    // 其他人的代码，仍然是递增一位，但是在连续寻找上有些优化，比如找到下一个字串，会把
    class Solution {
    public:
        vector<int> findSubstring(string s, vector<string> &words) {
            vector<int> res;
            if (words.empty() || s.empty()) {
                return {};
            }
            int word_length = (int) words[0].size();
            if (s.size()<word_length)
                return {};
            int words_size = (int) words.size();

            unordered_map<string, int> word_list;
            for (string temp : words) {
                word_list[temp]++;
            }

            for (int bias = 0; bias < word_length; bias++) {
                unordered_map<string, int> check_list;
                int left = bias, count = 0;
                for (int j = bias; j < s.size(); ){
                    string word = s.substr(j, word_length);
                    if (word_list.find(word) != word_list.end()) {
                        check_list[word]++;
                        count++;
                        //cout << word << endl;
                        while(check_list[word] > word_list[word]){
                            check_list[s.substr(left, word_length)]--;
                            //相当于把相同字串左侧的全部作废
                            count--;
                            left += word_length;
                        }

                        if(count == words.size())
                            res.push_back(left);
                        j += word_length;

                    } else {
                        check_list.clear();
                        count = 0;
                        left = j + ((j - left) > word_length ? (j - left - word_length) : word_length);
                        j += ((j - left) > word_length ? (j - left) : word_length);
                    }

                }
            }
            return res;
        }
    };

    class Solution0 {
    public:

        vector<int> findSubstring(string s, vector<string> &words) {
            if (words.empty() || s.empty()) {
                return vector<int>();
            }

            unordered_map<string, int> map;
            for (auto &w:words) {
                if (w.empty())
                    return vector<int>();
                map[w] += 1;
            }

            int len = words[0].length();
            int totalLen = len * words.size();
            vector<int> ret;
            int start = 0;

            auto verify = [&](string &piece) {
                auto table = map;
                int p1 = 0;
                int p2 = piece.length();
                if (p2 < totalLen)
                    return make_pair(false, p2);
                while (p1 < p2) {
                    string w = piece.substr(p1, len);
                    if (table[w] - 1 < 0) {
                        return make_pair(false, 1);
                    } else {
                        table[w] -= 1;
                    }
                    p1 += len;
                }
                return make_pair(true, p2);
            };

            while (start < s.length()) {
                string s0 = s.substr(start, totalLen);
                bool r0;
                int newpos;
                std::tie(r0, newpos) = verify(s0);
                if (r0) {
                    ret.emplace_back(start);
                }
                start++;
            }
            return ret;
        }
    };
}

DEFINE_CODE_TEST(030_substrconcaten)
{
    lc030::Solution obj;
    {
        vector<string> words{"aa","bb"};
        VERIFY_CASE(PRINT_VEC(obj.findSubstring("aabbbbcc",words)),"0 1 2");
    }
    {// 这个如何优化？公共子串？
        vector<string> words{"aa","aa","aa"};
        VERIFY_CASE(PRINT_VEC(obj.findSubstring("aaaaaaaa",words)),"0 1 2");
    }
    {
        vector<string> words{"foo","bar"};
        VERIFY_CASE(PRINT_VEC(obj.findSubstring("barfoothefoobarman",words)),"0 9");
    }
    {
        vector<string> words{"word","good","best","word"};
        VERIFY_CASE(PRINT_VEC(obj.findSubstring("wordgoodgoodgoodbestword",words)),"");
    }
    {
        vector<string> words{};
        VERIFY_CASE(PRINT_VEC(obj.findSubstring("wordgoodgoodgoodbestword",words)),"");
    }
    {
        vector<string> words{};
        VERIFY_CASE(PRINT_VEC(obj.findSubstring("",words)),"");
    }
    {
        vector<string> words{"","",""};
        VERIFY_CASE(PRINT_VEC(obj.findSubstring("",words)),"");
    }
    {
        vector<string> words{"bar","foo","the"};
        VERIFY_CASE(PRINT_VEC(obj.findSubstring("barfoofoobarthefoobarman",words)),"6 9 12");
    }

}