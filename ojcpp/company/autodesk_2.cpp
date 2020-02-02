//
// Created by rui zhou on 2020-01-16.
//

#include <codech/codech_def.h>

// Coding problem: 45 minute time limit.

// PROBLEM DEFINITION
// ------------------
// Reverse each word in the input string.
// The order of the words will be unchanged.
// A word is made up of letters and/or numbers.
// Other characters (spaces, punctuation) will not be reversed.

// NOTES
// ------
// Write production quality code
// We prefer clarity over performance (though if you can achieve both - great!)
// You can use the language that best highlights your programming ability
//    the template below is Python – but you can write
//    in Java/C++/C#/Haskell/etc if you feel you solve the
//    problem better in that language.
// A working solution is preferred (assert in main() should succeed)
// Bonus points for good tests

#include <string>
#include <assert.h>

using namespace std;

namespace {
    std::string reverse_words(const std::string &str)
    {
        string ans;
        string tmp;
        for (auto c : str) {
            if (isalnum(c)) {
                tmp = c+tmp;
            }  else {
                ans = ans+tmp+c;
                tmp="";
            }
        }
        return ans+tmp;
    }

    int main()
    {
        std::string test_str = "String;   2be reversed...";
        assert(reverse_words(test_str) == "gnirtS;   eb2 desrever...");


        assert(reverse_words("abc def") == "cba fed");
        assert(reverse_words("abc +def") == "cba +fed");
        assert(reverse_words("abcdef") == "fedcba");
        assert(reverse_words("a,b$c") == "a,b$c");
        assert(reverse_words("abc1def") == "fed1cba");
        assert(reverse_words("Abcdef ### abcdef") == "fedcbA ### fedcba");
        assert(reverse_words("") == "");
        assert(reverse_words("*()*!") == "*()*!");
        assert(reverse_words("AAAB*()*!BBBA") == "BAAA*()*!ABBB");
        assert(reverse_words("!@#$%ACDB*()*!BBBA") == "!@#$%BDCA*()*!ABBB");
        assert(reverse_words("A B C D E F G H I J K") == "A B C D E F G H I J K");
        assert(reverse_words(" A B C D E F G H I J K ") == " A B C D E F G H I J K ");
        assert(reverse_words("[]") == "[]");

        assert(reverse_words("this\x01 is a \x7f test string") == "siht\x01 si a \x7f tset gnirts");

        assert(reverse_words("// Write production quality code\n"
                      "// We prefer clarity over performance (though if you can achieve both - great!)\n"
                      "// You can use the language that best highlights your programming ability\n"
                      "//    the template below is Python – but you can write\n"
                      "//    in Java/C++/C#/Haskell/etc if you feel you solve the\n"
                      "//    problem better in that language.\n"
                      "// A working solution is preferred (assert in main() should succeed)\n"
                      "// Bonus points for good tests") \
                      == \
                    "// etirW noitcudorp ytilauq edoc\n"
                    "// eW referp ytiralc revo ecnamrofrep (hguoht fi uoy nac eveihca htob - taerg!)\n"
                    "// uoY nac esu eht egaugnal taht tseb sthgilhgih ruoy gnimmargorp ytiliba\n"
                    "//    eht etalpmet woleb si nohtyP – tub uoy nac etirw\n"
                    "//    ni avaJ/C++/C#/lleksaH/cte fi uoy leef uoy evlos eht\n"
                    "//    melborp retteb ni taht egaugnal.\n"
                    "// A gnikrow noitulos si derreferp (tressa ni niam() dluohs deeccus)\n"
                    "// sunoB stniop rof doog stset");


        return 0;
    }

}

{
// Jump Game
//   [3, 1, 2, 1, 4] -> Possible  
// [3, 2, 1, 0, 4] -> Not Possible
// [0,1,1,1,1] -> not possible
// [1,0,1,1,1] -> not possible

bool CanJump(vector<int> v)
{
     	if (v.empty()) return false;
    if (v.size()==1) return true;
    int start = 0;
    int end = 0;
    int l = v.size()-1;
    while (start < end && start<=l) {
        if (v[start] == 0 && end == start)
            return false;

        end = max(end,v[start]+start);

        if (end>=l)
            return true;
        start++;
    }
    return (end>=l?true:false);
     } 
}

DEFINE_CODE_TEST(autodesk_reversewords)
{
    main();
}