#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>>
        threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        int old_i = -1;
        for (int i = 0; i < nums.size(); i++, old_i++) {
            if (old_i != -1 && nums[old_i] == nums[i]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            int old_left = -1;
            int old_right = -1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] == 0) {
                    if (!(old_left != -1 && nums[left] == nums[old_left] || old_right != -1 && nums[right] == nums[old_right])) {
                        res.push_back({ nums[i], nums[left], nums[right] });
                    }
                    old_left = left;
                    left++;
                }
                else if (nums[i] + nums[left] + nums[right] < 0) {
                    old_left = left;
                    left++;

                }
                else if (nums[i] + nums[left] + nums[right] > 0) {
                    old_right = right;
                    right--;
                }
            }

        }
        return res;
    }
};

int main() {
    vector<int> nums = { -1,0,1,2,-1,-4 };
    Solution s;
    vector<vector<int>> g = s.threeSum(nums);
    return 0;
}
