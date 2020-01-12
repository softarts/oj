#ifndef CODECH_UTIL_H_
#define CODECH_UTIL_H_

#include <string>
#include <algorithm>
#include <random>
#include <vector>
namespace CODECH
{
    inline bool isspace(char ch)
    {
        return ch == ' ';
    }
    inline void trim(std::string &s) {
        s.erase(s.begin(), std::find_if_not(s.begin(), s.end(), [](char c){ return CODECH::isspace(c); }));
        s.erase(std::find_if_not(s.rbegin(), s.rend(), [](char c){ return CODECH::isspace(c); }).base(), s.end());
    }

    inline std::string& trim(std::string &&s) {
        s.erase(s.begin(), std::find_if_not(s.begin(), s.end(), [](char c){ return CODECH::isspace(c); }));
        s.erase(std::find_if_not(s.rbegin(), s.rend(), [](char c){ return CODECH::isspace(c); }).base(), s.end());
        return s;
    }

    inline int get_random(int sz) {
        int ret = 0;
        std::random_device rd; // obtain a random number from hardware
        std::mt19937 eng(rd()); // seed the generator

        for(int i = 0; i < sz;i++ ){
            std::uniform_int_distribution<> distr(0,9);
            ret = ret*10 + distr(eng);
        }
        return ret;
    }
}

#endif

