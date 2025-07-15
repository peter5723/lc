#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    // fast slow pointer
    int removeDuplicates(vector<int> &nums)
    {

        if(nums.size()==0){
            return 0;
        }
        int i = 0;
        int j = 0;
        for (j = 0; j < nums.size(); j++)
        {
            if (nums[j] == nums[i])
            {
                continue;
            }
            else
            {
                i++;
                nums[i] = nums[j];
            }
        }

        return i+1;
    }
};