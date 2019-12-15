//
// Created by rui zhou on 2019-12-15.
//

#include <codech/codech_def.h>
using namespace std;

// 重载函数模版的问题

namespace {
    template<typename T>
    inline T const& max(T const &a,T const &b) {
        cout << "call max 2" << endl;
        return a<b?b:a;
    }

    // warning: returning reference to local temporary object [-Wreturn-stack-address]
    // ?传递的是指针
    inline char const* max(char const*a,char const*b) {
        cout << a << endl;
        cout << "call strcmp" << endl;
        return std::strcmp(a,b) <0?b:a;
    }

    template<typename T>
    inline T const& max(T const &a,T const &b, T const& c) {
        cout << "call max 3" << endl;
        return max(max(a,b),c);
    }

    void test_functemp_overload() {
        //max(7,42,68);
        const char *s1 = "frederic";
        const char *s2 = "anica";
        const char *s3 = "lucas";
        cout << s1 << endl;
        max(s1,s2,s3);
    }
}


DEFINE_CODE_TEST(2_0204_functemp_overload)
{
    test_functemp_overload();
}