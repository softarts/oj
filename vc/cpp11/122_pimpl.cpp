//
// Created by rui zhou on 2019-11-29.
//

#include <codech/codech_def.h>
#include <memory>

using namespace std;

namespace {
    class Widget {
    public:
        unique_ptr<int> mptr;
        Widget():mptr(make_unique<int>(1)) {

        }
    };

    void tes_uniqueptr_copy() {
        Widget w0;
        // Widget w1(w0);//error  copy constructor of 'Widget' is implicitly deleted because field 'mptr' has a deleted copy constructor
    }
}

DEFINE_CODE_TEST(122_pimpl)
{
    tes_uniqueptr_copy();
}
