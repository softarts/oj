//
// Created by rui.zhou on 3/7/2019.
//

/*
 * The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"

 1 x 2 x 3 x 4...
 难点在于如何判别第K个permutation
1234    2134    3124    4123
1243    2143    3142    4132
1324    2314    3214    4213
1342    2341    3241    4231
1423    2413    3412    4312
1432    2431    3421    4321

 从阶乘的基本规律我们可以看到对于数字n来说，从1到n的每个数字开头的排列有(n - 1)!个。
 就像前面这样，以1, 2, 3, 4分别开头的排列它们每个都是有6个。因此对于我们的数字k来说，它对(n - 1)!相除得到的值就是当前所在的列，
 这个列索引就是我们所要确定的第一个元素。而它对(n - 1)!取余数，得到的数字就是当前剩余数组的index，因此也就可以得到对应的元素。
 在具体的实现里，我们需要用一个数组来保存数字1到n，每次找到对应索引的时候，从数组里把这个元素取出来加入到结果数组中，
 并将它从原来的数组里删除。
 */

#include <codech/codech_def.h>
using namespace std;

class Solution {
public:
    // n! => 每个col有(n-1)!的组合.
    // n=3 ,每个col size= 2  ([1,1],[2,2],[3,3]
    // n=2, 每个col size= 1 [1],[2]
    string getPermutation(int n, int k) {
        vector<int> nums;
        int fact=1;
        for (int i=1;i<n;i++) {
            fact*=i;
        }
        for (int i=1;i<=n;i++) {
            nums.emplace_back(i);
        }
        int rank= k-1;
        vector<int> ret;
        for (int i=n-1;i>0;i--) { //(n-1)!= (n-1)*(n-2)，所以以n-1为起点
            int index = rank/fact;  //找出col
            ret.emplace_back(nums[index]);
            nums.erase(nums.begin()+index);
            rank %=fact;
            fact/=i;
        } //正好取掉了n-1个字符。
        ret.emplace_back(nums[0]);//最后一个
        std::ostringstream oss;
        std::copy(ret.begin(), ret.end(),std::ostream_iterator<int>(oss, ""));
        return oss.str();
    }

};

DEFINE_CODE_TEST(060_permutationseq)
{
    Solution obj;
    {
        VERIFY_CASE(obj.getPermutation(4,9),"2314");
        VERIFY_CASE(obj.getPermutation(3,3),"213");
        VERIFY_CASE(obj.getPermutation(3,6),"321");
        VERIFY_CASE(obj.getPermutation(3,1),"123");

    }
}

// 方法完全错了
//    string getPermutation(int n, int k) {
//        int f=1,j=1;
//        for (int i=1;i<=n;i++) {
//            f=f*i;
//            if (f>k) {
//                j=i-1;
//                f=f/i;
//                break;
//            } else {
//                j=i;
//            }
//        }
//        vector<int> nums;
//        for (int i=j;i>0;i--) {
//            nums.emplace_back(i);
//        }
//        for (int i=j+1;i<=n;i++) {
//            nums.emplace_back(i);
//        }
//        int count=f+1;
//        while (count<k) {
//           next_permutation(nums.begin(),nums.end());
//           count++;
//        }
//
//        std::ostringstream oss;
//        std::copy(nums.begin(), nums.end(),std::ostream_iterator<int>(oss, ""));
//        return oss.str();
//    }