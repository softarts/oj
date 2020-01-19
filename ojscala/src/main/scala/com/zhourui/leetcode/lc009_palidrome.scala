package lc009 {
  object Solution {
    def isPalindrome(x: Int): Boolean = {
      if (x<0) return false
      if (x==0) return true
      if (x%10==0) return false
      val y=x.toString.reverse
      return y==x.toString
    }
  }
}