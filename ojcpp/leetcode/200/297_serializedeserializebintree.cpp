/*
序列化反序列化二叉树，注意，不是二叉搜索树
*/

#include <codech/codech_def.h>
using namespace CODECH;
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::deque<TreeNode*> deq{root};
        stringstream ss;
        while (!deq.empty()) {
            TreeNode *node = deq.front();
            deq.pop_front();
            if (node) {
                ss << node->val;
                deq.emplace_back(node->left);
                deq.emplace_back(node->right);
            } else {
                ss<<"na";
            }
            if (!deq.empty()) {
                ss<<",";
            }
        }
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        TreeNode dummy(0);
        TreeNode *parent=&dummy;
        deque<TreeNode*> deq{parent};
        int idx = 0;
        size_t sz;
        string tmp;
        while (getline(ss,tmp,',')) {
            if (!deq.empty()) {
                parent = deq.front();
            } else {
                break;
            }
            TreeNode *child = nullptr;
            if (tmp!="na") {
                int val = stoi(tmp,&sz,10);
                child = new TreeNode(val);
            } else {
                child = nullptr;
            }
            if (idx%2==1) {
                parent->left = child;
            } else {
                parent->right = child;
                deq.pop_front();
            }

            if (child) {
                deq.emplace_back(child);
            }
            idx++;
        }
        return dummy.right;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

