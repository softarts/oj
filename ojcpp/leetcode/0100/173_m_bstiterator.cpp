//
// Created by rui zhou on 2020-01-02.
//

/*
 * Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.



Example:



BSTIterator iterator = new BSTIterator(root);
iterator.next();    // return 3
iterator.next();    // return 7
iterator.hasNext(); // return true
iterator.next();    // return 9
iterator.hasNext(); // return true
iterator.next();    // return 15
iterator.hasNext(); // return true
iterator.next();    // return 20
iterator.hasNext(); // return false


Note:

next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
You may assume that next() call will always be valid, that is, there will be at least a next smallest number in the BST when next() is called.
 */

//需要实现一个最小堆

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace {
    /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
    class BSTIterator {
    public:
        deque<int> arr;
        BSTIterator(TreeNode* root) {
            dfs(root);
        }

        void dfs(TreeNode*node) {
            if (!node) return;
            dfs(node->left);
            arr.emplace_back(node->val);
            dfs(node->right);
        }

        /** @return the next smallest number */
        int next() {
            auto ret = arr.front();
            arr.pop_front();
            return ret;
        }

        /** @return whether we have a next smallest number */
        bool hasNext() {
            return (!arr.empty());
        }
    };

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
}
