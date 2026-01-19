
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
    vector<int> rightSideView(TreeNode* root) {
        // 因为自然地发现每层只有一个可以满足，就是层序遍历的每层最后一个，就可以了。
        // 复习一下各种遍历吧。
        queue<pair<int, TreeNode*>> myQueue;
        // 第一个储存当前层数，第二个储存节点。
        vector<int> ansVec;
        if(!root) return ansVec;
        myQueue.push(make_pair(0, root));
        while (!myQueue.empty())
        {
            pair<int, TreeNode*> tmp = myQueue.front();
            myQueue.pop();
            if(tmp.second->left) {
                myQueue.push(make_pair(tmp.first+1, tmp.second->left));
            }
            if(tmp.second->right) {
                myQueue.push(make_pair(tmp.first+1, tmp.second->right));
            }
            if(myQueue.empty() || tmp.first != myQueue.front().first) {
                ansVec.push_back(tmp.second->val);
            }
        }
        return ansVec;

    }
};