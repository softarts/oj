//
// Created by rui zhou on 2019-12-16.
//

#include <codech/codech_def.h>
using namespace std;

namespace {
    template<typename T>
    class Stack {
    private:
        std::vector<T> elems;
    public:
        void push(T const&elem) {}
    };


    void test_classtemp() {
        Stack<int> st;
        st.push(5);
    }
}

DEFINE_CODE_TEST(203_classtemp)
{
    test_classtemp();
}