package leetcode

import (
	"reflect"
	"testing"
)


func longestPalindrome(s string) string {
	n := len(s)
	if n==0 {
		return ""
	}
    // var dp [1000][1000] bool //bad
	dp := make([][]bool, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]bool, n)
	}
	maxLen:=1
	pos:=0
	for i:=0;i<len(s);i++ {
		dp[i][i]=true
		for j:=0;j<i;j++ {
			dp[j][i] = (i-j==1 && s[j]==s[i]) || (s[j]==s[i] && dp[j+1][i-1])
			if (dp[j][i] && (i-j+1)>maxLen) {
				maxLen = i-j+1
				pos = j
			}
		}
	}
	return s[pos:pos+maxLen]
}

func Test005(t *testing.T) {
	var ret = longestPalindrome("babad")
	var exp = "bab"
	if !reflect.DeepEqual(ret, exp) {
		t.Errorf("Not Passed, got %v", ret)
	}
}


