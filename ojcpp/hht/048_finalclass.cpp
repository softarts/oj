//
// Created by rui zhou on 2019-12-11.
//

#include <codech/codech_def.h>
using namespace std;

namespace {
    class FinalClass {
    public:
        ~FinalClass() = delete;
    };

    class Child: public FinalClass {
    public:
        int x;
    };
    void test_final() {
        // Child obj; error
    }
}

DEFINE_CODE_TEST(hht_048_finalclass)
{
    test_final();
}