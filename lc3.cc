#include<string>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int right = 1;
        int left = 0;
        int max_res = 1;
        while (right != s.size()) {
            string sub1 = s.substr(left, right - left);
            if (sub1.find(s[right]) == string::npos) {
                right++;
                max_res = max(max_res, right - left);
            }
            else {
                left++;
            }
        }
        return max_res;
    }

};