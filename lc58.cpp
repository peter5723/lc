#include<string>
#include<map>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        // just need to find the last space.
        int last_space_loc = -1;


        // need to jump_space.
        int last_not_space = s.size() - 1;
        if(s[last_not_space]==' ') {
            while (s[last_not_space]==' ')
            {
                last_not_space--;
            }

        }

        for (int i = last_not_space; i >= 0; i--){
            if(s[i]==' '){
                last_space_loc = i;
                break;
            }
        }
        if(last_space_loc == -1) {
            return last_not_space - 0 + 1;
        }
        return (last_not_space) - (last_space_loc + 1) + 1;
    }
};
