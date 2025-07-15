#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    void merge1(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {   
        //o(n2)

        // empty nums1
        if(m==0){
            for(int i=0;i<n;i++){
                nums1[i]=nums2[i];
            }
            return;
        }



        int now_loc = 0;
        int now_m = m;
        for (int i = 0; i < n; i++)
        {
            // more than biggst num, no need to find.
            if(nums2[i] >= nums1[now_m - 1]){
                nums1[now_m] = nums2[i];
                now_m++;
                continue;
            }

            // find the loc of nums2[i]
            while(nums1[now_loc] <= nums2[i])
            {
                now_loc++;
            }
            // now nums1[now_loc] > nums2[i]
            // nums1[now_loc-1] <= nums2[i]
            // put the new num at now_loc
            insert(nums1, now_loc, now_m, nums2[i]);
            now_m++; 
        }
    }

    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        //o(m+n)
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        // need to prove always k>i
        while (i>=0 && j>=0)
        {
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                k--;
                i--;
            }
            else {
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }
        if (i > 0) {
            return;
        } else {
            for(int p=0;p<=j;p++){
                nums1[p] = nums2[p];
            }
        }
        
    }
private:
    void insert(vector<int> &nums1, int loc, int m, int num)
    {
        // exc
        for(int i=m; i>loc; i--)
        {
            nums1[i] = nums1[i-1];
        }
        nums1[loc] = num;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m=3;
    int n=3;
    s.merge(nums1, m, nums2, n);
    for(auto num:nums1){
        cout <<num <<" ";
    }
    cout << "\n";
    return 0;
}