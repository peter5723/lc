#include<string>
#include<iostream>
using namespace std;


class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        int count = 0;
        for (; i < s.size() && j < t.size(); j++) {
            if(s[i]==t[j]){
                i++;
                count++;
            }
        }
        return count == s.size();
    }
};

int main() {
    string s = "axc";
    string t = "ahbgdc";
    Solution sol;
    std::cout << sol.isSubsequence(s, t);
    return 0;
}
