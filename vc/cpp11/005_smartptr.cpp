//
// Created by rui zhou on 24/04/19.
//

#include <codech/codech_def.h>
using namespace std;

// deprecated, not test
//namespace autoptr {
//    struct Resource
//    {
//        Resource()
//        {
//            x = 101;
//            std::cout << "ctor" << std::endl;
//        }
//        ~Resource()
//        {
//            x = 0;
//            std::cout << "dtor" << std::endl;
//        }
//        int x;
//    };
//
//    void auto_ptr_test()
//    {
//        {
//            auto_ptr<Resource> pt(new Resource);
//        }
//        vector<auto_ptr<Resource>> vec;
//        vec.push_back(auto_ptr<Resource>(new Resource()));
//
//        {
//            auto_ptr<Resource> pt1 = vec[0];  // ownership transfer to pt1
//            std::cout << pt1->x << std::endl;
//        }
//
//        std::cout << vec.size() << vec[0]->x <<std::endl;
//    }
//}

// unique_ptr
namespace {
    struct B {
        virtual void bar() { std::cout << "B::bar\n"; }
        virtual ~B() = default;
    };
    struct D : B
    {
        D() { std::cout << "D::D\n"; }
        ~D() { std::cout << "D::~D\n"; }
        void bar() override { std::cout << "D::bar\n"; }
    };

    auto deleter = [](D* ptr) {
        cout << "I am deleter" << endl;
        if (ptr)
            delete ptr;
    };

    class Deleter {
    public:
        int arr[5000]={0};
        void operator()(D*ptr) {
            cout << "I am Class deleter" << endl;
            if (ptr)
                delete ptr;
        }
    };

#include <memory>
    void unique_ptr_test()
    {
        {
            auto p1 = std::make_unique<D>(); // p is a unique_ptr that owns a D
            //auto invalid = p1;  // no copy ctor in unique_ptr
            // same size as plain struct
            cout << "unique ptr size is " << sizeof(p1) << " struct B size is " << sizeof(B) << endl;
            auto p2 = std::unique_ptr<D>(new D());

            // transfer ownership
            std::unique_ptr<D> p3(std::move(p2));  // p2
            if (!p2) {
                cout << "p2 is no more valid" << endl;
            }
        } // ~D called here

        {
            std::unique_ptr<D,decltype(deleter)> p4(nullptr,deleter);
            std::unique_ptr<D> p5;
            std::unique_ptr<D,decltype(deleter)> p6(new D(),deleter); // call I m deleter
            cout << "unique ptr with deleter size " << sizeof(p6) << endl;
            // std::unique_ptr<D,decltype(deleter)> p6; not compiled
        } // for not null ptr call deleter here

        {
            std::unique_ptr<D,Deleter> p6(new D(),Deleter() ); //use class object as deleter
            cout << "unique ptr size is " << sizeof(p6) << " struct B size is " << sizeof(B) << endl;
        }
    }
}

#include <chrono>
#include <thread>
namespace sharedptr {
    struct Resource  {
        Resource(int _x) {
            x = _x;
            std::cout << "Resource ctor " << x << std::endl;
        }
        ~Resource() {
            x = 0;
            std::cout << "Resource dtor" << std::endl;
        }
        int x;
    };
    // 如果是shared_ptr是引用，多线程中确实需要判断该指针是否可能会在别处被释放
    void reader(std::shared_ptr<Resource> &ptr) {
        while(true) {
            std::cout << "shared ptr use count " << ptr.use_count() << std::endl;
            if (ptr.get()) {
                cout <<"val="<< ptr->x << endl;
            }
            std::this_thread::sleep_for(1s);
            std::cout << "sleep timeout" << std::endl;  // will crash after main thread exit
        }
    }
    //The constructor of std::thread deduces argument types and stores copies of them by value.
    //This is needed to ensure the lifetime of the argument object is at least the same as that of the thread.
    void sharedptr_ref_test() {
        {
            std::shared_ptr<Resource> ptr(new Resource(5));
            std::thread t(reader, std::ref(ptr));
            std::this_thread::sleep_for(chrono::seconds(2));
            std::cout << "main thread exit.." << std::endl;
            t.detach(); // otherwise thread will be terminated
        }
        std::this_thread::sleep_for(chrono::seconds(5));
    }


