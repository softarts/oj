//
// Created by rui.zhou on 9/30/2019.
//

/*
 * Given a wordlist, we want to implement a spellchecker that converts a query word into a correct word.

For a given query word, the spell checker handles two categories of spelling mistakes:

Capitalization: If the query matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the case in the wordlist.
Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the query word with any vowel individually, it matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the match in the wordlist.
Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)
Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)
In addition, the spell checker operates under the following precedence rules:

When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
When the query matches a word up to capitlization, you should return the first such match in the wordlist.
When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
If the query has no matches in the wordlist, you should return the empty string.
Given some queries, return a list of words answer, where answer[i] is the correct word for query = queries[i].



Example 1:

Input: wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]


Note:

1 <= wordlist.length <= 5000
1 <= queries.length <= 5000
1 <= wordlist[i].length <= 7
1 <= queries[i].length <= 7
All strings in wordlist and queries consist only of english letters.
思路
 很实用的题目,元音拼写检查， 用何种数据来保存?
 这道题涉及比较复杂的逻辑，可能不适合做面试
 有完全匹配的输出
 没有完全匹配的
 可以替换多个元音字母以匹配
 因为大小写不能匹配的，输出第一个不考虑大小写的匹配
 HARE->hare
 */
#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;
namespace {
    class Solution {
    public:
        vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
            unordered_map<string, string> map;
            //unordered_set<char> vowels{'a','e','i','o','u'};
            unordered_set<char> vowels{'A','E','I','O','U'};
            auto str_to_upper = [](string s) {
                std::transform(s.begin(),s.end(),s.begin(),::toupper);
                return s;
            };
            auto str_replace_vowel = [&](string s){
                transform(s.begin(),s.end(),s.begin(),[&](auto ch){
                    if (vowels.count(ch)) {
                        return '*';
                    } else {
                        return ch;
                    }
                });
                return s;
            };

            for (auto s : wordlist) {
                string uppstr = str_to_upper(s);
                if (map.count(uppstr)==0) {
                    map[uppstr] = s;
                }

                string vowelstr = str_replace_vowel(uppstr);
                if (map.count(vowelstr) == 0) {
                    map[vowelstr] = s;
                }

                map[s] = s;
            }

            vector<string> ret;
            for (auto& s : queries) {
                string uppstr = str_to_upper(s);
                string vowelstr = str_replace_vowel(uppstr);
                if (map.count(s)) {
                    ret.emplace_back(map[s]);
                } else if (map.count(uppstr)) {
                    ret.emplace_back(map[uppstr]);
                } else if (map.count(vowelstr)){
                    ret.emplace_back(map[vowelstr]);
                } else {
                    ret.emplace_back("");
                }
            }
            return ret;
        }
    };
}

DEFINE_CODE_TEST(966_vowel_speel_checker) {
    Solution obj;
    {
        vector<string> input{"KiTe","kite","hare","Hare"};
        vector<string> queries{"kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"};
        vector<string> exp{"kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"};
        VERIFY_CASE(VERIFY_VEC(obj.spellchecker(input, queries), move(exp)),true);
    }

}