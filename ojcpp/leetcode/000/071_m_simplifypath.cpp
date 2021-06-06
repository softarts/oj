//
// Created by rui.zhou on 3/13/2019.
//

/*
 * Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.

In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double period .. moves the directory up a level. For more information, see: Absolute path vs relative path in Linux/Unix

Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names. The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path.



Example 1:

Input: "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.
Example 2:

Input: "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
Example 3:

Input: "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
Example 4:

Input: "/a/./b/../../c/"
Output: "/c"
Example 5:

Input: "/a/../../b/../c//.//"
Output: "/c"
Example 6:

Input: "/a//b////c/d//././/.."
Output: "/a/b/c"
 */
#include <codech/codech_def.h>
//#include <iostream>
//#include <istream>
using namespace std;
namespace lc071 {
    class Solution {
    public:
        string simplifyPath(string path) {
            stack<string> stk;
            stringstream ss(path);
            string tmp;
            while (getline(ss,tmp,'/')) {
                if (tmp==".") continue;
                if (tmp=="") {
                    continue;
                }
                if (tmp=="..") {
                    if (!stk.empty()) stk.pop();
                }
                else stk.push(tmp);
            }
            string ret="";
            while (!stk.empty()) {
                ret =  "/" + stk.top() +ret ;
                stk.pop();
            }
            if (ret=="") ret="/";
            return ret;
        }
    };
}

DEFINE_CODE_TEST(071_simplifypath)
{
    lc071::Solution obj;
    {
        VERIFY_CASE(obj.simplifyPath("/../"),"/");
        VERIFY_CASE(obj.simplifyPath("/home/"),"/home");
        VERIFY_CASE(obj.simplifyPath("/a/./b/../../c/"),"/c");
        VERIFY_CASE(obj.simplifyPath("/a/../../b/../c//.//"),"/c");
        VERIFY_CASE(obj.simplifyPath("/home//foo/"),"/home/foo");
    }
}
