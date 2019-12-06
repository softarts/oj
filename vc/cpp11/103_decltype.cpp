//
// Created by rui zhou on 21/05/19.
//

#include <codech/codech_def.h>

using namespace std;

namespace {
    template<typename Container,typename Index>
    auto authAndAccess_bad(Container&c,Index i)  //C++14
    {
        return c[i];
    };

    template<typename Container,typename Index>
    decltype(auto) authAndAccess(Container&c,Index i)  //C++14
    {
        return c[i];
    };

    template<typename Container, typename Index>
    auto
    authAndAccess2(Container&& c, Index i)
    -> decltype(std::forward<Container>(c)[i])
    {
        return std::forward<Container>(c)[i];
    }

    void test_decltype_bad() {
        ///mnt/d/work/oj/vc/cpp11/103_decltype.cpp:32:34: error: lvalue required as left operand of assignment
        //authAndAccess_bad(d,3) = 10; // error: expression is not assignable,must use decltype(auto)
        deque<int> d{1,2,3,4,5};
        //authAndAccess_bad(d,3) = 10;
        // error: expression is not assignable,must use decltype(auto)
    }

    void test_decltype() {
        vector<bool> vec{true,false};
        auto v = authAndAccess(vec,0);
        cout << v << typeid(v).name() << endl;
        deque<int> d{1,2,3,4,5};
        authAndAccess(d,3) = 10; // error: expression is not assignable,must use decltype(auto)
        //
        authAndAccess2(d,3) = 5;
        authAndAccess2(deque<int>{1,2,3,4,5},3) = 5;
    }
    // EMC item 6 ---------------------------

    vector<bool> feature(vector<bool> vec) {
        return vec;
    }
    void process_fea(int priority) {
        cout << priority << endl;
    }
    void test_auto_fail() {
        vector<bool> v{true,true,false,false};
        auto priority = feature(v)[1];
        cout << typeid(priority).name() << endl; // not bool but _bit_referenceINS_6vectorIbNS_9allocatorIbEEEELb1EEE
        process_fea(priority);
    }

}


DEFINE_CODE_TEST(103_decltype)
{
    test_decltype_bad();
    //test_decltype();
    //test_auto_fail();
}