//
// Created by rui zhou on 2019-12-03.
//

#include <codech/codech_def.h>
using namespace std;

// [3, 32, 321] -> 形成一个最小的数 321323
//lc 179
namespace {
    class Solution {
    public:
        string find_smallest(vector<string> &arr) {
            sort(arr.begin(),arr.end(),[](string&a,string&b){
               return a+b < b+a;
            });
            stringstream ss;
            copy(arr.begin(),arr.end(),ostream_iterator<string>(ss));
            return ss.str();

        }
    };
}

DEFINE_CODE_TEST(hht_033_smalleststr)
{
    Solution obj;
    {
        vector<string> arr = {"3","32","321"};
        VERIFY_CASE(obj.find_smallest(arr),"321323");
    }

}
