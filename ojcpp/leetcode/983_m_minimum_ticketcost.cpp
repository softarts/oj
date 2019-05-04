//
// Created by rui zhou on 03/05/19.
//

/*
 * In a country popular for train travel, you have planned some train travelling one year in advance.  The days of the year that you will travel is given as an array days.  Each day is an integer from 1 to 365.

Train tickets are sold in 3 different ways:

a 1-day pass is sold for costs[0] dollars;
a 7-day pass is sold for costs[1] dollars;
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.  For example, if we get a 7-day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 5, 6, 7, and 8.

Return the minimum number of dollars you need to travel every day in the given list of days.



Example 1:

Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation:
For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total you spent $11 and covered all the days of your travel.
Example 2:

Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation:
For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
In total you spent $17 and covered all the days of your travel.


Note:

1 <= days.length <= 365
1 <= days[i] <= 365
days is in strictly increasing order.
costs.length == 3
1 <= costs[i] <= 1000
 10:49
 */


#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution0 {
    public:
        int mincostTickets(vector<int>& days, vector<int>& costs) {
            if (min({costs[0],costs[1]/7,costs[2]/30}) == costs[0]) {
                return days.size()*costs[0];
            }

            int count = 3;
            if (costs[1]/7<costs[2]/30) {
                count = 2;
            }
            vector<int> dp(days.size()+1,0);
            for (int i=1;i<=days.size();i++) {
                dp[i]=dp[i-1]+costs[0];
            }

            vector<int> gap{1,7,30};
            int minCost=costs[0]*days.size();

            for (int i=0;i<3;i++) {
                int start = 0;
                for (int j=1;j<days.size();j++) {
                    if (days[j]-days[start]<gap[i]) {
                        dp[j+1] = min(dp[j+1],dp[start]+costs[i]);
                    } else {
                        dp[j+1] = min({dp[j+1],dp[j]+costs[0],dp[j]+costs[1],dp[j]+costs[2]});
                        start=j;
                    }
                }
            }
            return dp[days.size()];
        }
    };


    class Solution {
    public:
        int mincostTickets(vector<int>& days, vector<int>& costs) {
            if (min({costs[0],costs[1]/7,costs[2]/30}) == costs[0]) {
                return days.size()*costs[0];
            }

            int count = 3;
            if (costs[1]/7<costs[2]/30) {
                count = 2;
            }
            vector<int> dp(days.size()+1,0);
            for (int i=1;i<=days.size();i++) {
                dp[i]=dp[i-1]+costs[0];
            }

            vector<int> gap{1,7,30};
            int minCost=costs[0]*days.size();

            for (int i=0;i<3;i++) {
                for (int j=0;j<days.size();j++) {

                    for (int k=j;k>0;k--) {
                        days[k]>days[j]-gap[i]
                    }





                }
            }
            return dp[days.size()];
        }
    };
}


DEFINE_CODE_TEST(993_minimum_ticketcost)
{
    Solution obj;
    {
        vector<int> days{1,4,6,9,10,11,12,13,14,15,16,17,18,20,21,22,23,27,28};
        vector<int> costs{3,13,45};
        VERIFY_CASE(obj.mincostTickets(days,costs),44);
    }
    {
        vector<int> days{1,2,3,4,5,6,7,8,9,10,30,31};
        vector<int> costs{2,7,15};
        VERIFY_CASE(obj.mincostTickets(days,costs),17);
    }
    {
        vector<int> days{1,4,6,7,8,20};
        vector<int> costs{2,7,15};
        VERIFY_CASE(obj.mincostTickets(days,costs),11);
    }

}