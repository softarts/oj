//
// Created by rui.zhou on 5/20/2020.
//

//ticket 1-10,code will be {1,2,3,4,5,6,7,8,9,1}
// 10->1+0=1
// 2-9都对应1个winner, 1,10 ->1 意味着可以有2个winner,但是只有1个办法(即ticket 1& 10)
// {1,2,3,4,5}则有 5个办法，得到1个winner,返回{5,1}
#include <codech/codech_def.h>

using namespace std;
using namespace CODECH;
namespace {
    vector<long> waysToChooseSum0(long lowLimit, long highLimit) {
        unordered_map<int,int> m;
        auto digitsum = [](long num) {
            long sum = 0;
            while (num>0) {
                sum+=num%10;
                num=num/10;
            }
            return sum;
        };
        int maxCount = INT_MIN;
        for (int i=lowLimit;i<=highLimit;i++) {
            auto sum=digitsum(i);
            //cout << i<<","<< sum <<endl;
            m[sum]+=1;
            maxCount = max(maxCount,m[sum]);
        }

        unordered_set<int> ans;
        for (auto &iter: m) {
            //cout << iter.first << "," << iter.second<<endl;
            if (iter.second == maxCount) {
                ans.insert(iter.first);
            }
        }
        return vector<long>{(long)ans.size(),maxCount};
    }

    vector<long> waysToChooseSum(long lowLimit, long highLimit) {
        unordered_map<int,int> m;
        auto digitsum = [](long num) {
            long sum = 0;
            while (num>0) {
                sum+=num%10;
                num=num/10;
            }
            return sum;
        };
        int maxCount = INT_MIN;
        auto prev = digitsum(lowLimit);
        for (int i=lowLimit;i<=highLimit;i++) {
            if (i%10 ==0) {
                prev = prev-8;
                m[prev]+=1;
            } else {
                prev = prev+1;
                m[prev]+=1;
            }
            maxCount = max(maxCount,m[prev]);
        }

//        for (int i=lowLimit;i<=highLimit;i++) {
//            m[digitsum(i)]+=1;
//            maxCount = max(maxCount,m[digitsum(i)]);
//        }

        unordered_set<int> ans;
        for (auto &iter: m) {
            if (iter.second == maxCount) {
                ans.insert(iter.first);
            }
        }
        return vector<long>{(long)ans.size(),maxCount};
    }

    // ---------------------------------------------------------------
//    long long int solve(int pos,int sum,int f){
//        if(pos==num.size())
//            return sum;
//        if (DP[pos][sum][f]!=-1) return DP[pos][sum][f];
//        long long int res=0;
//        int lmt;
//        if(f==0){
//            lmt=num[pos];
//        }
//        else lmt=9;
//        for(int dgt=0;dgt<=lmt;dgt++){
//            int nf=f;
//            if(f==0 && dgt<lmt) nf=1;
//            res+=solve(pos+1,sum+dgt,nf);
//        }
//
//        return DP[pos][sum][f]=res;
//
//    }
//
    long long dp[20][180][2];

    long long helper(int idx, int sum, int tight, vector<int> &digit) {
        if (idx==0) {
            // calculating range value
            int k = (tight)? digit[idx] : 9;
            for (int i = 0; i <= k ; i++)
            {
                // caclulating newTight value for next state
                int newTight = (digit[idx] == i)? tight : 0;
                // fetching answer from next state
                ret += helper(idx-1, sum+i, newTight, digit);
            }
        }


        if (dp[idx][sum][tight] != -1 and tight != 1)
            return dp[idx][sum][tight];

        long long ret = 0;

        // calculating range value
        int k = (tight)? digit[idx] : 9;
        for (int i = 0; i <= k ; i++)
        {
            // caclulating newTight value for next state
            int newTight = (digit[idx] == i)? tight : 0;



                    // fetching answer from next state
            ret += helper(idx-1, sum+i, newTight, digit);
        }

        if (!tight)
            dp[idx][sum][tight] = ret;
        return ret;
    }



    long long digitSum(int idx, int sum, int tight,
                       vector <int> &digit)
    {
        // base case
        if (idx == -1)
            return sum;

        // checking if already calculated this state
        if (dp[idx][sum][tight] != -1 and tight != 1)
            return dp[idx][sum][tight];

        long long ret = 0;

        // calculating range value
        int k = (tight)? digit[idx] : 9;

        for (int i = 0; i <= k ; i++)
        {
            // caclulating newTight value for next state
            int newTight = (digit[idx] == i)? tight : 0;

            // fetching answer from next state
            ret += digitSum(idx-1, sum+i, newTight, digit);
        }

        if (!tight)
            dp[idx][sum][tight] = ret;

        return ret;
    }

    // Stores the digits in x in a vector digit
    long long getDigits(long long x, vector <int> &digit)
    {
        while (x)
        {
            digit.push_back(x%10);
            x /= 10;
        }
    }
    int rangeDigitSum(int a, int b)
    {
        // initializing dp with -1
        memset(dp, -1, sizeof(dp));

        // storing digits of a-1 in digit vector
        vector<int> digitA;
        getDigits(a-1, digitA);

        // Finding sum of digits from 1 to "a-1" which is passed
        // as digitA.
        long long ans1 = digitSum(digitA.size()-1, 0, 1, digitA);

        // Storing digits of b in digit vector
        vector<int> digitB;
        getDigits(b, digitB);

        // Finding sum of digits from 1 to "b" which is passed
        // as digitB.
        long long ans2 = digitSum(digitB.size()-1, 0, 1, digitB);

        return (ans2 - ans1);
    }


}

DEFINE_CODE_TEST(blockone_digitsum)
{
    long long a = 564645538, b = 885248788;
    cout << "digit sum for given range : "
         << rangeDigitSum(a, b) << endl;

//    {
//        auto vec = waysToChooseSum(1,5);
//        VERIFY_CASE(vec[0],5);
//        VERIFY_CASE(vec[1],1);
//
//    }
//    {
//        auto vec = waysToChooseSum0(564645538,885248788);
//        VERIFY_CASE(vec[0],1);
//        VERIFY_CASE(vec[1],15604491);
//    }
//    {
//        auto vec = waysToChooseSum0(1,200);
//        VERIFY_CASE(vec[0],1);
//        VERIFY_CASE(vec[1],504);
//    }

//    {
//        auto vec = waysToChooseSum0(48444,55924);
//        VERIFY_CASE(vec[0],1);
//        VERIFY_CASE(vec[1],504);
//    }





}