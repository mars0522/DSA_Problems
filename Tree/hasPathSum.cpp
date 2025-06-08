#include<iostream>
#include<queue>
using namespace std;
class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) {
        val = val;
        left =nullptr;
        right = nullptr;
    }
};

class Solution {
    public:
        bool hasPathSum(TreeNode* root, int targetSum) {
            if (!root) return false;
            if (root->left == NULL && root->right == NULL && targetSum - root->val == 0) return true;
            return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right,targetSum-root->val);
            
        }
    };
