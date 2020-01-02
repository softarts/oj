#ifndef ALGO_COMMON_H_
#define ALGO_COMMON_H_

#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <deque>
#include <climits>
#include "codech_util.h"

namespace CODECH
{
    //const long null = LONG_MAX;
    const int null = INT_MIN;
    //const double null = std::numeric_limits<double>::infinity();

    struct TreeNode {        
        //int data;
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode *next = nullptr;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    // create tree per layer
    //TreeNode* CREATE_TREENODE(int idx, const std::vector<int> &list);
    TreeNode* CREATE_TREENODE(const std::vector<int> &list);

    // deprecated
    TreeNode* LCREATE_TREENODE(const std::vector<int> &list);

    // node data first
    std::string TREE_PREORDER(TreeNode*root);

    std::string TREE_BYLEVEL(TreeNode*root);

    TreeNode* FIND_NODE(TreeNode *root, int val);

    // linkedlist ==================================
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode * CREATE_LIST(int size);

    ListNode * CREATE_LIST(std::vector<int> &&vec);

    ListNode* FIND_LISTNODE(ListNode* head,int val);

    std::string PRINT_LIST(ListNode *head);

    // array ========================================

    bool VERIFY_VVECINT(std::vector<std::vector<int>> &&m, std::vector<std::vector<int>> &n);

    std::string PRINT_VEC(std::vector<int> &&vec);

    std::string PRINT_VVEC(std::vector<std::vector<int>> &&m);

    std::string PRINT_STRVEC(std::vector<std::string>  &&m);

    std::string PRINT_MATRIX(std::vector<std::vector<int>> &m);

    template<typename T>
    bool VERIFY_VV(std::vector<std::vector<T>> &&m,std::vector<std::vector<T>> &n, bool sort_flag=true){
            std::vector<T> a,b;
            for (auto &row : m){
                for (auto &v : row) {
                    a.emplace_back(v);
                }
            }
            for (auto &row : n){
                for (auto &v : row) {
                    b.emplace_back(v);
                }
            }
            if (sort_flag) {
                sort(a.begin(),a.end());
                sort(b.begin(),b.end());
            }

            if (a!=b) {
                for (auto &row : m){
                    for (auto &v : row) {
                        std::cout << v << " ";
                    }
                    std::cout<<std::endl;
                }
                std::cout<<std::endl;
                return false;
            }
            return true;
    }

    template<typename T>
    bool VERIFY_VEC0(std::vector<T> &&m,std::vector<T> &n){
        sort(m.begin(),m.end());
        sort(n.begin(),n.end());
        if (m!=n) {
            for (auto &v : m){
                std::cout << v << " ";
            }
            std::cout<<std::endl;
            return false;
        }
        return true;
    }

    template<typename T>
    bool VERIFY_VEC(std::vector<T> &&m,std::vector<T> &&n){
        //sort(m.begin(),m.end());
        //sort(n.begin(),n.end());
        if (m!=n) {
            for (auto &v : m){
                std::cout << v << " ";
            }
            std::cout<<std::endl;
            return false;
        }
        return true;
    }

    // graph ===========================================================
    struct UndirectedGraphNode {
        int val;
        std::vector<UndirectedGraphNode *> neighbors;
        UndirectedGraphNode(int x) : val(x) {};
    };

    UndirectedGraphNode* CREATE_GRAPH(std::vector<std::vector<int>> &adjList);
    std::string GRAPH_BFS(UndirectedGraphNode *node);
}
#endif