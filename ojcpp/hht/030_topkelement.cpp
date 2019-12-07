//
// Created by rui zhou on 2019-12-03.
//

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;
//最小的k个数
//sort之后,O(NLogN)
// nthelement
//优先队列

namespace {
    class Solution {
    public:

        //思路,将所有小于pivot的数放到左边,这是其中一种分区方法,Log(N)
        int partition(vector<int>&arr,int low,int high) {
            int pivot = arr[low];
            while (low<high) {
                while (low < high && arr[high]>=pivot) high--;
                arr[low] = arr[high];
                while (low<high && arr[low]<=pivot) low++;
                arr[high] = arr[low];
            }
            arr[low]=pivot;
            return low;
        }

        vector<int> topksmallest(vector<int>&arr, int k) {
            int low=0,high=arr.size()-1;
            int cut = partition(arr,low,high);
            while (cut!=k-1) {
                if (cut>k-1) {
                    low=cut;
                } else {
                    high = cut;
                }
                cut = partition(arr,low,high);
            }

            vector<int> ans;
            copy(arr.begin(),arr.begin()+k,back_inserter(ans));
            sort(ans.begin(),ans.end());
            return ans;
        }
    };
}

DEFINE_CODE_TEST(hht_030_topk)
{
    Solution obj;
    {
        vector<int> arr{4,5,1,6,2,7,3,8};
        VERIFY_CASE(PRINT_VEC(obj.topksmallest(arr,4)),"1 2 3 4")
    }

}
