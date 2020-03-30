package com.zhourui.leetcode

//class Solution {
//  public:
//    string intToRoman(int num) {
//      vector<int> t1{1000,900,500,400,100,90,50,40,10,9,5,4,1};
//      vector<string> t2{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
//      string ret="";
//      for (int i=0;i<t1.size();i++) {
//      if (num>=t1[i]) {
//      int c = num/t1[i];
//      for (int j=0;j<c;j++) {
//      ret+=t2[i];
//    }
//      num=num%t1[i];
//    } else if (num==0) {
//      break;
//    }
//    }
//      return ret;
//    }
//};


//object Solution {
//  case class RomanNumber(decValue: Int, romanStr: String)
//  val numbers = Seq(
//    RomanNumber(1000, "M"),
//    RomanNumber(900, "CM"),
//    RomanNumber(500, "D"),
//    RomanNumber(400, "CD"),
//    RomanNumber(100, "C"),
//    RomanNumber(90, "XC"),
//    RomanNumber(50, "L"),
//    RomanNumber(40, "XL"),
//    RomanNumber(10, "X"),
//    RomanNumber(9, "IX"),
//    RomanNumber(5, "V"),
//    RomanNumber(4, "IV"),
//    RomanNumber(1, "I")
//  )
//  def intToRoman(num: Int): String = {
//    def loop(num:Int, romans: Seq[RomanNumber]): String = {
//      romans match {
//        case RomanNumber(x, romanStr) :: _ if x < num => romanStr + loop(num-x, romans)
//        case RomanNumber(x, romanStr) :: _ if x == num => romanStr
//        case RomanNumber(x, _) :: tail if x > num => loop(num, tail)
//      }
//    }
//    loop(num, numbers)
//  }
//}
package lc0012_integertoroman {
  object Solution {
    case class RomanNumber(s:String, i: Int)
    def intToRoman(num: Int): String = {
      val numbers:Seq[RomanNumber] = Seq(
        RomanNumber("M",1000),
        RomanNumber("CM",900),
        RomanNumber("D",500),
        RomanNumber("CD",400),
        RomanNumber("C",100),
        RomanNumber("XC",90),
        RomanNumber("L",50),
        RomanNumber("XL",40),
        RomanNumber("X",10),
        RomanNumber("IX",9),
        RomanNumber("V",5),
        RomanNumber("IV",4),
        RomanNumber("I",1)
      )
      // 很巧妙 利用seq的head 和tail 递归调用
      // :: 相当于拼接

      def loop(num:Int, romans:Seq[RomanNumber]): String = {
        romans match {
          case RomanNumber(romanStr, v) :: lst if v == num => romanStr
          case RomanNumber(romanStr, v) :: lst if v < num => romanStr+loop(num-v,romans)
          case RomanNumber(romanStr, v) :: tail => loop(num,tail)
        }
      }
      loop(num, numbers)
    }
  }
}
