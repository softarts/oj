package com.zhourui.leetcode

import scala.collection.mutable._

package lc205_lsomorphic {
  object Solution {
    def isIsomorphic(s: String, t: String): Boolean = {
      val m:HashMap[Char,Char] = HashMap[Char,Char]()
      val n:HashMap[Char,Char] = HashMap[Char,Char]()

      s.indices.foreach(
        idx=>idx match {
          case idx if m.contains(s(idx)) && m(s(idx))!=t(idx) => return false
          case idx if n.contains(t(idx)) && n(t(idx))!=s(idx) => return false
          case idx =>{
            m(s(idx))=t(idx)
            n(t(idx))=s(idx)
          }
        }
      )
      true
    }
  }
}

/*
unordered_map<char,char> m;
unordered_map<char,char> n;

for (int i=0;i<s.length();i++) {
    if (m.count(s[i])) {
        if (m[s[i]]!=t[i]) return false;
    } else if (n.count(t[i])) {
        if (n[t[i]]!=s[i]) return false;
    } else {
        m[s[i]]=t[i];
        n[t[i]]=s[i];
    }
}
return true;

 */