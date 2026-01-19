#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        std::sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(auto &p:intervals) {
            int L = p[0], R = p[1];
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