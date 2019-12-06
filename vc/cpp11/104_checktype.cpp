//
// Created by rui.zhou on 2019/12/6.
//
#include <codech/codech_def.h>
using namespace std;
namespace {
    template<typename T> // declaration only for TD;
    class TD;

    void find_type() {
        const int theAnswer = 42;
        auto x = theAnswer;
        auto y = &theAnswer;
        TD<decltype(x)> xType; // 推导规则 case3 - 去掉const, 剩下x=int
        TD<decltype(y)> yType; // 推导规则 case1 - 全部保留，y=const int*
    }
}

DEFINE_CODE_TEST(104_findtype)
{
    find_type();
}