//
// Created by rui zhou on 2020-06-20.
//

#include <codech/codech_def.h>

using namespace std;
// 用数组表示一串矩形，找出可以组成最大的矩形
// 参考42 trapwater
// 应该是一个dp的解法
// dp[i]= 0..i的最大面积，这个难，后一个面积并不仅依赖于前一个最大面积
// 单纯拿到一个left/right min没有用处，需要一个尽可能大的数字，可能要一个双重循环.
// 状态转移方程

namespace {
    // O(N^2)的解法
    //前提，最大的矩形必定是某一个元素的最大高度
    // 一个双重循环，对于每个idx,向左和向右直到遇到更矮的
    class Solution0 {
    public:
        int largestRectangleArea(vector<int>& heights) {
            int maxArea = 0;
            for (int i=0;i<heights.size();i++) {
                int mid = i;
                int area = 0;
                // left part
                for(;mid >= 0 && heights[mid] >= heights[i]; area += heights[i], --mid);
                // right
                for(mid = i+1 ;mid < heights.size() && heights[mid] >= heights[i]; area += heights[i], ++mid);
                maxArea = max(area,maxArea);
            }
            return maxArea;

        }
    };

    // O(n) 的解法,参考以上
    // 如果是递增的波峰型，面积等于每个的高度*宽度(当前IDX-所在的IDX)
    // 如果新元素比stack中的元素高度高，压栈；如果新的元素小，就把栈里所有高于这个元素的弹出来，计算矩形面积，
    // 这个精髓在于用一个o(n)操作来完成此类波浪上升的矩形面积计算操作
    class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            int maxArea = 0;
            stack<int> st;
            heights.push_back(0); //加入一个终结的元素
            for (int i=0;i<heights.size();i++) {
                // 当前元素和栈顶比较，如果比栈顶元素大，则压栈
                if (st.empty() || heights[st.top()]<heights[i]) {
                    st.push(i);
                } else {
                    //如果比栈顶元素小，则弹出栈顶，设为tmp
                    int tmp = st.top();
                    st.pop();
                    //然后计算当前I到下一个栈顶的宽度，即tmp能达到的宽度
                    //注意必须和下一个栈顶有关，这样才知道本tmp的跨度
                    maxArea = max(maxArea, heights[tmp]*(st.empty()?i:(i-st.top()-1)));
                    i--;  // 这样导致i原地不动，仍然继续比较i
                }
            }
            return maxArea;


        }

        // 参考代码
        int test(vector<int>& h) {
            stack<int> S;
            h.push_back(0);
            int sum = 0;
            for (int i = 0; i < h.size(); i++) {
                if (S.empty() || h[i] > h[S.top()]) {
                    S.push(i);
                }
                else {
                    int tmp = S.top();
                    S.pop();
                    sum = max(sum, h[tmp]*(S.empty()? i : i-S.top()-1));
                    i--;
                }
            }
            return sum;
        }
    };


}


DEFINE_CODE_TEST(0084_largestrectangle)
{
    Solution obj;
    {
        vector<int> h{1,5,6,7,2,3};
        VERIFY_CASE(obj.largestRectangleArea(h),10);
    }

//    {
//        vector<int> h{2,1,5,6,2,3};
//        VERIFY_CASE(obj.(h),10);
//    }
}

