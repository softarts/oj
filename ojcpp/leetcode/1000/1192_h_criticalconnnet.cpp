//2021-04-26
#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;


// 一开始没想出来，主要是不知道某些算法会不会超时
// 
namespace {
    class Solution {
    public:

        void dfs(int i,vector<list<int>> &nodes,int parent,vector<int> &dfn,vector<int>&low,vector<vector<int>> &res) {
            static int time = 0;
            dfn[i] = low[i] = ++time;
            for (auto &it: nodes[i]) {
                int ni = it;
                if (ni==parent) {
                    continue;
                }
                if (dfn[ni]==-1) { // not visited
                    dfs(ni,nodes,i,dfn,low,res);
                    if (dfn[i] < low[ni]) {
                        res.push_back({i,ni});
                    }
                }
                low[i]=min(low[i],low[ni]);
            }
        }

        vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
            vector<int> dfn(n,-1);   // discover time
            vector<int> low(n,-1);
            vector<vector<int>> res;
            // create graph
            vector<list<int>> nodes(n,list<int>());
            for (auto &p:connections) {
                int src = p[0];
                int dst = p[1];
                nodes[src].push_back(dst);
                nodes[dst].push_back(src);
            }

            // DFS
            dfs(0,nodes,-1,dfn,low,res);
            return res;
        }

/*
def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        graph=collections.defaultdict(list)
        # 建图
        for u,v in connections:
            graph[u].append(v)
            graph[v].append(u)
        
        res=[]
        # 记录每个节点当前时间戳和最早时间戳
        dfn=[-1]*n
        low=[-1]*n
        # tarjan算法
        def tarjan(node,parent,depth):
            dfn[node]=depth
            low[node]=depth
            for nex in graph[node]:
                # 下个节点为父节点，跳过
                if nex==parent:continue
                if dfn[nex]==-1:
                    tarjan(nex,node,depth+1)
                    # 如果当前节点仍然比子节点小，说明找到桥
                    if dfn[node]<low[nex]:
                        res.append([node,nex])
                # 更新当前节点的最小时间戳
                low[node]=min(low[node],low[nex])
        tarjan(0,-1,0)
        return res

作者：yim-6
链接：https://leetcode-cn.com/problems/critical-connections-in-a-network/solution/python3-tarjansuan-fa-by-yim-6-p5ok/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
        
    };
}