    // enable shared -------------------------------------
    // 前提，该对象必须已经存在一个被shared_ptr管理的指针，并且要从enabled_shared_from_this继承
    struct Good:std::enable_shared_from_this<Good>
    {
        std::shared_ptr<Good> getSharedptr() {
            return shared_from_this();
        }
        Good(std::shared_ptr<Good> &p)
        {
            // do nothing
        }
        Good(){
            cout << "in enable shared from this ctor" << endl;
        }
    };

    void test_enabled_bad() {
        Good *pBad = new Good();
        // Bad: shared_from_this is called without having std::shared_ptr owning the caller
        try {
            std::shared_ptr<Good> gp1 = pBad->getSharedptr();  // pBad is not owned by shared_ptr,it is a raw ptr
        } catch(std::bad_weak_ptr& e) {
            // undefined behavior (until C++17) and std::bad_weak_ptr thrown (since C++17)
            std::cout << e.what() << '\n';
        }
    }

    void test_enable_good()
    {
        //Good
        std::shared_ptr<Good> p1(new Good());
        try {
            std::shared_ptr<Good> p2 = p1->getSharedptr();
            std::cout << "shared ptr use count " << p1.use_count() << std::endl;
        } catch(std::bad_weak_ptr& e) {
            // undefined behavior (until C++17) and std::bad_weak_ptr thrown (since C++17)
            std::cout << e.what() << '\n';
        }
    }

    void test_enabled_shared() {
        test_enabled_bad();
        test_enable_good();
    }

    // 对数组的支持
    void test_shared_arr() {
        //std::shared_ptr<int[]> p2(new int[10]); //C++ 17 good
        //p1[0]=1;
        std::shared_ptr<int> p1(new int[10],[](int*ptr){delete []ptr;});
        // p1[0] = 0; no support
        p1.get()[1]=0;
    }

    // deleter
    class Widget {};
    auto widgetDeleter1 = [](Widget*pw) {delete pw;};
    auto widgetDeleter2 = [](Widget*pw) {delete pw;};

    void test_deleter() {
        // shared_ptr<Widget,widgetDeleter1> ptr1(new Widget);  bad
        shared_ptr<Widget> ptr1(new Widget,widgetDeleter1);
        shared_ptr<Widget> ptr2(new Widget,widgetDeleter2);
        //shared_ptr<Widget> ptr3(ptr2,widgetDeleter1);  //bad
        vector<shared_ptr<Widget>> vec{ptr1,ptr2};
    }

    // ---------------------------------------------
    // atomic 支持
    struct A {};
    struct B :public A { int x=1;};
    void test_shared_atomic() {
        shared_ptr<A> a = std::make_shared<B>();
        shared_ptr<A> b;
        std::atomic_store(&b,a); // Error here
    }


}

namespace weakptr{
    // weak_ptr -------------------------------------------
    struct Resource
    {
        Resource()
        {
            x = 101; // 4bytes
            std::cout << "ctor" << std::endl;
        }
        ~Resource()
        {
            x = 0;
            std::cout << "dtor" << std::endl;
        }
        int x;
    };

    void weak_ptr_test()
    {
        cout << "// weak_ptr -------------------------------------------" << endl;
        std::shared_ptr<Resource> p1 = std::make_shared<Resource>();
        std::cout << "size of shared ptr " << sizeof(p1) << std::endl;  // 8bytes, 4-raw ptr, 4-count block?

        std::weak_ptr<Resource> wp1(p1);
        std::cout << "use count : " << wp1.use_count() << "\n";
        //p1.reset();

        //weak ptr->shared ptr
        //std::shared_ptr<Resource> spw1 = wp1.lock();  //good
        std::shared_ptr<Resource> spw1(wp1);  //good
        if (spw1)
        {
            std::cout << "create a shared ptr from the resource" << std::endl;
            std::cout << "use count after a new shared_ptr: " << wp1.use_count() << "\n";
        } else {
            cout << "unable to get shared_ptr from weak_ptr" << endl;
        }

        // std::shared_ptr<Resource> spw2 = wpw1;  // compiler error
        p1.reset();
        p1 = nullptr;
        std::cout << "use count after spw reset: " << wp1.use_count() << "\n";

        if (wp1.expired())
        {
            std::cout << "the object was destroy" << std::endl;
        }
    }
}

DEFINE_CODE_TEST(005_smartptr)
{
    //sharedptr::test_enabled_shared();
    //sharedptr::test_shared_arr();

    //sharedptr::test_shared_atomic();
    sharedptr::test_deleter();

    //sharedptr::sharedptr_ref_test();
    //unique_ptr_test();

    //weakptr::weak_ptr_test();
}

