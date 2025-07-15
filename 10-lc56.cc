// https://leetcode.cn/problems/jump-game-ii/description/?envType=study-plan-v2&envId=top-interview-150
#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution
{
public:
    // dp
    // dp[i] = min_j(dp[j]+1)
    // o(n2)
    int jump1(vector<int> &nums)
    {
        int n = nums.size();
        int dp[n];
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            dp[i] = 2147483647;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] + j >= i)
                {

                    dp[i] = min(dp[j] + 1, dp[i]);
                }
            }
        }
        return dp[n - 1];
    }

    
    //下面的方法应该是可读性较好的o(n)方法。
    // 但是似乎和贪心关系不大。
    int jump(vector<int> &nums)
    {
        //[start, end]
        int start = 0;
        int end = 0;//0
        int max_p = 0;
        int step = 0;
        while (end < nums.size() - 1)
        {
            for(int i=start;i<=end;i++){
                max_p = max(max_p, i+nums[i]);
            }
            start = end;
            end = max_p;
            step++;
        }
        return step;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,2,1};
    int k = s.jump(nums);
    cout << k << "\n";
}