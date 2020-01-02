//
// Created by rui zhou on 2020-01-01.
//

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace {
    class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            vector<int> ans{1};
            for (int i=0;i<rowIndex;i++) {
                int prev=1;
                for (int j=1;j<ans.size();j++) {
                    ans[j]=ans[j]+prev;
                    prev=ans[j]-prev;
                }
                ans.emplace_back(1);
            }
            return ans;
        }
    };
}


DEFINE_CODE_TEST(119_pascaltriangle2)
{
    Solution obj;
    {
        VERIFY_CASE(PRINT_VEC(obj.getRow(2)),"1 2 1");
        VERIFY_CASE(PRINT_VEC(obj.getRow(0)),"1");
        VERIFY_CASE(PRINT_VEC(obj.getRow(1)),"1 1");
        VERIFY_CASE(PRINT_VEC(obj.getRow(3)),"1 3 3 1");
    }

}