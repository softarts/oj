/**
 * Created by rui.zhou on 29 May, 2020
 */
package com.zhourui.other;

import com.zhourui.codech.BaseSolution;

public class Lazada2020 extends BaseSolution {
    class Solution {
        public int nextNum(int num, int small, int big) {
            int right = 0,factor=1;
            while (num>0) {
                int m = num%10;
                if (m==big) {
                    right = 1*factor+right;
                } else if (m==small) {
                    return ((num/10)*10+big)*factor+right;
                }
                factor*=10;
                num=num/10;
            }

            return 1*factor+right;
        }
    }

    @Override
    public boolean test() {
        // 1-> 5 -> 11 -> 15 ->51 -> 55 ->111 ->115->...555->1111
        // assume the input are valid number
        boolean ret = true;
        Solution slu = new Solution();
        ret &=  (slu.nextNum(1,1,5) == 5);
        ret &=  (slu.nextNum(5,1,5) == 11);
        ret &=  (slu.nextNum(15,1,5) == 51);
        ret &=  (slu.nextNum(111,1,5) == 115);
        ret &=  (slu.nextNum(555,1,5) == 1111);
        return ret;
    }
}
