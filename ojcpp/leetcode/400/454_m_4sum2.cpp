//
// Created by rui.zhou on 2/1/2019.
//

/*
 * Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
 */
#include <codech/codech_def.h>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> map;
        
        int count = 0;
        for (auto a: A) {
            for (auto b: B) {
                map[a+b]+=1;
            }
        }
        for (auto c:C) {
            for (auto d:D) {
                int cd = -(c+d);
                if (map.find(cd)!=map.end()) {
                    count+=map[cd];
                }
            }
        }
        return count;
    }
};

DEFINE_CODE_TEST(454_4sum2)
{
    Solution obj;
    {
        vector<int> a{1,2},b{-2,-1},c{-1,2},d{0,2};
        VERIFY_CASE(obj.fourSumCount(a,b,c,d),2);
    }
    {
        vector<int> a{0,0},b{0,0},c{0,0},d{0,0};
        VERIFY_CASE(obj.fourSumCount(a,b,c,d),16);
    }
}