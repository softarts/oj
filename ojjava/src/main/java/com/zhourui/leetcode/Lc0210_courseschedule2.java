package com.zhourui.leetcode;

import java.util.*;

public class Lc0210_courseschedule2 {
    class Solution {
        public int[] findOrder(int numCourses, int[][] prerequisites) {
            HashMap<Integer,Integer> deps = new HashMap();
            HashMap<Integer,ArrayList<Integer>> requires = new HashMap();
            for (int i=0;i<numCourses;i++) {
                deps.put(i,0);
                requires.put(i, new ArrayList());
            }

            for (int[] pair : prerequisites) {
                int course = pair[0];
                deps.put(course, deps.get(course)+1);  //
                requires.get(pair[1]).add(course);
            }

            Queue<Integer> ready = new ArrayDeque();
            for (int i=0;i<numCourses;i++) {
                if (deps.get(i)==0) {
                    ready.offer(i);
                }
            }

            //ArrayList<Integer> topo = new ArrayList();
            int[] topo = new int[numCourses];
            int idx=0;
            while (!ready.isEmpty()) {
                var course = ready.remove();
                topo[idx++]=course;
                for (var v:requires.get(course)) {
                    deps.put(v, deps.get(v)-1);
                    if (deps.get(v)==0) {
                        ready.offer(v);
                    }
                }
            }
            int[] empty ={};
            return idx==numCourses?topo:empty;

        }
    }
}


/*
import scala.collection.mutable.ArrayBuffer
object Solution {
    def findOrder(numCourses: Int, prerequisites: Array[Array[Int]]): Array[Int] = {
      val inDegree = new Array[Int](numCourses)
      val neighbour = new Array[ArrayBuffer[Int]](numCourses).map(_=>new ArrayBuffer[Int]()) //必须初始化

      prerequisites.foreach(p=> {
        inDegree(p(0)) += 1
        neighbour(p(1)) += p(0)
      })

      val ans = ArrayBuffer[Int]()
      var zeroInDegree = inDegree.zipWithIndex.filter(_._1 == 0).map(_._2).toList
      var canFinshNum = zeroInDegree.length
      while (zeroInDegree.nonEmpty) {
        val cur = zeroInDegree.head
        ans += cur
        zeroInDegree = zeroInDegree.tail
        neighbour(cur).foreach(p=>{
          inDegree(p)-=1
          if (inDegree(p) == 0) {
            zeroInDegree :+= p
            canFinshNum+=1
          }
        })
      }
      canFinshNum match {
        case canFinshNum if canFinshNum == numCourses => ans.toArray
        case _ => Array()
      }
    }
}
 */