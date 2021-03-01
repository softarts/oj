/*
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
Note:

The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
*/

#include <codech/codech_def.h>
using namespace CODECH;
using namespace std;
namespace {
    class Solution {
    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
            int w = image[0].size();
            int h = image.size();
            int oc = image [sr][sc];
            unordered_set<int> m;
            bfs(m, image, sc, sr, oc, newColor, w, h);
            return image;
        }

        void bfs(unordered_set<int> &m, vector<vector<int>> &image, int x, int y, int oc, int nc, int w, int h) {
            int pos = (x<<16|y);
            if (m.count(pos)) {
                return;
            } else {
                m.emplace(pos);
            }

            if (image[y][x] == oc) {
                image[y][x] = nc;
            } else {
                return;
            }
            int dx[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
            
            for (int i=0;i<4;i++) {
                int nextX = x+dx[i][0];
                int nextY = y+dx[i][1];
                if (nextX>=w || nextX<0 || nextY >= h || nextY <0) {
                    continue;
                } else {
                    bfs(m, image,nextX, nextY, oc, nc, w, h);
                }
            }
        }
    };
}
