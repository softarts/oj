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

    template<string name>
    void useString() {
        cout << name << endl;
    }
}

DEFINE_CODE_TEST(204_nontypetemp)
{
    //test_nontypetemp();
    test_nontype_functemp();
}