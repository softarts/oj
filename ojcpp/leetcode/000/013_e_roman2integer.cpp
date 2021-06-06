//
// Created by rui.zhou on 2/17/2019.
//

/*
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: "III"
Output: 3
Example 2:

Input: "IV"
Output: 4
Example 3:

Input: "IX"
Output: 9
Example 4:

Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 5:

Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 */

#include <codech/codech_def.h>
using namespace std;

class Solution {
public:
    unordered_map<char, int> map{{'I',1},{'V',5},{'X',10},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int romanToInt(string s) {
        int ret = 0;
        cout<<s[s.length()]<<endl;
        for (int i =0; i < s.length(); i++) {
            if (i+1<s.length() && map[s[i+1]]>map[s[i]]) {
                ret+= -map[s[i]];
            }  else {
                ret+=map[s[i]];
            }
        }
        return ret;
    }
};

struct RomanMap
{
	RomanMap()
	{
		memset(arr, 0, 50);
		arr['I' - 'A'] = 1;
		arr['V' - 'A'] = 5;
		arr['X' - 'A'] = 10;
		arr['L' - 'A'] = 50;
		arr['C' - 'A'] = 100;
		arr['D' - 'A'] = 500;
		arr['M' - 'A'] = 1000;
	}

	int get(char c)
	{
		if (c >= 'A' && c <= 'Z')
			return arr[c - 'A'];
		else
			return 0;
	}

	int arr[50];
};

//If pos is equal to the string length, the function returns a reference to the null character that follows the last character in the string (which should not be modified).
class Solution0 {
public:
	int romanToInt(string s) {
		static RomanMap roman;
		size_t len = s.length();
		int sum = 0;
		for (size_t i = 0; i < len; i++)
		{
			int cur = roman.get(s[i]); int next = roman.get(s[i + 1]);
			if (cur < next)
				sum += -cur;
			else
				sum += cur;
		}
		return sum;
	}
};

DEFINE_CODE_TEST(013_roman2integer)
{
    Solution0 obj;
    {
        VERIFY_CASE(obj.romanToInt("MCMXCIV"),1994);
        VERIFY_CASE(obj.romanToInt("LVIII"),58);
        VERIFY_CASE(obj.romanToInt("IV"),4);
    }
}