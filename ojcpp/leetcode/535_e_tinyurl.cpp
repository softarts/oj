//
// Created by rui zhou on 2020-01-07.
//

/*
 * Note: This is a companion problem to the System Design problem: Design TinyURL.
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
 */


#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace {
    class Solution {
    public:
        unordered_map<string,string> m;
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

        // Encodes a URL to a shortened URL.
        string encode(string longUrl) {
            int uid = get_random(6);
            // to 62 BASE
            auto short_url = "http://tinyurl.com/"+to62base(uid);
            m[short_url] = longUrl;
            return short_url;
        }

        // Decodes a shortened URL to its original URL.
        string decode(string shortUrl) {
            auto iter = m.find(shortUrl);
            if (iter!=m.end()) {
                return iter->second;
            }
            return "";
        }


        string to62base(int uid) {
            static string tbl="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
            string ret;
            while (uid>0) {
                ret += tbl[(uid-1)%62];
                uid = (uid-1)/62;
            }
            return ret;
        }
    };

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
}

DEFINE_CODE_TEST(535_tinyurl)
{
    Solution obj;
    {
        string long_url = "www.google.com";
        string short_url = obj.encode(long_url);
        VERIFY_CASE(obj.decode(short_url),long_url);
    }


}
