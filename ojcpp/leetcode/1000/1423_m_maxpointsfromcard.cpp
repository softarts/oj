/*
https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
There are several cards arranged in a row, and each card has an associated number of points The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

 

Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
Example 2:

Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.
Example 3:

Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.
Example 4:

Input: cardPoints = [1,1000,1], k = 1
Output: 1
Explanation: You cannot take the card in the middle. Your best score is 1. 
Example 5:

Input: cardPoints = [1,79,80,1,1,1,200,1], k = 3
Output: 202
2021-05-12

每次必须拿走头或尾部
0: [1,79,80,1,1,1,200,1] 
1: [1,79,80,1,1,1,200]  -->1
2: [1,79,80,1,1,1]  --> 1, 200
3: [1,79,80,1,1,1]  --> 1,200, amny one from left or right


1.递归, 每次选择左侧或者右侧， 考虑到k很大的话，会造成TLE
2.估计不能用贪心解法，可能在某侧最后面存在一个更大的数，而此时所有的k都选完了
3.考虑dp，但是看上去也需要k**2
4.presum的解法，假设全部取左侧k，得到一个presum，然后逐个从左面减去最后一个，取右边最后一个，看是否得到一个更大值，因为不需要顺序，只需要一个Max，所以这是可行的

这道题说是sliding window有些勉强，但是套路是必须先有个presum

*/
#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        int maxScore(vector<int>& cardPoints, int k) {
            auto maxsum = accumulate(cardPoints.begin(),cardPoints.begin()+k,0);
            int right = cardPoints.size()-1;
            int cursum = maxsum,i=0;
            while (--k >= 0) {
                cursum = cursum + cardPoints[right-i] - cardPoints[k];
                maxsum = max(maxsum, cursum);
                i++;
            }
            return maxsum;
        }
    };
}

DEFINE_CODE_TEST(1423_maxpointscard)
{
    Solution obj;
    {
        vector<int> a = {9,7,7,9,7,7,9};
        VERIFY_CASE(obj.maxScore(a,7),55);   
    }
     
}

