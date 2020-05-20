//
// Created by rui.zhou on 5/20/2020.
//

// {5,5,2,5,8}
// 删除第一个或第二个元素后， 剩余的odd或者even 和仍然相等，这个数叫做平衡数，5
// {2 1 6 4}， 把1删除后，也得到一个平衡点，所以1是平衡数
// 思路

#include <codech/codech_def.h>

using namespace std;

namespace {
    int countBalancingElements(vector<int> arr) {
        int oddSum = 0,evenSum=0;
        int ans = 0;
        int prevOddSum = 0,prevEvenSum = 0;

        for(int i=0;i<arr.size();i++){
            if(i%2==0) {
                evenSum += arr[i];
            } else {
                oddSum += arr[i];
            }
        }

        for(int i=0;i < arr.size();i++){
            int currentEvenSum = evenSum - prevEvenSum;
            int currentOddSum = oddSum - prevOddSum;

            if (i%2==0) {
                currentEvenSum -= arr[i];
            } else {
                currentOddSum -= arr[i];
            }
            // remove the current one.
            if (prevOddSum + currentEvenSum == prevEvenSum + currentOddSum) {
                ans++;
            }

            if(i%2==0) {
                prevEvenSum += arr[i];
            } else {
                prevOddSum +=arr[i];
            }
        }
        return ans;
    }





}