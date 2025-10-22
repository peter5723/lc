#include<vector>
#include<cstdio>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int right = 0;
        int left = right = 0;
        int res = 0;
        int now_sum = 0;

        for (;right != nums.size() || now_sum >= target;) {
            if (now_sum < target) {
                if (right == nums.size()) {
                    break;
                }
                now_sum += nums[right];
                right++;
            }
            else {
                res = res == 0 ? (right - left) : min(right - left, res);
                now_sum -= nums[left];
                left++;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    int target = 7;
    vector<int> nums = { 2,3,1,2,4,3 };
    int res = s.minSubArrayLen(target, nums);
    printf("%d\n", res);
    return 0;
}
