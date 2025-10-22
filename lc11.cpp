#include<vector>

using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int left, right;
        left = 0;
        right = height.size() - 1;
        int max_size = 0;
        while (left < right)
        {
            max_size = std::max(max_size, (right - left) * std::min(height[left], height[right]));
            if(height[left] < height[right]) {
                left++;
            } else
            {
                right--;
            }

        }
        return max_size;
    }
};
