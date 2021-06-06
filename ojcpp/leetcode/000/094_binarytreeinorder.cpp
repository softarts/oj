//
// Created by zhou rui on 29/3/18.
//

/*
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 * Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?


 */

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
#include <codech/algo_common.h>
#include <stack>

using namespace CODECH;
using namespace std;

class Solution {
public:
//    vector<int> inorderTraversal(TreeNode* root) {
//        vector<int> ret;
//        vector<int> heap;
//        deque<TreeNode*> q{root};
//        while (!q.empty()) {
//            TreeNode *node = q.front();
//            q.pop_front();
//            if (node!=nullptr) {
//                heap.emplace_back(node->val);
//                q.push_back(node->left);
//                q.push_back(node->right);
//            } else {
//                heap.emplace_back(null);
//            }
//        }
//        // process the heap
//
//        return ret;
//    }
//    void loop(stack<TreeNode*> &st, unordered_set<TreeNode*> &visited,TreeNode *&node) {
//        if  (node) {
//            node = node->left;
//            st.push(node);
//        }
//    }
//    vector<int> inorderTraversal(TreeNode* root) {
//        vector<int> ret;
//        stack<TreeNode*> st;
//        unordered_set<TreeNode*> visited;
//        st.push(root);
//
//        while (!st.empty()) {
//            TreeNode *node = st.top();
//            if (!node) {
//                st.pop();continue;
//            }
//
//            if (visited.count(node)) {
//                st.pop();
//                ret.push_back(node->val);
//                if (node->right) {
//                    node = node->right;
//                    loop(st, visited, node);
//                }
//            } else {
//                loop(st, visited, node);
//            }
//        }
//        return ret;
//    }

     // omg, i figure out this solution!!!!
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ret;
        TreeNode *node = root;
        while (node) {
            st.push(node);
            node = node->left;
        }

        while (!st.empty()) {
            TreeNode*node = st.top();
            if (node) {
                ret.push_back(node->val);
                st.pop();
                node = node->right;
                while (node) {
                    st.push(node);
                    node = node->left;
                }
            } else {
                st.pop();
            }
        }
        return ret;
    }

    // a trivial solution
    void loop(TreeNode* root, vector<int> &v) {
        if (root==nullptr)
            return;
        if (root->left)
            loop(root->left, v);
        v.push_back(root->val);
        if (root->right)
            loop(root->right, v);
    }

    vector<int> inorderTraversal1(TreeNode* root) {
        vector<int> v;
        loop(root,v);
        return v;
    }

};


DEFINE_CODE_TEST(094_binarytreeinorder)
{
    Solution obj;
    {
        TreeNode *root = LCREATE_TREENODE({1,null,2,3,null,null,null});
        VERIFY_CASE(PRINT_VEC(obj.inorderTraversal1(root)),"1 3 2");

    }
}