//
// Created by rui zhou on 2019-12-20.
//

//模版特化
#include <codech/codech_def.h>

using namespace std;

namespace {
    template<typename T>
    class Types {
    public:
        typedef int I;
    };

    // 特化
    template<typename T,typename U=typename Types<T>::I>
    class S;

    //特化
    template<typename T,int N>
    class K;

    //特化
    template<>
    class S<void> {
    public:
        void f();
    };

    template<>
    class S<char,char> {};

    template<>
    class K<char,0>;

    void test_explic_spec() {
        S<int> *a;
        S<char,char> b;
    }

}


DEFINE_CODE_TEST(212_tempspec)
{
    test_explic_spec();
}