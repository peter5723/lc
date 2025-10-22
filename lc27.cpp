#include <vector>
#include <iostream>
using namespace std;
class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            // use two pointers
            // the first is now's position(not val)
            // the second is the val's position
            // if val's position's num != val, swap
            // if == val, val'pos--, then compare and try
            // until now==val
            if(nums.size() == 0){
                return 0;
            }
            int now_pos = 0;
            int val_pos = nums.size() - 1;
            int k = 0;
            while(now_pos != val_pos) {
                if(nums[now_pos] == val) {

                    while (nums[val_pos]==val && val_pos != now_pos)
                    {
                        val_pos--;

                    }
                    //my_swap(nums, now_pos, val_pos);
                    swap(nums[now_pos], nums[val_pos]);
                }
                if(val_pos == now_pos) {
                    break;
                }
                now_pos++;
            }
            k= nums[now_pos]==val ? now_pos: now_pos+1;
            return k;
        }
    };

int main()
{
    // vector<int> a = { 3, 2, 2, 3 };
    // vector<int> a = {0, 1, 2, 2, 3, 0, 4, 2};
    vector<int> a = {2};
    Solution s;
    int k = s.removeElement(a, 3);
    std::cout << k << endl;
    printf("[");
    for (int i = 0; i < a.size(); i++)
    {
        printf("%d ", a[i]);
    }
    printf("]\n");
    return 0;
}
