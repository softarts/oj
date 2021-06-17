package leetcode

/*
这题感觉有点扯,就是个loop？
*/

func longestCommonPrefix(strs []string) string {
    minLen := 200
	if len(strs) == 0 {return ""}
	for _, s := range(strs) {
		if len(s) < minLen {
			minLen = len(s)
		}
	}

	for i:=0;i<=minLen;i++ {
		ch := strs[0][i]
		count := 0
		for _, s := range(strs) {
			if s[i]==ch {
				count++
			}
		}
		if count!=len(strs) {
			return strs[0][:i]
		}
	}
	return strs[0][:minLen]
}