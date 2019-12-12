//
// Created by rui zhou on 2019-12-12.
//

#include <codech/codech_def.h>
using namespace std;

namespace {
    class Widget {
    public:
        int x = 5;
    };

    void lambda_capture() {
        auto ptr = make_unique<Widget>();
        ptr->x=10;
        auto f = [&]() {
            ptr->x = 20;
        };

        f();
        cout <<ptr->x <<endl;
    }

    void lambda_capture1() {
        auto ptr = make_unique<Widget>();
        ptr->x=10;
        auto f = [ptr = move(ptr)]() {
            cout <<"inside lambda:"<< ptr->x <<endl;
        };

        f();
        if (ptr) {
            cout <<"outside:"<< ptr->x <<endl;
        } else {
            cout <<"destroy";
        }

    }

    void lambda_capture2() {
        auto ptr = make_unique<Widget>();
        ptr->x=111;
        auto f = [ptr = make_unique<Widget>()]() {
            cout <<"inside lambda:"<< ptr->x <<endl;  // no capture outside
        };

        f();
        if (ptr) {
            cout <<"outside:"<< ptr->x <<endl;
        } else {
            cout <<"destroy";
        }
    }



    void c11_capture(){
        auto ptr = make_unique<Widget>();
        ptr->x=111;
        auto f = std::bind([](const std::unique_ptr<Widget>& pw) {
            cout <<"inside bind:"<< pw->x <<endl;  // no capture outside
        }, move(ptr));
        f();
        if (ptr) {
            cout <<"outside:"<< ptr->x <<endl;
        } else {
            cout <<"destroy";
        }
    }

    void unique_param(std::unique_ptr<Widget> pw) {
        cout <<"inside unique_test:"<< pw->x <<endl;  // no capture outside

    }

    void test_unique() {
        auto ptr = make_unique<Widget>();
        ptr->x=111;
        unique_param(move(ptr));
        if (ptr) {
            cout <<"outside:"<< ptr->x <<endl;
        } else {
            cout <<"destroy";
        }
    }

}

DEFINE_CODE_TEST(132_lambda_capture)
{
    //lambda_capture();
    //lambda_capture1();
    //lambda_capture2();
    c11_capture();
    //test_unique();

}