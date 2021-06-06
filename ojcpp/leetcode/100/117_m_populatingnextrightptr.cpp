//
// Created by rui zhou on 2020-01-01.
//

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace {
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/


    class Solution {
    public:
        using Node = TreeNode;
        Node* connect(Node* root) {
            if (!root) return root;
            vector<Node*> layer{root};
            helper(layer);
            return root;
        }

        void helper(vector<Node*> &layer) {
            vector<Node*> next;
            for (int i=0;i<layer.size();i++) {
                if (i==layer.size()-1) {
                    layer[i]->next = nullptr;
                } else {
                    layer[i]->next = layer[i+1];
                }

                if (layer[i]->left) {
                    next.emplace_back(layer[i]->left);
                }
                if (layer[i]->right) {
                    next.emplace_back(layer[i]->right);
                }
            }
            if (!next.empty())
                helper(next);
        }
    };
}

DEFINE_CODE_TEST(117_populating_right_node)
{
    Solution obj;
    {
        TreeNode *root=CREATE_TREENODE({1,2,3,4,5,null,7});
        obj.connect(root);
        cout << "done\n";
    }
}
