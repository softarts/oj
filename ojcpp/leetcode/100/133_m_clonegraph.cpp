//
// Created by rui.zhou on 2/22/2019.
//

/*
 * Given the head of a graph, return a deep copy (clone) of the graph.
 * Each node in the graph contains a val (int) and a list (List[UndirectedGraphNode])
 * of its neighbors. There is an edge between the given node and
 * each of the nodes in its neighbors.

OJ's undirected graph serialization (so you can understand error output):
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node val and each neighbor of the node.


As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.


Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
Note: The information about the tree serialization is only meant so that you can understand error output if you get a wrong answer. You don't need to understand the serialization to solve the problem.
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */


#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

class Solution {
public:
    using Node=UndirectedGraphNode;

    void copyNode(Node*node) {

    }

    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> map;
        unordered_set<int> visited;

        if (!node) return nullptr;
        std::deque<Node*> todo{node};
        Node *retNode = nullptr;
        while (!todo.empty()) {
            Node *ugn = todo.front();
            int nodeLabel = ugn->val;
            todo.pop_front();

            if (visited.find(nodeLabel) != visited.end()) {
                continue;
            }
            visited.emplace(nodeLabel);
            Node *clone=map[nodeLabel];
            if (!clone) {
                clone = new Node(nodeLabel);
                map[nodeLabel] = clone;
            }
            //cout << "clone " << nodeLabel <<endl;

            if (!retNode) retNode=clone;
            //clone->neighbors = ugn->neighbors;
            for (int i=0;i<ugn->neighbors.size();i++) {
                Node *adj=map[ugn->neighbors[i]->val];
                if (!adj) {
                    adj = new Node(ugn->neighbors[i]->val);
                    map[adj->val] = adj;
                }
                clone->neighbors.emplace_back(adj);
                todo.emplace_back(ugn->neighbors[i]);
            }
        }
        return retNode;
    }
};

//
//class Solution {
//public:
//
//    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
//        unordered_set<int> visited;
//        if (!node) return nullptr;
//        std::deque<UndirectedGraphNode*> todo{node};
//        UndirectedGraphNode *retNode = nullptr;
//        while (!todo.empty()) {
//            UndirectedGraphNode *ugn = todo.front();
//            int nodeLabel = ugn->val;
//            todo.pop_front();
//
//            if (visited.find(nodeLabel) != visited.end()) {
//                continue;
//            }
//            visited.emplace(nodeLabel);
//            UndirectedGraphNode *clone=new UndirectedGraphNode(nodeLabel);
//            if (!retNode) retNode=clone;
//            clone->neighbors = ugn->neighbors;
//            for (int i=0;i<clone->neighbors.size();i++) {
//                todo.emplace_back(clone->neighbors[i]);
//            }
//        }
//        return retNode;
//    }
//};

DEFINE_CODE_TEST(133_clonegraph)
{
    Solution obj;
    {
        vector<vector<int>> nums{{0,1,2},{1,0,2},{2,0,1,2}};
        UndirectedGraphNode *node=CREATE_GRAPH(nums);
        UndirectedGraphNode* clone = obj.cloneGraph(node);
        VERIFY_CASE(GRAPH_BFS(clone),"#2,0,1,2#0,1,2#1,0,2");
    }
    {
        UndirectedGraphNode *node=nullptr;
        UndirectedGraphNode* clone = obj.cloneGraph(node);
        VERIFY_CASE(GRAPH_BFS(clone),"");
    }
    {
        vector<vector<int>> nums{{0,1,2},{1,0,2},{2,0,1,3},{3,2}};
        UndirectedGraphNode *node=CREATE_GRAPH(nums);
        UndirectedGraphNode* clone = obj.cloneGraph(node);
        VERIFY_CASE(GRAPH_BFS(clone),"#3,2#2,0,1,3#0,1,2#1,0,2");
    }

}

