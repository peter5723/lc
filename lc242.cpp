#include<string>
#include<unordered_map>
using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> st_count;
        for (int i = 0;i < s.size();i++) {
            st_count[s[i]]++;
            st_count[t[i]]--;
        }
        for (const auto& pair : st_count) {
            if (pair.second != 0) {
                return false;
            }
        }

        return true;
    }
};
