package leetcode

/*这考题见过几次
1 2 3
4 5 6
7 8 9
==>
7 4 1
8 5 2
9 6 3

10:44 PM--->

*/

func rotate(matrix [][]int)  {
	n := len(matrix) - 1
	start:=0
	end:=n
	for start < end {
		for i:=start;i<end;i++ {
			matrix[start][i], matrix[i][end] = matrix[i][end], matrix[start][i]
			matrix[start][i], matrix[end][n-i] = matrix[end][n-i], matrix[start][i]
			matrix[start][i], matrix[n-i][start] = matrix[n-i][start], matrix[start][i]
		}
		start++
		end--
	}
}
