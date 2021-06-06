/*
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
 * 
 * Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie,
 buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions
 at the same time (ie, you must sell the stock before you buy again).
->
if see lower price sell stock on previous day

 Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
不能在同一天买卖股票，求最大的profit
 */

#include <codech/codech_def.h>
#include <vector>

using namespace std;

namespace {
    class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            if(prices.size() == 0) return 0;
            int curmin = prices[0];
            int counts = 0;
            for(int i = 0; i <prices.size(); ++i){
                if(prices[i] > curmin){
                    counts += prices[i] - curmin;
                    curmin = prices[i];
                }else{
                    curmin = min(curmin, prices[i]);
                }
            }
            return counts;
        }
    };

    class Solution1 {
    public:
        // not a beautiful code, 比较挫的
        int maxProfit(vector<int>& prices) {
            if (prices.empty())
                return 0;
            int profit = 0;
            int prev = prices[0];
            int buy = -1;
            for (auto &p:prices)
            {
                // 如果发现今天的价格比prev低了，那就在prev卖出，今天买入
                if (p < prev) {
                    if (buy>=0) {
                        profit += prev - buy;
                        buy = -1;
                    }
                } else {
                    if (buy==-1) {//如果发现今天的价格比prev高了，那就prev买入，今天卖出
                        buy = prev;
                    }
                }
                prev = p;
            }
            if (buy>=0) { //结束后，如果仍然持有，那就
                profit += prev - buy;
                buy = -1;
            }
            return profit;
        }
    };

    //贪心算法，为何有效的?
    class Solution2 {
    public:
        // not a beautiful code, 比较挫的,用了太多的buy signal太繁琐了
        int maxProfit(vector<int>& prices) {
            if (prices.empty())
                return 0;
            int profit = 0;
            int prev = prices[0];
            int buy = -1;
            for (auto &p:prices)
            {
                // 如果发现今天的价格比prev低了，那就在prev卖出，今天买入
                if (p < prev) {
                    if (buy>=0) {
                        profit += prev - buy;
                        buy = -1;
                    }
                } else {
                    if (buy>=0) { //如果仍然持有，那就sell
                        profit += prev - buy;
                        buy = -1;
                    }else if (buy==-1) {//如果发现今天的价格比prev高了，那就prev买入，今天卖出
                        profit += p-prev;
                    }
                }
                prev = p;
            }

            return profit;
        }
    };

    // 简洁
    class Solution3 {
    public:
        int maxProfit(vector<int>& prices) {
            int total = 0;
            int pl = prices.size();
            for (int i = 0; i < pl-1; i++) {
                if (prices[i + 1] > prices[i]) total += prices[i + 1] - prices[i];// 不一定是同一天买卖
            }
            return total;
        }
    };

}



DEFINE_CODE_TEST(122_besttime_tobuysell_stock2)
{
    Solution3 obj;
    {
        vector<int> px{ 7,1,5,3,6,4 };
        VERIFY_CASE(obj.maxProfit(px), 7);
    }
    {
        vector<int> px{ 2,1,2,0,1};
        VERIFY_CASE(obj.maxProfit(px), 2);
    }
    

}