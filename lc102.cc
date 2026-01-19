
#include <iostream>
#include <vector>
#include<queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<int, TreeNode*>> myQueue;
        vector<vector<int>> ans;
        if(!root) return ans;
        myQueue.push({0, root});
        vector<int> tmpVec;
        while (myQueue.empty()==false)
        {

            int index = myQueue.front().first;
            TreeNode *tmp = myQueue.front().second;
            tmpVec.push_back(tmp->val);
            myQueue.pop();
            if(tmp->left){
                myQueue.push({index+1, tmp->left});
            }
            if(tmp->right){
                myQueue.push({index+1, tmp->right});
            }
            if(myQueue.empty() || myQueue.front().first!=index){
                ans.push_back(tmpVec);
                tmpVec.clear();
            }
        }
        return ans;
        
    }
};