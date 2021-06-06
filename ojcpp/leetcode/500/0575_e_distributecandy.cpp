#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace {
    class Solution {
    public:
        int distributeCandies(vector<int>& candyType) {
            unordered_set<int> set;
            for (auto v : candyType) {
                set.emplace(v);
            }
            return min(set.size(), candyType.size()/2);
        }
    };
}
