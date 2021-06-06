//
// Created by rui.zhou on 2/15/2019.
//

/*
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I

1.本题需要仔细观察输出结果和row之间的关系，简单的逻辑可能不行.
2.直白的解法，首先标记每个字符所在的行，放入idl中.然后再按每行把字符取出来
3.其实可以先纵向放入字符，然后横向读出来的做法。


 */
#include <codech/codech_def.h>
using namespace std;

//class Solution {
//public:
//    string convert(string s, int numRows) {
//        int rid = 0;
//        vector<int> idl;
//        bool way = true;
//
//        for (auto c:s)
//        {
//            if (way)
//            {
//                idl.push_back(rid);
//                rid++;
//            }
//            else
//            {
//                idl.push_back(rid);
//                rid--;
//            }
//
//            if (rid == numRows)
//            {
//                way = false;
//                rid = numRows - 1 - 1;
//            }
//            else if (rid==0)
//            {
//                way = true;
//            }
//        }
//
//        string *srow = new string[numRows];
//        int idx = 0;
//        for (unsigned int i = 0; i < idl.size(); ++i)
//        {
//            srow[idl[i]].push_back(s.at(i));
//        }
//        string ret = "";
//
//        for (int i = 0; i < numRows; i++)
//        {
//            ret += srow[i];
//        }
//        delete[]srow;
//        return ret;
//    }
//};

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows<2)
            return s;
        vector<vector<char>> vec(numRows, vector<char>());
        int row = 0, x=1;
        for (auto c:s) {
            vec[row].push_back(c);
            row += x;
            if (row==numRows-1) {
                x=-1;
            } else if (row==0) {
                x=1;
            }
        }
        for (int i=1;i<numRows;i++) {
            vec[0].insert(vec[0].end(),vec[i].begin(),vec[i].end());
        }
        return string(vec[0].begin(),vec[0].end());
    }
};

DEFINE_CODE_TEST(006_zigzag)
{
    Solution obj;
    {
        string s="PAYPALISHIRING";
        VERIFY_CASE(obj.convert(s,3),"PAHNAPLSIIGYIR");
    }
}
