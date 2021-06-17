package leetcode

/*
这题不是很难，就是sorted & hash?
==>直接使用key更好
*/
import (
	"sort"
)

func groupAnagrams(strs []string) [][]string {
    //sorted := make(map[[]byte][]int)
	sorted := make(map[string][]int)
	for i, v := range(strs) {
		//还挺麻烦的，需要转成slice
		tmp := []byte(v)
        sort.Slice(tmp, func(a, b int) bool { return tmp[a] < tmp[b] }) //=>sorted bytes
        sorted[string(tmp)] = append(sorted[string(tmp)], i)
	}

	res := [][]string{}
	for _,v := range sorted {
		tmp := []string{}
		for _, index := range v{
			tmp = append(tmp, strs[index])
		}
		res = append(res, tmp)
	}
	return res
}
