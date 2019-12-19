//
// Created by rui zhou on 2019-12-19.
//

#include <codech/codech_def.h>

using namespace std;
namespace {
    // member func temp can't be virtual func
    class Dynamic {
    public:
//        template <typename T2>
//        virtual void copy(T2 const&) {};  // virtual func can't be func template
    };

    template <typename T,T nontype_param>
    class C {};

    class Base {
    public:
        int i;
    } base;

    class Derived:public Base {

    } derived_object;


    void test_nontype() {
        // C<Base*,&derived_object> err1;  // no able to convert derived to base
        // C<int,base.i> err2; // error: non-type template argument is not a constant expression

//        int a[10];
//        int *const p=&a[0];
//        constexpr auto cp = p;
//        //C<int*,&a[0]> err3; // non-type template argument of type 'int *' is not a constant expression
//        //C<int*,p> err4; // non-type template argument of type 'int *' is not a constant expression
//        C<int*,cp> err5;
    }

    template<typename T, int I>
    class Mix;

    void test_equal() {
        Mix<int, 3*3>* p1;
        Mix<int, 4+5>* p2;
        p1=p2;
        //Mix<int, 4+5+6>* p3 = p2;  // not equal

    }

    // friend function
    template<typename T>
    void multiply(T);

    class TestFriend {
        friend void multiply(int);  // not template func, it declare a new func()
        friend void multiply<int>(int);
        int x = 99;
    };

    TestFriend tf;

    template<typename T>
    void multiply(T obj) {
        cout << tf.x<< endl; //not access private member,because it is not friend
    }


    void test_friendfunc() {

        // cout << tf.x<< endl; //not access private member
        multiply(5);
    }

    template<typename T>
    class Creator {
    public:
        friend void appear(){}// 相当于定义friend function twice
    };

    void test_twiceinit() {
        Creator<int> a;
        //Creator<double> b;
    }
}

DEFINE_CODE_TEST(208_nontypemisc)
{
    //test_nontype();
    //test_equal();
    test_friendfunc();
}
