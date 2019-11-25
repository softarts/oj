//
// Created by rui zhou on 2019-11-24.
//

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace {

    char findFirst(const string input)
    {
        // TODO: implement the solution here
        unordered_map<char,int> m;
        //m['c']=1;
        for (auto &it:input) {
            m[it]+=1;
        }

        for (auto &it:input) {
            if (m.count(it)==1) {
                return it;
            }
        }
        return 0;
    }

/**
 * bool doTestsPass()
 * Returns true if all tests pass. Otherwise returns false.
 */
    bool doTestsPass()
    {
        // todo: implement more tests, please
        // feel free to make testing more elegant
        bool result = true;
        result &= findFirst("apple") == 'a';
        result &= findFirst("racecars") == 'e';
        result &= findFirst("ababdc") == 'd';
        //additional test
        result &= findFirst("") == 0;
        result &= findFirst("aaa") == 0;


        return result;
    }

/**
* Execution entry point.
*/
//    int main()
//    {
//        if(doTestsPass())
//        {
//            cout << "All tests pass" << endl;
//        }
//        else
//        {
//            cout << "There are test failures" << endl;
//        }
//
//        return 0;
//    }

}


DEFINE_CODE_TEST(HHT_025_bstsum)
{

    cout <<  findFirst("aaa") == 0;

}