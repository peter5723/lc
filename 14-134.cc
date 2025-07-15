// https://leetcode.cn/problems/gas-station/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 能否证明 all_cost <= all_gas 则必有解？
    // min_num 对应的 index 必定是一个解？
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int all_cost = 0;
        int all_gas = 0;
        int num = 0;
        int min_num = num;
        int index = 0;
        for(int i = 0; i < gas.size(); i++) {
            all_cost += cost[i];
            all_gas += gas[i];
            num = num + gas[i] - cost[i];
            if(num < min_num) {
                index = i + 1;
                min_num = num;
            }
        }
        if(all_cost > all_gas){
            return -1;
        }
        return index % gas.size();
    }
};