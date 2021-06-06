//
// Created by rui zhou on 29/05/19.
//

/*
 * https://leetcode.com/problems/verifying-an-alien-dictionary/
 * In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.



Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).


Note:

1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
All characters in words[i] and order are english lowercase letters.

 facebook interview
 给出一个words列表，判断是不是所有的词都按顺序排列
 */

#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        bool isAlienSorted(vector<string>& words, string &order) {
            string prev = words[0];
            unordered_map<char,int> m;
            int idx = 0;
            for (auto&ch:order) {
                m[ch] = idx++;
            }
            auto comp = [&](string &a, string &b){
                int len = min(a.length(),b.length());
                for (int i=0;i<len;i++) {
                    if (m[a[i]]<m[b[i]]) {
                        return true;
                    } else if (m[a[i]]>m[b[i]]) {
                        return false;
                    }
                }
                if (a.length()<=b.length())
                    return true;
                else if (a.length()>b.length())
                    return false;
            };

            for (int i=1;i<words.size();i++) {
                if (!comp(prev, words[i]))
                    return false;
                prev = words[i];
            }
            return true;
        }
    };
}

DEFINE_CODE_TEST(953_alien_dict)
{
    Solution obj;
    {
        vector<string> words = {"hello","leetcode"};
        string order = "hlabcdefgijkmnopqrstuvwxyz";
        VERIFY_CASE(obj.isAlienSorted(words, order),true);
    }

}

