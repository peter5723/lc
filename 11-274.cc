// https://leetcode.cn/problems/h-index/description/?envType=study-plan-v2&envId=top-interview-150
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 要加 static，不然cmp函数会变成成员函数
    // 静态成员函数不需要对象实例即可调用
    static bool descendingcmp(int a, int b){
        return a > b;
    }
    int hIndex(vector<int>& citations) {
        std::sort(citations.begin(), citations.end(), descendingcmp);
        int h = 0;
        for(int i=0;i<citations.size();i++){
            // 降序排列。8 5 5 4 3 3 2 1
            // 若当前的citations值大于等于 (index+1)，则 (index+1) 满足 h 值的条件。
            if(citations[i]>=(i+1)){
                h=i+1;
            }
        }
        return h;
    }
};