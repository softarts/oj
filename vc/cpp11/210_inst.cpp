//
// Created by rui zhou on 2019-12-20.
//

#include <codech/codech_def.h>
using namespace std;

namespace {
    template<typename T>
    void f1(T x) {
        //g1(x);  // not found
    }

    void g1(int) {

    }

    void test_inst1() {
        f1(7);
    }
}

DEFINE_CODE_TEST(210_inst)
{
    test_inst1();
}
