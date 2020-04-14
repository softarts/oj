//
// Created by rui zhou on 08/05/19.
//

//一个数是否是丑数， only division 2，3，5
//丑数应是另一个丑数乘以2，3，5的结果
// 思路 LC264

#include <codech/codech_def.h>

using namespace std;

namespace {
    class Solution {
    public:
        int getUgly(int index) {
            vector<int> arr(index);
            if (index<=0) return 0;
            arr[0]=1;
            int *u2=&arr[0],*u3=&arr[0],*u5=&arr[0];
            int next=1;
            while (next < index) {
                arr[next]=std::min({*u2*2,*u3*3,*u5*5});
                while (*u2*2<=arr[next])
                    u2++;
                while (*u3*3<=arr[next])
                    u3++;
                while (*u5*5<=arr[next])
                    u5++;
                next++;
            }
            return arr[index-1];
        }
    };
}


DEFINE_CODE_TEST(034_ugly)
{
    Solution obj;
    {
        VERIFY_CASE(obj.getUgly(1500),859963392);
        VERIFY_CASE(obj.getUgly(1500),859963392);
    }
}



