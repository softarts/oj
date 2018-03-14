'''
This is a demo task.

Write a function:

def solution(A)

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Assume that:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].
Complexity:

expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
'''



def solution(A):
    # write your code in Python 3.6
    lst = sorted(A)
    result = 1
    for i in lst:
        if i < 0:
            continue
        elif i>result:
            continue
        elif i==result:
            result+=1
    return result



if __name__ == '__main__':
    print(solution([1,3,6,4,1,2])==5)
    print(solution([1,2,3])==4)
    print(solution([-1,-3]) == 1)

