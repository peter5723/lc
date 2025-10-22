#include <string>
#include <map>
#include <vector>
using namespace std;



class Solution {
public:
    string convert(string s, int numRows) {
        int r = numRows;
        int t = 2 * r - 2;
        int n = s.size();
        if (r==1 || r>=n){
            return s;
        }
        string ans="";
        for (int i = 0; i < r;i++){
            // 第 i 行
            for (int j = 0; j +i< n; j = j+t){
                //每个周期对应的x下标
                ans.push_back(s[j + i]);
                if(i>0&&i<r-1&& j+t-i<n){
                    ans.push_back(s[j + t - i]);
                }
            }
        }
        return ans;
    }
};
