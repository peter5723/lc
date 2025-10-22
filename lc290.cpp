#include<vector>
#include<sstream>
#include<string>
#include<map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> split_s;
        istringstream str(s);
        string out;
        while(str >> out){
            split_s.push_back(out);
        }

        if (split_s.size() != pattern.size()) {
            return false;
        }

        unordered_map<char, string> c2s;
        unordered_map<string, char> s2c;

        for (int i = 0;i < split_s.size();i++) {
            if (c2s.find(pattern[i]) == c2s.end()) {
                c2s[pattern[i]] = split_s[i];
            }
            if (s2c.find(split_s[i]) == s2c.end()) {
                s2c[split_s[i]] = pattern[i];
            }

            if (c2s[pattern[i]] != split_s[i]) {
                return false;
            }

            if (s2c[split_s[i]] != pattern[i]) {
                return false;
            }
        }
        return true;
    }
};
