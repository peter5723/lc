// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/?envType=study-plan-v2&envId=top-interview-150


#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size(),0);
        int min_price = prices[0];
        int i;
        for( i=1;i<prices.size();i++){
            min_price = min(min_price, prices[i]);
            dp[i] = max(dp[i-1], prices[i]-min_price);
        }
        return dp[i-1];

    }
};