/**
 * Created by rui.zhou on 27 May, 2020
 */
package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import java.util.*;

public class Lc0133_clonegraph extends BaseSolution {

// Definition for a Node.
    class Node {
        public int val;
        public List<Node> neighbors;
        public Node() {}
        public Node(int _val,List<Node> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
    };

    // 注意需要一个hashmap判断该node是否已被复制
    class Solution {
        public Node cloneGraph(Node node) {
            Node ret = null;
            if (node==null) return ret;
            LinkedList<Node> todo = new LinkedList(Arrays.asList(node));
            HashSet<Node> visited = new HashSet<>();
            HashMap<Integer,Node> m = new HashMap();
            while (!todo.isEmpty()) {
                Node n = todo.poll();
                if (visited.contains(n))  continue;
                visited.add(n);


                Node cloneN = m.get(n.val);
                if (cloneN==null) {
                    cloneN = new Node(n.val, new ArrayList<Node>());
                    m.put(n.val, cloneN);
                }

                if (ret==null) ret = cloneN;

                for (Node el:n.neighbors) {
                    Node elcopy =  m.get(el.val);
                    if (elcopy==null) {
                        elcopy = new Node(el.val, new ArrayList<Node>());
                        m.put(el.val, elcopy);
                    }
                    cloneN.neighbors.add(elcopy);
                    todo.offer(el);
                }
            }
            return ret;
        }
    }
}
