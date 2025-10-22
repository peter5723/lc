#include<string>
#include<map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> r_to_i;
        r_to_i.insert(make_pair('I', 1));
        r_to_i.insert(make_pair('V', 5));
        r_to_i.insert(make_pair('X', 10));
        r_to_i.insert(make_pair('L', 50));
        r_to_i.insert(make_pair('C', 100));
        r_to_i.insert(make_pair('D', 500));
        r_to_i.insert(make_pair('M', 1000));
        int num = 0;
        for (int i = 0; i < s.size(); i++) {
            if(i==s.size()-1){
                num += r_to_i[s[i]];
            } else {
                if(r_to_i[s[i]] >= r_to_i[s[i+1]]){
                    num += r_to_i[s[i]];
                } else {
                    num -= r_to_i[s[i]];
                }
            }
        }
        return num;
    }
};
