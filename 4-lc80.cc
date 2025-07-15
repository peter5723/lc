#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    // fast slow pointer
    // I think use stack is the best.

    // if nums[n]=nums[n-k],then  nums[n]= nums[n-1] = nums[n-2] =...nums[n-k]
    int removeDuplicates(vector<int> &nums)
    {

        int numsstack = 2;
        int top = 1;
        if (nums.size() <= 2)
        {
            return nums.size();
        }
        int j = 2;

        for (; j < nums.size(); j++)
        {
            if (nums[j] == nums[top - 1])
            {
                continue;
            }
            else
            {
                top++;
                nums[top] = nums[j];
            }
        }
        return top + 1;
    }
};