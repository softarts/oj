//
// Created by rui.zhou on 2/23/2019.
//

/*
 * Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

   这个简直没有思路，睡觉去了
利用1..n产生 所有独特的树


17:00
目前打算采用的方法太笨，但是思路可能是对的，一个新的节点，可以作为之前tree的parent,也可以作为其右树，
 但是需要针对1-2-3这种情况进行调整，例如1-2-3-4是一种情况，1-4-3-2又是另一种，从这里找出规律并生成子树，代码挺复杂的

 换一个思路，这种题目一般都是DP或者递归的方法，不然无法产生这种收敛的结果，考虑，取一个作为root,那么其左右两侧都是
 一棵树，从而可以递归的解决这个问题。

 */

#include <codech/codech_def.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace lc095 {
    class Solution {
    public:
        vector<TreeNode*> create(int start, int end) {
            vector<TreeNode*> lnodes;
            if (start>end) {
                lnodes.emplace_back(nullptr);
            }
            for (int i=start;i<=end;i++) {
                const auto &left = create(start,i-1);//第一次，左子树为null,第二次,0-0为左子树
                const auto &right = create(i+1,end);
                //相当于交叉组合
                for (auto &l:left) {
                    for (auto &r: right) {
                        TreeNode* node=new TreeNode(i);//如果左右均为空，那么就创建一个叶节点
                        node->left=l;
                        node->right=r;
                        lnodes.emplace_back(node);
                    }
                }
            }
            return lnodes;
        }

        vector<TreeNode*> generateTrees(int n) {
            vector<TreeNode*> ret=create(1,n);
            return ret;
        }
    };

    class Solution1 {
    public:
        vector<TreeNode*> create(int start, int end) {
            vector<TreeNode*> lnodes;
            for (int i=start;i<=end;i++) {
                auto &&left = create(start,i-1);
                auto &&right = create(i+1,end);

                if (left.empty()) {
                    left.emplace_back(nullptr);
                }
                if (right.empty()) {
                    right.emplace_back(nullptr);
                }
                for (auto &l:left) {
                    for (auto &r: right) {
                        TreeNode* node=new TreeNode(i);
                        node->right=r;// 应该是多个副本
                        node->left=l;// 应该是多个副本
                        lnodes.emplace_back(node);
                    }
                }
            }
            return lnodes;
        }

        vector<TreeNode*> generateTrees(int n) {
            vector<TreeNode*> ret=create(1,n);
            return ret;
        }
    };
//    class Solution {
//    public:
//        TreeNode *create(int n,vector<TreeNode*> &dp) {
//            vector<TreeNode*> ret;
//            for (int i=0;i<dp.size();i++) {
//                TreeNode *n1=new TreeNode(n);
//                n1->left=dp[i];
//
//                TreeNode *n2=new TreeNode(n);
//                TreeNode *tmp=dp[i];
//                while (tmp->right) {
//                    tmp=tmp->right;
//                }
//                tmp->right=n2;
//
//
//            }
//
//        }
//        vector<TreeNode*> generateTrees(int n) {
//            vector<vector<TreeNode*>> dp;
//            dp[0]=vector<TreeNode*>(1,new TreeNode(1));
//            TreeNode *p1=new TreeNode(1);
//            TreeNode *p2=new TreeNode(2);
//            p1->right=p2;
//            TreeNode *r1=new TreeNode(1);
//            TreeNode *r2=new TreeNode(2);
//            r2->left=r1;
//            dp[1]={p1,r2};
//
//            for (int i=2;i<=n;i++) {
//
//            }
//
//            return vector<TreeNode*>();
//        }
//    };
}

DEFINE_CODE_TEST(095_uniquebst2)
{
    lc095::Solution1 obj;
    {
        vector<TreeNode*> &&ret= obj.generateTrees(3);
        for (auto &n:ret) {
            cout<<TREE_PREORDER(n)<<endl;
        }
        //VERIFY_VEC(obj.generateTrees(2),));

    }
}
