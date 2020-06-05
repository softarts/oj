/**
 * Created by rui.zhou on 05 Jun, 2020
 */
package com.zhourui.other;

import com.zhourui.codech.BaseSolution;

import java.util.Arrays;
import java.util.HashSet;



public class Epam2020 extends BaseSolution {
    class Solution {
        public int solution(int[] A) {
            // some edge cases to be considered:
            // cycle list
            // invalid next element.
            HashSet<Integer> visited = new HashSet(Arrays.asList(0));
            int len = 1;
            int nextIdx = A[0];
            while (!visited.contains(nextIdx) && nextIdx!=-1 && (nextIdx <A.length && nextIdx>=0)) {
                visited.add(nextIdx);
                nextIdx = A[nextIdx];
                len++;
            }
            return len;
        }
    }

}
