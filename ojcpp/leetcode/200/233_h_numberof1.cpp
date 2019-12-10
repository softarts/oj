//
// Created by rui zhou on 2019-12-10.
//

#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        int countDigitOne(int n) {
            int ans = 0;
            int round = n;
            int base = 1;
            while (round > 0) {
                int w = round%10;
                round = round / 10;
                ans += round*base;
                if (w>1) {
                    ans+=base;
                } else if (w==1) {
                    ans+=n%base+1;
                }
                base*=10;
            }
            return ans;
        }
    };
}