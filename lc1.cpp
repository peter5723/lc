#include<vector>
#include<sstream>
#include<string>
#include<map>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        for (int i = 0;i < nums.size();i++) {
            if (hashmap.find(target - nums[i]) == hashmap.end()) {
                hashmap[nums[i]] = i;
                continue;
            }
            return { hashmap[target - nums[i]], i };
        }
        return {};
    }
};
