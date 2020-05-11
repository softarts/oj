package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import java.util.HashMap;
import java.util.Map;

// 使用finite state machine
// 使用正则表达式
//Some examples:
//        "0" => true
//        " 0.1 " => true
//        "abc" => false
//        "1 a" => false
//        "2e10" => true
//        " -90e3   " => true
//        " 1e" => false
//        "e3" => false
//        " 6e-1" => true
//        " 99e2.5 " => false
//        "53.5e93" => true
//        " --6 " => false
//        "-+3" => false
//        "95a54e53" => false

//(\d+\.?|\.\d+)这个能匹配0.5,分为0. 一个group, .5也可以，结果能把0.5都吃掉!!!
// 更合理的应该是这个 ([0-9]+\.?|[0-9]*\.[0-9]+) 第二个匹配带数字开头
//e3 如何忽略掉前面的group
//https://segmentfault.com/a/1190000010018231
public class Lc0067_validnumber extends BaseSolution {
    class Solution {
        public boolean isNumber(String s) {
            if(s.trim().isEmpty()){
                return false;
            }
            String regex = "[-+]?(\\d+\\.?|\\.\\d+)\\d*(e[-+]?\\d+)?";
            //String regex = "[-+]?(\\d+\\.?\\d+)\\d*(e[-+]?\\d+)?";
            if(s.trim().matches(regex)){
                return true;
            }else{
                return false;
            }
        }
    }

    @Override
    public boolean test() {
        HashMap<String,Boolean> input = new HashMap(){
            {
                put("0.5",true);
                put("0",true);
                put(" 0.1 ",true);
                put("abc",false);
                put("1 a",false);
                put("2e10",true);
                put(" -90e3   ",true);
                put(" 1e",false);
                put("e3",false);
                put(" 6e-1",true);
                put(" 99e2.5 ",false);
                put("53.5e93",true);
                put(" --6 ",false);
                put("-+3",false);
                put("95a54e53",false);
            }
        };
        var slu = new Solution();
        for (Map.Entry<String,Boolean> pr:input.entrySet()) {
            var ret=slu.isNumber(pr.getKey());
            if (ret!=pr.getValue()) {
                System.out.println(String.format("%20s - %s - act: %s",pr.getKey(),pr.getValue(),ret));
            }

        }
        return true;
    }
}
//  另一个实现，管理e,dot, number,number after E
//    public boolean isNumber3(String s){
//        s = s.trim();
//        boolean pointSeen = false;
//        boolean eSeen = false;
//        boolean numberSeen = false;
//        boolean numberAfterE = true;
//        for(int i=0; i<s.length(); i++) {
//            //当前值为数字
//            if('0' <= s.charAt(i) && s.charAt(i) <= '9') {
//                numberSeen = true;
//                numberAfterE = true;
//                //遇到小数点
//            } else if(s.charAt(i) == '.') {
//                //已经遇到小数点或是e，则出错
//                if(eSeen || pointSeen) {
//                    return false;
//                }
//                pointSeen = true;
//                //遇到e
//            } else if(s.charAt(i) == 'e') {
//                //已经遇到e或是尚未遇到数字
//                if(eSeen || !numberSeen) {
//                    return false;
//                }
//                numberAfterE = false;
//                eSeen = true;
//                //遇到正负号，只能在首位或是e后面
//            } else if(s.charAt(i) == '-' || s.charAt(i) == '+') {
//                if(i != 0 && s.charAt(i-1) != 'e') {
//                    return false;
//                }
//                //遇到其它符号一定是错的
//            } else {
//                return false;
//            }
//        }
//        //是否遇到小数点或是e均不重要
//        return numberSeen && numberAfterE;
//    }
