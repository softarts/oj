//
// Created by rui.zhou on 2019/12/17.
//

#include  <codech/codech_def.h>
using namespace std;
namespace {
    class Singleton {
    public:
        static Singleton & getInstance() {
            static Singleton obj;
            return obj;
        }

        void test() {
            cout << "I am singleton test\n";
        }
        // Singleton() = delete;
    };

    void test_singleton() {
        Singleton &obj = Singleton::getInstance();

    }
}

DEFINE_CODE_TEST(002_singleton)
{
    test_singleton();
}