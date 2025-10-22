// https://leetcode.cn/problems/gas-station/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        // res 是我们希望求的站点解
        int res = 0;
        int now_gas = 0;
        int count_road = 0;
        // 一定不会是解的站点。
        // 从 i+1 开始，到 i+m+1 缺油，则 i+1 到 i+m 都不是解。
        while (res < n)
        {
            now_gas = 0;
            count_road = 0;
            for (int i = res; count_road <= n; i++, count_road++)
            {

                int j = i % n;
                if (now_gas + gas[j] - cost[j] >= 0)
                {
                    now_gas += (gas[j] - cost[j]);

                    continue;
                }
                else
                {
                    res = i + 1;
                    break;
                }
            }
            if (count_road == n + 1)
            {
                return res;
            }
        }
        return -1;
    }
};

int main()
{

    Solution s;
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    cout << s.canCompleteCircuit(gas, cost);
    return 0;
}