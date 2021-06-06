//
// Created by rui.zhou on 2/24/2019.
//

/*
 * We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)



Example 1:

Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)


Note:

1 <= K <= points.length <= 10000
-10000 < points[i][0] < 10000
-10000 < points[i][1] < 10000
 */

#include <codech/codech_def.h>
#include <cmath>
using namespace CODECH;
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto comp = [](vector<int>&a,vector<int> &b){
            return sqrt(a[0]*a[0]+a[1]*a[1]) < sqrt(b[0]*b[0]+b[1]*b[1]);
        };
        priority_queue<vector<int>, std::vector<vector<int>>, decltype(comp)>pq(comp);
        for (auto &iter:points) {
            pq.push(iter);
            if (pq.size()>K) {
                pq.pop();
            }
        }
        vector<vector<int>> ret{0,vector<int>()};
        while (!pq.empty()) {
            auto &iter = pq.top();
            ret.emplace_back(iter);
            pq.pop();
        }
        return ret;
    }
};

DEFINE_CODE_TEST(937_kclosestpt)
{
    Solution obj;
    {
        vector<vector<int>> nums{{3,3},{5,-1},{-2,4}};
        VERIFY_CASE(PRINT_VVEC(obj.kClosest(nums,2)),"-2 4 3 3");
    }
    {
        vector<vector<int>> nums{{1,3},{-2,2}};
        VERIFY_CASE(PRINT_VVEC(obj.kClosest(nums,1)),"-2 2");
    }

}

