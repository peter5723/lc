// https://leetcode.cn/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    // map
    map<int,int> mymap;
    int majorityElement(vector<int>& nums) {
        map<int,int> mymap;

        for(int num:nums){
            if(mymap.find(num)==mymap.end()){
                mymap.insert(std::make_pair(num, 1));
            }else{
                mymap[num]++;
            }
        }
        for(auto it=mymap.begin(); it!=mymap.end(); it++){
            if(it->second>=nums.size()/2+1){
                return it->first;
            }
        }

    }
};