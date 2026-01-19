#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//此题面试几率大。
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 按照左端点排序。
        std::sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(auto& p: intervals) {
            int L=p[0],R=p[1];
            if(ans.empty() || ans.back()[1] < L) {
                ans.push_back({L,R});
            }
            else {
                ans.back()[1] = max(ans.back()[1], R);
            }
        }
        return ans;
    }
};