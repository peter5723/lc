#include<vector>
using namespace std;

// 此题双指针思路是直觉，但是证明可能有难度
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        while(i < j){
            if(numbers[i]+numbers[j]==target){
                break;
            }
            else if(numbers[i]+numbers[j]<target){
                i++;
            }
            else if (numbers[i]+numbers[j]>target)
            {
                j--;
            }
        }
        vector<int> res;
        res.push_back(i+1);
        res.push_back(j+1);
        return res;
    }
};
