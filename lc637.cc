#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> avgArr;
        queue<pair<int, TreeNode*>> myQueue;
        myQueue.push(make_pair(0, root));
        int floorCount = 0;
        double tmpSum = 0;
        while (myQueue.empty() == false) {
            TreeNode* tmp = myQueue.front().second;
            int index = myQueue.front().first;
            floorCount++;
            tmpSum += tmp->val;
            myQueue.pop();
            if (tmp->left) {
                myQueue.push({index + 1, tmp->left});
            }
            if (tmp->right) {
                myQueue.push({index + 1, tmp->right});
            }
            if (myQueue.empty() || myQueue.front().first != index) {
                double res = tmpSum / floorCount;
                avgArr.push_back(res);
                tmpSum = 0;
                floorCount = 0;
            }
        }
        return avgArr;
    }
};