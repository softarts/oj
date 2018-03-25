//
// Created by Rui Zhou on 11/3/18.
//

/*
 * https://leetcode.com/problems/count-primes/
 * Description:

Count the number of prime numbers less than a non-negative number, n.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.

 9:00pm -

 2,3,5,7,11,13...

 https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

*/

#include <codech/codech_def.h>


using namespace std;

class Solution {
public:
    // slow
    int countPrimes0(int n) {
        auto isPrime = [](int p) -> bool {
            for (int i = 2; i < int(sqrt(p)) + 1; i++) {
                if (p % i == 0) {
                    return false;
                }
            }
            return true;
        };

        if (n <= 2) return 0;
        int count = 1;

        for (int i=3; i<n; i+=2) {
            if (isPrime(i)) {
                count++;
            }
        }
        return count;
    }

    int countPrimes1(int n) {
        auto isPrime = [](int p) -> bool {
            for (int i = 2; i < int(sqrt(p)) + 1; i++) {
                if (p % i == 0) {
                    return false;
                }
            }
            return true;
        };

        if (n <= 2) return 0;
        int count = 1;
        vector<int> passed(n, 0);

        int upper = sqrt(n);
        for (int i=3; i<n; i+=2) {
            if (!passed[i]) {
                if (isPrime(i)) {
                    count++;
                    if (i>upper) continue;
                    for (int j=i*i; j<n; j+=i) {
                        passed[j] = 1;
                    }
                }
            }

        }
        return count;
    }

    // 75%
    int countPrimes2(int n) {
        if (n <= 2) return 0;
        int count = 1;
        vector<int> passed(n, 0);

        int upper = sqrt(n);
        for (int i=3; i<n; i+=2) {
            if (!passed[i]) {  // 29?
                count++;
                if (i>upper) continue;
                for (int j=i*i; j<n; j+=i) { //must not be primes, i*i,i*(i+1)...
                    passed[j] = 1;
                }
            }

        }
        return count;
    }

    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<int> flag(n,1);    //true
        //int count = 0;
        flag[0]=0;            //0 not prime
        flag[1]=0;            //1 not prime
        int upper = sqrt(n);
        for(int i=2;i<n;++i)
        {          
            if(flag[i])
            {
                //count++;
                if (i>upper) continue;
                for(int j=2*i;j<n;j+=i)
                {
                    flag[j]=0;
                }
            }
            if (i*i>=n)
                break;
        }
        int count = count_if(flag.begin(), flag.end(),[](int r){return r==1;});
        return count;
    }
};

DEFINE_CODE_TEST(204_countprimes)
{
    Solution obj;
    VERIFY_CASE(obj.countPrimes(3),1);
    VERIFY_CASE(obj.countPrimes(1500000),114155);
    VERIFY_CASE(obj.countPrimes(499979),41537);
}
