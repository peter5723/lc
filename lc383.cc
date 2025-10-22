#include<string>
#include<map>
using namespace std;


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size() > magazine.size()) {
            return false;
        }
        map<char,int> cnt;

        for(char c:magazine){
            cnt[c]++;
        }
        for(char c:ransomNote){
            cnt[c]--;
            if(cnt[c] < 0) {
                return false;
            }
        }
        return true;
    }
};