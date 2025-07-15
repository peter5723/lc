// https://leetcode.cn/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> L(nums.size(), 0);
        vector<int> R(nums.size(), 0);
        vector<int> ans(nums.size(), 0);
        L[0] = 1;
        for(int i = 1; i < nums.size(); i++) {
            L[i] = L[i-1] * nums[i-1];
        }
        R[nums.size()-1]=1;
        for(int i=nums.size()-2; i >= 0; i--){
            R[i] = R[i+1] * nums[i+1];
        }
        for(int i=0; i<nums.size();i++){
            ans[i] = L[i] * R[i];
        }
        return ans;
    }
};