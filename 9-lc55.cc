// https://leetcode.cn/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150
#include <vector>
#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
    // consider dfs
    bool dfs(vector<int>& nums, int now_loc){
        if(now_loc >= nums.size() - 1) {
            return true;
        }
        if(now_loc!=nums.size()-1 && nums[now_loc]<=0){
            return false;
        }
        bool has_a_sol = false;
        for(int i = 1; i <= nums[now_loc]; i++){
            has_a_sol |= dfs(nums, now_loc + i);
            if(has_a_sol==true){
                //pruning
                break;
            }
        }
        return has_a_sol;
    }
    bool canJump1(vector<int>& nums) {
        return dfs(nums, 0);
    }

    // dfs will timeout.
    // consider greedy
    // 考虑能到达的最远位置。
    // 如果 x 可达，则 x 到 x+nums[x] 所有位置均可达。
    bool canJump(vector<int>& nums) {
        //max_d 是最远可到距离。
        int max_d = 0;
        for(int i=0;i<nums.size();i++){
            //先判断当前位置是否可到。
            bool can_get = (i <= max_d);
            if(!can_get){
                return false;
            }
            max_d = max(max_d, i+nums[i]);
        }
        return (max_d >= nums.size() - 1);
    }
    
    // max_d = max(max_d, i+nums[i]); 有最优子结构的特性，可以使用动态规划做。
};

int main(){
    Solution s;
    vector<int> nums1 = {2,3,1,1,4};
    vector<int> nums2 = {2,0,0,1};

    printf("%d %d\n", s.canJump(nums1), s.canJump(nums2));
}