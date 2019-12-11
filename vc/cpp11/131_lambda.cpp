//
// Created by rui zhou on 2019-12-11.
//

#include <codech/codech_def.h>
using namespace std;

namespace {
    void test_value() {
        int id = 1;
        auto f=[id]() mutable {
            id++;  //only with mutable
        };
    }

    int gbl = 5;
    class Widget {
    public:
        int divisor;

        void addFilter() {
            int a = 5;
            auto f = [](int v) { return v % gbl; };
            auto f3 = [divisor=divisor](int v){return v%divisor;};  //可以捕捉成员变量;
        }
    };

    void test_capture(){
        Widget w;
        w.addFilter();
    }
}

DEFINE_CODE_TEST(131_lambda)
{
    //test_value();
    test_capture();
}
