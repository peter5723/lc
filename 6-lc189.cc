// https://leetcode.cn/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    //o(n) o(1)
    void rotate(vector<int>& nums, int k) {
       int new_loc;
        int count=0;
        int i = 0;
        int tmp = 0;
        while(count<nums.size()){
            new_loc = (i + k) % nums.size();
            while (new_loc!=i)
            {
                // 循环的第一个数 i 是下一个待确定新位置的数字。
                swap(nums[i], nums[new_loc]);
                new_loc = (new_loc + k) % nums.size();
                count++;
            }
            //如果now_loc == i，意味着 now_loc 这个数确定位置。
            count++;
            i++;
            
        }
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {1,2,3,4,5,6,7};
    vector<int> nums2 = {-1,-100,3,99};
    int k=2;
    s.rotate(nums2, k);
    for(auto i:nums2){
        printf("%d ",i);
    }
    printf("\n");
    return 0;
}