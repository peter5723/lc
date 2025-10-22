// https://leetcode.cn/problems/candy/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    // 思路：
    // num是糖果数
    //  先按 rating[i]>rating[i-1]算，只考虑左边
    //  再按 rating[i]>rating[i+1]算，只考虑右边
    //  两者算得的 candy 数量取最大值的话，则左右两个不等式均可以满足。
    int candy(vector<int>& ratings) {

        int n = ratings.size();
        vector<int> left(n, 1);
        int right;
        int ret = 0;

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
            else {
                left[i] = 1;
            }
        }

        right = 1;
        ret += max(left[n - 1], right);

        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right++;
            }
            else {
                right = 1;
            }

            ret += max(left[i], right);
        }
        return ret;
    }
};