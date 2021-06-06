/*
 https://leetcode.com/problems/two-sum/
 Given nums = [2, 7, 11, 15], target = 9,

 Because nums[0] + nums[1] = 2 + 7 = 9,
 return [0, 1].

思路
 在one pass中，每个element-target=value,看看value是否已存在于hash map中
 */

#include <codech/codech_def.h>

using namespace CODECH;
using namespace std;

/*
vector<int> twoSum(vector<int>& nums, int target) {
    std::unordered_set<int> sets;
    vector<int> ret;
    std::copy(nums.begin(), nums.end(), inserter(sets,sets.begin()));
    for (int i = 0; i < nums.size(); i++) 
    {
        int key = target - nums[i];
        if (key == nums[i])
            continue;
        auto found = sets.find(key);
        if (found != sets.end())
        {
            ret.push_back(i);
        }
    }
    return ret;
}
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> maps;
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++)
        {
            int key = target - nums[i];
            auto found = maps.find(nums[i]);
            if (found == maps.end())
            {
                maps.insert(std::make_pair(key,i));
            }
            else
            {
                ret.push_back(found->second);
                ret.push_back(i);
                break;
            }
        }
        return ret;
    }
};

/*
vector<int> twoSum(vector<int>& nums, int target) {
    std::unordered_map<int,int> maps;
    vector<int> ret;
    for (int i = 0; i < nums.size(); i++)
    {
        int key = target - nums[i];
        auto found = maps.find(key);
        if (found == maps.end())
        {
            maps.insert(std::make_pair(nums[i],i));
        }
        else
        {
            ret.push_back(found->second);
            ret.push_back(i);
            break;
        }
    }
    return ret;
}



void printResult(const vector<int>& ret)
{
    for_each(ret.begin(), ret.end(),
        [](int elem)
        {
            cout << elem << " ";
        }
    );
    std::cout << std::endl;
}
*/

DEFINE_CODE_TEST(001_twosum)
{
//    vector<int> ret;
//    vector<int> test1 = { 2, 7, 11, 15 };
//    printResult(twoSum(test1, 9));
//    vector<int> test2 = { 3,2,4 };
//    printResult(twoSum(test2, 6));

    vector<int> test1 = { 2, 7, 11, 15 };
    Solution obj;
    VERIFY_CASE(PRINT_VEC(obj.twoSum(test1, 9)),"0 1");


}