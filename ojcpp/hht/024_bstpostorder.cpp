//
// Created by rui zhou on 2019-11-24.
//

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

// 给出一组数字，判断是否为二叉树的后序遍历
namespace {
    class Solution {
    public:
        bool veriftbst(vector<int> &arr) {
            if (arr.size()==1) return true;
            if (arr.size()==0) return false;

            return helper(arr,0,arr.size()-1);
        }

        bool helper(vector<int> &arr,int begin,int end) {
            if (begin>=end)
                return true;

            int root = arr[end];
            int l0 = begin,l1=end-1;

            for (int i=begin;i<end;i++) {
                if (arr[i]>root) {
                    l1 = i;break;
                }
            }
            //verify left tree
            if (!helper(arr,l0,l1-1))
                return false;

            // right tree, should > root
            for (int i=l1+1;i<end;i++) {
                if (arr[i]<root) {
                    return false;
                }
            }

            int r0 = l1+1,r1 = end-1;
            if (!helper(arr,r0,r1))
                return false;

            return true;
        }
    };
}


DEFINE_CODE_TEST(024_verifybst_postorder)
{
    Solution obj;
    {
        vector<int> arr{5,7,6,9,11,10,8};
        VERIFY_CASE(obj.veriftbst(arr),true);
    }
    {
        vector<int> arr{7,4,6,5};
        VERIFY_CASE(obj.veriftbst(arr),false);
    }
}