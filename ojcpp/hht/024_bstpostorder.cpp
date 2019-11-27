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
        bool veriftbst(vector<int> &nums) {
            if (nums.size()==1) return true;
            if (nums.size()==0) return false;

            int n = nums.size()-1;


        }

        bool helper(vector<int> &arr,int begin,int end) {

//            int begin = 0;
//            int end = arr.size()-2;
            int root = arr[end];
            int left=begin,right;

            for (int i=begin;i<end;i++) {
                if (arr[i]>root) {
                    right = i;break;
                }
            }
            helper(arr,left,)
            for (int i=right;i<end;i++) {
                if (arr[i]<root) {
                    return false;
                }
            }
            return true;
        }
    };
}