#include<string>
#include<map>
using namespace std;
//注 map效率低，需要高效率改成直接字符映射即可。
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        map<char, char> s2t;
        map<char, char> t2s;
   
        for (int i = 0;i < s.size();i++) {
            if (s2t.find(s[i]) == s2t.end()) {
                s2t[s[i]] = t[i];
            } 
            if(t2s.find(t[i]) == t2s.end()) {
                t2s[t[i]] = s[i];
            }
            if(s2t[s[i]]!=t[i]||t2s[t[i]]!=s[i]){
                return false;
            }
        }
        return true;
    }
};


int main() {
    string s = "egg";
    string t = "add";
    Solution s1;
    s1.isIsomorphic(s, t);
    return 0;
}