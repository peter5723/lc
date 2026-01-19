
#include <iostream>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || p == root || q == root) {
            return root;
        }
        TreeNode* leftcase = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightcase = lowestCommonAncestor(root->right, p, q);
        // left 和 right 都不空只有一种情况，就是 p 和 q 都返回了它自己，那么root就是结果
        if (leftcase && rightcase) {
            return root;
        }
        return leftcase ? leftcase : rightcase;
    }
};