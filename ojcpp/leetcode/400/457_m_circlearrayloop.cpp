#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

// 1. must have a circle, 2. loop again to check certial 

namespace {
    class Solution {
    public:
        // can start from any position， 任意一个位置走, 因此有缺陷
        bool circularArrayLoop0(vector<int>& nums) {
            int slow = 0;
            int fast = (0+nums[0])>0?(0+nums[0])%nums.size():(nums.size()-(0+nums[0])%nums.size());
            cout<<"slow:"<<slow<<endl;
            cout<<"fast:"<<fast<<endl;
            while (true) {
                if (slow==fast) break;
                slow = (slow+nums[slow])>0?(slow+nums[slow])%nums.size():(nums.size()-(slow+nums[slow])%nums.size());
                fast =(fast+nums[fast])>0?(fast+nums[fast])%nums.size():(nums.size()-(fast+nums[fast])%nums.size());
                fast = (fast+nums[fast])>0?(fast+nums[fast])%nums.size():(nums.size()-(fast+nums[fast])%nums.size());
                cout<<"slow:"<<slow<<endl;
                cout<<"fast:"<<fast<<endl;
            }
            cout << "pos="<<slow<<endl;
            int pos = slow;
            int start=slow;
            
            bool neg1 = nums[slow]>0?false:true;
            while (true) {
                int nextPos  = (pos+nums[pos])>0?(pos+nums[pos])%nums.size():(nums.size()-(pos+nums[pos])%nums.size());
                bool neg2 = nums[nextPos]>0?false:true;
                if (neg1!=neg2) return false;
                if (nextPos==pos) return false;
                if (nextPos==start) return true;
                pos = nextPos;
            }
            return true;
        }

        bool circularArrayLoop(vector<int>& nums) {
            for (int i=0;i<nums.size();i++) {
                int slow = i;
                int fast = next(slow, nums);
                //while (nums[fast]*nums[i] >0 && nums[next(fast,nums)]*nums[i]>0) {
                while(1) {
                    //if (nums[fast]*nums[i] <0 || nums[slow]*nums[i]<0) break;
                    //if (nums[slow]*nums[i] <0 ) break;
                    if (nums[fast]*nums[i] <0 || nums[next(fast,nums)]*nums[i]<0) break;
                    if (fast==slow) {
                         if (slow ==next(slow,nums))
                            break;
                         return true;
                    }
                    slow = next(slow, nums);
                    fast = next(next(fast, nums), nums);
                }
            }
            return false;
        }

        
        int next(int idx, vector<int>& nums) {
            return ((idx+nums[idx])%nums.size()+nums.size())%(nums.size());
            //return (idx+nums[idx]+nums.size()) % nums.size();
        }


        // good
        bool circularArrayLoop1(vector<int>& nums) {
            int n = nums.size();
            for (int i = 0; i < n; ++i) {
                if (nums[i] == 0) {
                    continue;
                }
                int slow = i, fast = i;
                while (1) {
                    slow = nextIndex(slow, n, nums[slow]);
                    fast = nextIndex(fast, n, nums[fast]);
                    fast = nextIndex(fast, n, nums[fast]);
                    if (slow == fast) {
                        break;
                    }
                }
                if (!nums[slow]) {
                    break;
                }
                // find start point of cycle
                slow = i;
                while (slow != fast) {
                    int jump = nums[slow];
                    nums[slow] = 0;
                    slow = nextIndex(slow, n, jump);
                    fast = nextIndex(fast, n, nums[fast]);
                }
                int begin = fast, step = 0, valid = 1, dir = -1;
                // check if cyles step > 1 and correct direction
                while (dir == -1 || fast != begin) {
                    if (dir != -1 && dir > 0 != nums[fast] > 0) {
                        valid = 0;
                    }
                    dir = nums[fast] > 0;
                    int jump = nums[fast];
                    nums[fast] = 0;
                    fast = nextIndex(fast, n, jump);
                    ++step;
                }
                if (step > 1 && valid) {
                    return true;
                }
            }
            return false;
        }
        int nextIndex(int idx, int n, int jump) {
            return (((idx+jump)%n)+n)%n;
        }
    };
}

DEFINE_CODE_TEST(457_circlearray)
{
    Solution obj;
    {
        vector<int> nums1{-2,1,-1,-2,-2};
        Solution obj;
        VERIFY_CASE(obj.circularArrayLoop(nums1), false);
    }

    {
        vector<int> nums1{2,-1,1,2,2};
        Solution obj;
        VERIFY_CASE(obj.circularArrayLoop(nums1), true);
    }
    {
        vector<int> nums1{-1,2};
        Solution obj;
        VERIFY_CASE(obj.circularArrayLoop(nums1), false);
    }
    
    {
        vector<int> nums1{3,1,2};
        Solution obj;
        VERIFY_CASE(obj.circularArrayLoop(nums1), true);
    }

    
}