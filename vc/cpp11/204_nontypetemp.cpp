//
// Created by rui zhou on 2019-12-16.
//
#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace {
    template<typename T, int MAXSIZE=100>
    class Stack {
    private:
        T elems[MAXSIZE];
        int size = 0;
    public:
        void push(const T &elem) {
            elems[size++] = elem;
        }
    };

    void test_nontypetemp() {
        Stack<int, 5> st;
        st.push(5);
    }
    // =========================================
    template<typename T, int VAL>
    T addValue(T const& x) {
        return x + VAL;
    }

    void test_nontype_functemp() {
        vector<int> arr{1,2,3,4,5};
        vector<int> dest;
        transform(arr.begin(),arr.end(),back_inserter(dest),addValue<int,5>);
        cout << PRINT_VEC(std::forward<vector<int>>(dest)) << endl;
    }

    // error
//    template<string name>
//    void useString() {
//        cout << name << endl;
//    }

#if __GNUC__
#if __x86_64__ || __ppc64__
#define ENV64BIT
#else
#define ENV32BIT
#endif
#endif

    // determine platform ======================
    void test_cpu0() {
#if defined ENV64BIT
        cout << "it is 64bit\n";
#elif defined ENV32BIT
        cout << "it is 32bit\n";
#endif
    }

    constexpr int cpu = sizeof(void*);
    void test_cpu1() {
        if (cpu==8) {
            cout << "it is 64bit\n";
        } else {
            cout << "it is 32bit\n";
        }
    }

    template<int>
    struct Thing;

    template<>
    struct Thing<4>
    { typedef uint32_t type; };

    template<>
    struct Thing<8>
    { typedef uint64_t type; };

    typedef Thing<sizeof(void*)>::type thingtype;


    void test_cpu2() {
        thingtype val;  // cpu size
    }

    // another
    template<typename IntType, typename std::enable_if<sizeof(IntType) == 4>::type* = nullptr>  //?????TODO
    void foo(IntType& out)
    {
        cout << "it is 32bit\n";
    }

    template<typename IntType, typename std::enable_if<sizeof(IntType) == 8>::type* = nullptr>
    void foo(IntType& out)
    {
        cout << "it is 64bit\n";
    }



    void test_cpu3() {
        int val=4;
        foo<int>(val);
    }


    // credit sussie
    template <class T, int S = 100> struct Array
    {
        T arr[S];
        int size() const { return S; }
    };

    template<> struct Array<int, 200>
    {
        int arr[200];
        int size() const { return 201; }
    };

    void test_cs() {
        std::cout << Array<int,200>().size() << '\n';
    }
}

DEFINE_CODE_TEST(204_nontypetemp)
{
    //test_nontypetemp();
    //test_nontype_functemp();
    //test_cpu3();
    test_cs();
}