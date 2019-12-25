//
// Created by rui zhou on 2019-12-22.
//

/*
 * Given a binary tree, return the vertical order traversal of its nodes values.

For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).

Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing Y coordinates).

If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.

Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.



Example 1:



Input: [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Without loss of generality, we can assume the root node is at position (0, 0):
Then, the node with value 9 occurs at position (-1, -1);
The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2);
The node with value 20 occurs at position (1, -1);
The node with value 7 occurs at position (2, -2).

 vector<vector<int>> verticalTraversal(TreeNode* root) {
            using elem_t = pair<int,int>;
            using treemap_t = map<int,list<elem_t>>;
            treemap_t tree;
            deque<pair<TreeNode*,pair<int,int>>> todo{(root,(0,0))};

            while (!todo.empty()) {
                vector<pair<TreeNode *,pair<int,int>>> layerNodes;

                while (!todo.empty()) {
                    auto &elem = todo.front();
                    auto &pos = elem.second;
                    auto &node = elem.first;
                    todo.pop_front();
                    int x = pos.first;
                    int y = pos.second;
                    auto &lst = tree[x];
                    lst.emplace_back((y,node->val));
                    if (node->left) {
                        layerNodes.emplace_back((node->left,(x-1,y-1));
                    }
                    if (node->right) {
                        layerNodes.emplace_back((node->right,(x+1,y-1));
                    }
                }
                for (auto &&pr: layerNodes) {
                    todo.emplace_back(pr);
                }
            }
            vector<vector<int>> ans;
            for (auto &&iter:tree) {
                int x = iter.first;

            }


        }

 */

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
    class Solution {
    public:
        vector<vector<int>> verticalTraversal(TreeNode* root) {
            using elem_t = pair<int,int>;
            using treemap_t = map<int,vector<int>>;
            treemap_t tree;
            deque<pair<TreeNode*,pair<int,int>>> todo{{root,{0,0}}};

            while (!todo.empty()) {
                vector<pair<TreeNode *,pair<int,int>>> layerNodes;

                treemap_t tmptree;
                while (!todo.empty()) {
                    auto &elem = todo.front();
                    auto &pos = elem.second;
                    auto &node = elem.first;
                    todo.pop_front();
                    int x = pos.first;
                    int y = pos.second;

                    auto &lst = tmptree[x];
                    lst.emplace_back((node->val));

                    if (node->left) {
                        layerNodes.emplace_back(make_pair(node->left,make_pair(x-1,y-1)));
                    }
                    if (node->right) {
                        layerNodes.emplace_back(make_pair(node->right,make_pair(x+1,y-1)));
                    }
                }

                for (auto &&pr: layerNodes) {
                    todo.emplace_back(pr);
                }

                for (auto&&it:tmptree) {
                    int x = it.first;
                    auto &lst = it.second;
                    sort(lst.begin(),lst.end());
                    auto &target = tree[x];
                    for (auto &it:lst) {
                        target.emplace_back(it);
                    }
                    //tree[x].insert(tree[x].end(),lst.begin(),lst.end());
                }
            }
            vector<vector<int>> ans;
            for (auto &&iter:tree) {
                int x = iter.first;
                auto &lst = iter.second;
                ans.emplace_back(lst);
            }
            return ans;
        }

    };
}

DEFINE_CODE_TEST(987_verticalordertree)
{
    Solution obj;

}