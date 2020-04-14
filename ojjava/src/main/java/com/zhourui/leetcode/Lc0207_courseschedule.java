package com.zhourui.leetcode;

//numCourses = 2, prerequisites = [[1,0]]

import com.zhourui.codech.BaseSolution;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;

//[1,0],[2,0] 如果避免判断0 visited了2次？
//如果某个vertex能够全部访问，那就无所谓被visited,所以推出的时候将visited【vertex】去掉
public class Lc0207_courseschedule extends BaseSolution {
    class Solution {
        public boolean canFinish(int numCourses, int[][] prerequisites) {
            var graph  = new HashMap<Integer,List<Integer>>();
            var visited = new HashSet<Integer>();

            for (int[] pair : prerequisites) {
                int course = pair[0];
                if (graph.containsKey(course)) {
                    graph.get(course).add(pair[1]);
                } else {
                    graph.put(course,new ArrayList(List.of(pair[1])));
                }
            }
            for (var v : graph.keySet()) {
                if (!helper(graph, visited, v))
                    return false;
            }
            return true;
        }

        boolean helper(HashMap<Integer,List<Integer>> graph, HashSet<Integer> visited, int curVertex) {
            if (visited.contains(curVertex)) {
                return false;
            }

            visited.add(curVertex);

            if (graph.containsKey(curVertex)) {
                for (var v :graph.get(curVertex)) {
                    if (!helper(graph,visited, v))
                        return false;
                }
            }
            visited.remove(curVertex);
            return true;
        }
    }
    @Override
    public boolean test() {
        boolean ret = true;
        {
            int [][]prerequisites = {{0,1},{1,0}};
            ret &= new Solution().canFinish(2, prerequisites) == false;
        }
        {
            int [][]prerequisites = {{1,0},{2,0}};
            ret &= new Solution().canFinish(2, prerequisites) == true;
        }
        return ret;
    }

    @Override
    public String name() {return "207 course schedule";}
}
