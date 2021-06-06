//
// Created by rui.zhou on 2019/9/2.
//
/*
 * Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.
 */


#include <codech/codech_def.h>
using namespace CODECH;
using namespace std;

namespace {
    class Solution {
    public:
        vector<string> topKFrequent(vector<string>& words, int k) {
            // default is max heap(less<>), we want a min heap
            auto comp = [](pair<string,int> &a, pair<string,int>&b){
                if (a.second!=b.second)
                    return a.second > b.second;
                else {
                    return (bool)(a.first.compare(b.first)<=0);
                }
            };

            priority_queue<pair<string, int>, vector<pair<string,int>>,
                    decltype(comp)> pq(comp);

            unordered_map<string,int> map;
            vector<string> ret;
            for (auto &&it:words) {
                map[it]+=1;
            }

            for (auto &&it : map) {
                pq.push(make_pair(it.first,it.second));
                if (pq.size() > k) {
                    pq.pop();
                }
            }

            while (!pq.empty()) {
                ret.insert(ret.begin(),pq.top().first);pq.pop();
            }
            return ret;
        }
    };
}

DEFINE_CODE_TEST(692_topfrequentwords)
{
    Solution obj;
    {
        vector<string> words = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
        vector<string> exp = {"the", "is", "sunny", "day"};
        VERIFY_CASE(obj.topKFrequent(words,4) == exp,true);
        cout << PRINT_STRVEC(obj.topKFrequent(words,4)) << endl;
    }
    {
        vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
        vector<string> exp = {"i", "love"};
        VERIFY_CASE(obj.topKFrequent(words,2) == exp,true);
        cout << PRINT_STRVEC(obj.topKFrequent(words,2)) << endl;
    }

}
