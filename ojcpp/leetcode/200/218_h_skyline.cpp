/*
Input: buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
Output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
Explanation:
Figure A shows the buildings of the input.
Figure B shows the skyline formed by those buildings. The red points in figure B represent the key points in the output list.

2021-04-15
画出天际线，x 比前一个高或者低的点
这题关键是解题方法，如何描述思路
对于每一个x，搜索后面所有的x，合并得到最大值,
同时需要查看前面x，是否有被覆盖
*/

#include <codech/codech_def.h>
#include <set>

using namespace std;

namespace {
    class Solution {
    public:
        vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
            // height
            // 首先把每个building 拆成x1,-y, x2,y两个坐标，放入到一个vector中排序，先比较x,再比较y
            // 对于同样高度的建筑物， buildingA右节点(x2,y)  和 buildingB左节点 (x2,-y), building B会排在前面-->这个不重要？


            // 使用heap来维护一个当前的高度的排序,这是关键
            // 左侧起点，加入到heap，最高点会自动维护在heap的最右侧, 遇到右侧结束点，从heap中删除，表示该高度已被删除.
            // 同样的x,右侧结束点永远排在左侧起点前面，
            // 当当前高度被删除后，就会回到前一个次高上面
            // 如果building 与当前heap的最大高度不一样,
            vector<pair<int,int>> height;
            for (auto &b:buildings) {
                height.push_back({b[0],-b[2]});
                height.push_back({b[1],b[2]});
            }
            sort(height.begin(),height.end());

            multiset<int> heap;
            heap.insert(0);     // 初始高度是0
            int pre = 0, cur = 0;        // 前一高度是0
            vector<vector<int>> res;
            for (auto &h : height) {
                if (h.second < 0) { // 这是building的左侧起点
                    heap.insert(-h.second);  //前面放入height的时候是取反，现在需要再反过来
                } else {
                    heap.erase(heap.find(h.second));
                }
                cur = *heap.rbegin();  // 当前的最大高度
                if (cur != pre) {
                    res.push_back({h.first, cur});
                    cur = pre;
                }
            }
            return res;
        }
    };
}

DEFINE_CODE_TEST(218_skyline)
{
    Solution obj;
    {
        vector<vector<int>> building{{2,9,10},{3,7,15},{7,10,15}};
        obj.getSkyline(building);
    }

    {
        vector<vector<int>> building{{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
        obj.getSkyline(building);
    }
    
}