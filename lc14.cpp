#include<string>
#include<map>
#include<vector>
using namespace std;



class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        // find min sentence.
        int min_sent_index = 0;
        for (int i = 0; i < strs.size(); i++){
            min_sent_index = strs[i].size() < strs[min_sent_index].size() ? i : min_sent_index;
        }

        int prefix_num = -1;
        bool same = true;
        for (int i = 0; i < strs[min_sent_index].size(); i++) {
            for (int j = 0; j < strs.size(); j++){
                if(strs[j][i]!=strs[min_sent_index][i]){
                    same = false;
                    break;
                }
            }
            if(same = false) {
                break;
            }
            prefix_num++;
        }
        if(prefix_num==-1){
            return "";
        }
        return strs[min_sent_index].substr(0, prefix_num+1);
        //string substr(size_t pos = 0, size_t len = npos) const;
    }
};

int main(){
    Solution s;
    vector<string> a = {"dog", "racecar", "car"};
    s.longestCommonPrefix(a);
}
