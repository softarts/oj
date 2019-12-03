//
// Created by rui zhou on 2019-12-02.
//


// 将二叉树转成一个排序的双向链表，不能创建新的节点
//   10
// 6   14
//4 8 12 16
//4-6-8-10-12-14-16


//lc426
/*
 * [LeetCode] 426. Convert Binary Search Tree to Sorted Doubly Linked List 将二叉搜索树转为有序双向链表


Convert a BST to a sorted circular doubly-linked list in-place. Think of the left and right pointers as synonymous
 to the previous and next pointers in a doubly-linked list.

Let's take the following BST as an example, it may help you understand the problem better:


We want to transform this BST into a circular doubly linked list. Each node in a doubly linked list has a predecessor
 and successor. For a circular doubly linked list, the predecessor of the first element is the last element, and the
 successor of the last element is the first element.

The figure below shows the circular doubly linked list for the BST above. The "head" symbol means the node it points
 to is the smallest element of the linked list.


Specifically, we want to do the transformation in place. After the transformation, the left pointer of the tree node
 should point to its predecessor, and the right pointer should point to its successor. We should return the pointer
 to the first element of the linked list.

The figure below shows the transformed BST. The solid line indicates the successor relationship, while the dashed
 line means the predecessor relationship.

这道题给了一个二叉搜索树，让我们将其转化为双向链表。并且题目中给了一个带图的例子，帮助理解。题目本身并不难理解，仔细观察下给的示例图。
 首先，转化成双向链表的每个结点都有 left 和 right 指针指向左右两个结点，不管其原来是否是叶结点还是根结点，转换后统统没有区别。其次，
 这是个循环双向链表，即首尾结点是相连的，原先的二叉搜索树中的最左结点和最右结点，现在也互相连接起来了。最后，返回的结点不再是原二叉
 搜索树的根结点 root 了，而是最左结点，即最小值结点。

好，发现了上述规律后，来考虑如何破题。根据博主多年经验，跟二叉搜索树有关的题，肯定要利用其性质，即左<根<右，即左子结点值小于根结点值小
 于右子结点值。而且十有八九都得用中序遍历来解，因为中序遍历的顺序就是左根右啊，跟性质吻合。观察到原二叉搜索树中结点4连接着结点2和结点5，
 而在双向链表中，连接的是结点3和结点5，这就是为啥要用中序遍历了，因为只有中序遍历，结点3之后才会遍历到结点4，这时候可以将结点3和结点4
 串起来。决定了用中序遍历之后，就要考虑是迭代还是递归的写法，博主建议写递归的，一般写起来都比较简洁，而且递归是解树类问题的神器啊，十有
 八九都是用递归，一定要熟练掌握。再写中序遍历之前，其实还有难点，因为需要把相邻的结点连接起来，所以需要知道上一个遍历到的结点是什么，所
 以用一个变量 pre，来记录上一个遍历到的结点。还需要一个变量 head，来记录最左结点，这样的话，在递归函数中，先判空，之后对左子结点调用递
 归，这样会先一直递归到最左结点，此时如果 head 为空的话，说明当前就是最左结点，赋值给 head 和 pre，对于之后的遍历到的结点，那么可以和
 pre 相互连接上，然后 pre 赋值为当前结点 node，再对右子结点调用递归即可，参见代码如下：
 */

#include <codech/codech_def.h>
using namespace CODECH;
using namespace std;

namespace {
    //该方法并不好，没考虑返回的节点在链表中的位置
//    class Solution {
//    public:
//        TreeNode* _head = nullptr;
//        TreeNode* tolist(TreeNode*root) {
//            helper(root);
//            return _head;
//        }
//
//        TreeNode* helper(TreeNode*root) {
//            if (root==nullptr)
//                return nullptr;
//
//            TreeNode*leftTree = root->left;
//            TreeNode*rightTree = root->right;
//
//            TreeNode*left = helper(leftTree);
//            if (left) {
//                if (_head==nullptr) {
//                    _head = left;
//                }
//                left->left = root;
//                root->right = left;
//            }
//
//            TreeNode*right = helper(rightTree);
//            if (right) {
//                right->right = root;
//                root->left = right;
//                return right;
//            }
//            return root; // 返回最大值
//        }
//    };
    class Solution {
    public:
        TreeNode* _head = nullptr;
        TreeNode* tolist(TreeNode*node) {
            if (node==nullptr)
                return nullptr;

        }

        void inorder(TreeNode* node,TreeNode*parent) {
            if (node==nullptr)
                return;

//            TreeNode*leftTree = node->left;
//            TreeNode*rightTree = node->right;

            inorder(node->left,parent);
            if (_head==nullptr) {
                _head = node;
            } else {
                node->left = parent;
                parent->right = node;
                parent = node;
            }

            inorder(node->right,parent);
            parent->left = node;
            node->right = parent;

            // 左右子树返回的值不一样，一个最大，一个最小
            // 不能用返回值
            //



        }
    };
}

//   10
// 6   14
//4 8 12 16
//4-6-8-10-12-14-16

void loop(TreeNode*node) {
    TreeNode*prev = nullptr;
    while (node) {
        cout << node->val << "-->";
        prev = node;
        node = node->left;
    }
    cout << "***";
    node = prev;
    while (node) {
        cout << node->val << "-->";
        prev = node;
        node = node->right;
    }

}
DEFINE_CODE_TEST(027_bst_to_lst)
{
    Solution obj;
    {
        TreeNode* root = CREATE_TREENODE({10,6,14,4,8,12,16});
        TreeNode *head = obj.tolist(root);
        loop(head);
    }


}

