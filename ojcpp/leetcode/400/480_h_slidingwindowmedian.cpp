#include <codech/codech_def.h>
#include <set>
using namespace std;
//using namespace CODECH
/*
使用multiset'
维护中位数指针，这个中位数指针指向奇数区间的正中间或者偶数区间中间靠右的位置(e.g. [1,2,3,4]中的3)。
既然每次会插入和删除元素各一个数字（总区间长度不变）：当插入一个数字时，如果这个数字比中位数小，则中位数左边的数字变多，
那么把中位数指针向左边移动一个位置；当删除一个数字时，如果小于等于中位数（这里的等于是因为可能中位数被删除），
则中位数左边的数字变少，那么把中位数指针向右边移动一个位置。

为什么只比较小于等于中位数，不判断当插入和删除的数字大于中位数时要如何移动指针呢？这个和我们每次插入和删除各一个数字有关，
如果插入和删除都是比中位数大的，那么中位数不用动；如果插入和删除都是比中位数小的，那么中位数向左一步向右一步也没变；
如果插入和删除一个比中位数大一个比中位数小，那么中位数正好按照两个if中的一个移动一个位置，仍然指向中位数

-1 ,1 ,3 , (mid)==>1
-3 ,-1 ,3 , (mid)==>-1
-3 ,-1 ,5 , (mid)==>-1
-3 ,3 ,5 , (mid)==>3
3 ,5 ,6 , (mid)==>5
3 ,6 ,7 , (mid)==>6
1 , -1 , -1 , 3 , 5 , 6 , zhous-MacBook-Pro:build zhourui$ 

*/
namespace {
    class Solution {
    public:
        vector<double> medianSlidingWindow(vector<int>& nums, int k) {
            multiset<double> ms(nums.begin(),nums.begin()+k);
            auto mid = next(ms.begin(),k/2);
            vector<double> ans;

            for (int i=k;;i++) {
                ans.emplace_back((*mid+*prev(mid,1-k%2))/2.0);
                if (i==nums.size()) {
                    return ans;
                }
                ms.insert(nums[i]);       // 先插入再调整
                for (auto iter:ms) {
                    cout << iter << " ,";
                }
                cout << " (mid)==>" << *mid << endl;
                if (*mid>nums[i]) mid--;  // 在mid前面多一个元素
                //else mid++;

                if (nums[i-k]<=*mid) mid++;  //要在mid前面移除一个元素，因此mid++
                //else mid--;  不能再作此处理，因为有可能mid已变化，不再是之前的那个
                //可能的情况，前面已经mid--了，结果这里再比较mid,导致再次mid--
                //切记，无论做如何判断，这里mid要么+1,要么-1，要么不变，不可能-2,+2
                //如果插入和删除都是比中位数大的，那么中位数不用动；
                //如果插入和删除都是比中位数小的，那么中位数向左一步向右一步也没变；
                //如果插入和删除一个比中位数大一个比中位数小，那么中位数正好按照两个if中的一个移动一个位置，仍然指向中位数。
                ms.erase(ms.find(nums[i-k]));
            }
            return ans;

        }
    };
}

DEFINE_CODE_TEST(480_slidingwindow)
{
    Solution obj;
    {
        vector<int> nums={1,3,-1,-3,5,3,6,7};
        for (auto iter:obj.medianSlidingWindow(nums,3)) {
            cout << iter << " , ";
        }
    }
}
