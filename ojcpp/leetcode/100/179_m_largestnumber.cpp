//
// Created by zhou rui on 7/4/18.
//

/*
 * https://leetcode.com/problems/largest-number/description/
 *
 * Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

9:01 pm
 3, 30
 */

#include <codech/codech_def.h>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for (auto &p:nums) {
            arr.emplace_back(to_string(p));
        }
        sort(arr.begin(), arr.end(),[](const string &s1, string &s2){ return s1+s2 > s2+s1;});
        string ret;
        for (auto &r:arr) {
            ret+=r;
        }
        if (ret.length()>1) {
            if (ret[0]=='0')
                return "0";
        }
        return ret;
    }
};

DEFINE_CODE_TEST(179_largest_number)
{
    Solution obj;
    {
        vector<int> nums{3,30,34,5,9};
        VERIFY_CASE(obj.largestNumber(nums),"9534330");
    }
    {
        vector<int> nums{0,0,0,0,0,0,0,0};
        VERIFY_CASE(obj.largestNumber(nums),"0");
    }
}