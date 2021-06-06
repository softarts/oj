//
// Created by rui zhou on 23/03/19.
//
/*
 * You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.



Example:



Input: {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":{"$id":"6","left":null,"next":null,"right":null,"val":6},"next":null,"right":{"$id":"7","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}

Output: {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":{"$id":"6","left":null,"next":null,"right":null,"val":7},"right":null,"val":6},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"7","left":{"$ref":"5"},"next":null,"right":{"$ref":"6"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"7"},"val":1}

Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B.
 参考lc103
 */

#include <codech/codech_def.h>
using namespace std;

namespace {

// Definition for a Node.
    class Node {
    public:
        int val;
        Node* left;
        Node* right;
        Node* next;

        Node() {}

        Node(int _val, Node* _left, Node* _right, Node* _next) {
            val = _val;
            left = _left;
            right = _right;
            next = _next;
        }
    };

    class Solution {
    public:
        Node* connect(Node* root) {
            if (!root)
                return root;
            deque<Node*> deq{root};
            while (!deq.empty()) {
                vector<Node*> layer;
                while (!deq.empty()) {
                    Node*node=deq.front();
                    deq.pop_front();
                    if (node->left)
                        layer.emplace_back(node->left);
                    if (node->right)
                        layer.emplace_back(node->right);
                }

                for (int i=0;i<layer.size();i++) {
                    if (i!=0)
                        layer[i-1]->next=layer[i];
                    deq.emplace_back(layer[i]);
                }
            }
            return root;
        }

    };
}

DEFINE_CODE_TEST(116_populating_nextrightptr)
{
    Solution obj;
    {
        Node *node4 = new Node(4,nullptr,nullptr,nullptr);
        Node *node5 = new Node(5,nullptr,nullptr,nullptr);
        Node *node2 = new Node(2,node4,node5,nullptr);
        Node *node6 = new Node(6,nullptr,nullptr,nullptr);
        Node *node7 = new Node(7,nullptr,nullptr,nullptr);
        Node *node3 = new Node(3,node6,node7,nullptr);
        Node *node1 = new Node(1,node2,node3,nullptr);
        obj.connect(node1);
    }
}