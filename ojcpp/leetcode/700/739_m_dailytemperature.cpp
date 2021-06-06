//
// Created by rui zhou on 2019-09-03.
//

/* https://leetcode.com/problems/daily-temperatures/
 * Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].
 */

#include <codech/codech_def.h>

using namespace std;
using namespace CODECH;

namespace {
    class Solution0 {
    public:
        vector<int> dailyTemperatures(vector<int>& T) {
            vector<int> ret;
            for (size_t i=0;i<T.size();i++) {
                bool found = false;
                for (size_t j=i+1;j<T.size();j++) {
                    if (T[j]>T[i]) {
                        ret.emplace_back(j-i);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    ret.emplace_back(0);
                }
            }
            return ret;
        }
    };

    class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& T) {
            vector<int> ret(T.size(),0);
            stack<pair<int,int>> st;
            st.emplace(make_pair(T[0],0));

            for (size_t i=1;i<T.size();i++) {
                while (!st.empty()) {
                    auto prev = st.top();
                    if ( T[i] > prev.first ) {
                        int days = i - prev.second;
                        ret[prev.second] = days;
                        st.pop();
                    } else {
                        break;
                    }
                }
                st.emplace(make_pair(T[i],i));
            }

            return ret;
        }
    };
}

DEFINE_CODE_TEST(739_daily_temperature)
{
    Solution obj;
    {
        vector<int> temps{73, 74, 75, 71, 69, 72, 76, 73};
        vector<int> exp = {1, 1, 4, 2, 1, 1, 0, 0};
        auto actual = obj.dailyTemperatures(temps);
        cout << PRINT_VEC(move(actual)) << endl;
        VERIFY_CASE(actual == exp,true);

    }
}