package leetcode

/*
Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
这题的思路?如何构造一个window？
11:48PM， 难
问题转化为给定区间，占少数的字符的计算<=k，找出此区间的最大长度
使用sliding window(two pointer)


如果认为maxcount是重复字符个数，当然就需要更新maxcount。但是maxcount的逻辑含义是窗口最大值，也就是当前的最优解。
只有当后面的窗口大于maxcount时，才有可能更新最优解，因此不需要收缩maxcount。如果收缩maxcount也可以得到结果，只是效率比较低。



class Solution {
public:
    int characterReplacement(string s, int k)
    {
        unordered_map<char, int> countmap;
        int left = 0;
        int result = 0;
        int maxcount = 0;

        for (int i = 0; i < s.size(); i++) {
            countmap[s[i]]++;
            maxcount = max(maxcount,countmap[s[i]]);

            while (i - left+1 > maxcount + k) {
                countmap[s[left]]--;
                left++;
            }

            result = max(result, i - left + 1);
        }

        return result;
    }
};

对maxcount的分析，
maxcount是在条件下所能得到的最大重复字符个数(未包括k)，为最优解，这里并不需要更新maxcount为当前窗口下的最大字符个数，
而是历史上所有最大字符个数，除非当前位置得到另一个更大的maxcount
maxcount总是和所能得到的结果有关，当得到k变换后最大重复字符个数，此时总是有maxcount,因此只要看历史最大maxcount

调整窗口的条件，这里和maxcount有关有些难理解，因为此时的窗口和maxcount可能没有关系的，
此时窗口内的maxcount只可能小，不可能大，所以取历史最高maxcount没有问题，
当一个新的字符和当前最多重复次数的字符不一样，调整窗口后字符可能会变化，但这不影响
移动窗口左侧，会影响某字符计数

套路
建立滑动窗口
遍历数组
当不满足条件的时候循环调整滑动窗口, 本题目由于采用最大maxcount，所以只需要调整一次


class Solution {
public:
    int characterReplacement(string s, int k) {

        vector<int> table(26,0);
        int start=0,end=0,alpha_count=0,final_count=0;

        for(int end=0; end<s.size();end++)
        {
            table[s[end]-'A']++;
            if(table[s[end]-'A']>alpha_count)
                alpha_count=table[s[end]-'A'];

            if((end-start-alpha_count+1)>k)
            {
                table[s[start]-'A']--;
                start++;
            }
            final_count=max(final_count,(end-start+1));
        }
        return final_count;
    }
};

func characterReplacement(s string, k int) int {
    count := make([]int, 128)
    for i:=0; i < len(count); i++ {
        count[i] = 0
    }
    max := 0
    start := 0
    for end:=0; end < len(s); end++ {
        count[s[end]] += 1
        if max < count[s[end]] {
            max = count[s[end]]
        }
        if max + k <= end - start {
            count[s[start]] -= 1
            start += 1
        }
    }
    return len(s) - start
}
*/

func max(a, b int) int {
	if a < b {
		return b
	} else {
		return a
	}
}

func getMaxCount(m map[byte]int) int {
	maxCount := 0
	for _, v := range m {
		maxCount = max(maxCount, v)
	}
	return maxCount
}

func characterReplacement(s string, k int) int {
	m := make(map[byte]int)

	ans := 0
	maxCount := 0
	left := 0
	for i := 0; i < len(s); i++ {
		m[s[i]] += 1

		maxCount = getMaxCount(m)
		for i-left+1-maxCount > k {
			m[s[left]] -= 1
			left++
		}
		ans = max(i-left+1, ans)
	}
	return ans
}
