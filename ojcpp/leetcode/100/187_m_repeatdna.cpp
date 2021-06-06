//
// Created by rui.zhou on 3/14/2019.
//

/*
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

Example:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

Output: ["AAAAACCCCC", "CCCCCAAAAA"]

 //TODO 其它实现
 */

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace lc187 {
    // straightforward
    class Solution {
    public:
        vector<string> findRepeatedDnaSequences(string s) {
            unordered_set<string> set;
            unordered_set<string> ret;
            int sz=s.length();
            for (int i=0;i<=sz-10;i++) { //s.length()是size_t
                string tmp=s.substr(i,10);
                if (set.count(tmp)) {
                    ret.emplace(tmp);
                } else {
                    set.emplace(tmp);
                }
            }
            return vector<string>(ret.begin(),ret.end());
        }
    };
}

DEFINE_CODE_TEST(187_findrepeatdna)
{
    lc187::Solution obj;
    {
        //vector<string> exp0{};
        VERIFY_CASE(VERIFY_VEC(obj.findRepeatedDnaSequences(""),{}),true);

        VERIFY_CASE(trim(PRINT_STRVEC(obj.findRepeatedDnaSequences("AAAAAAAAAAAA"))),
                    "AAAAAAAAAA");
        //vector<string> exp{"AAAAACCCCC","CCCCCAAAAA"};
        VERIFY_CASE(VERIFY_VEC(obj.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"),
                               {"AAAAACCCCC","CCCCCAAAAA"}),true);
    }
}