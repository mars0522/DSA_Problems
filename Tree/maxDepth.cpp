#include<iostream>
#include<queue>
using namespace std;
class TreeNode {
    public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) {
        data = val;
        left =nullptr;
        right = nullptr;
    }
};
class Solution {
    public:
        int max(int x, int y) {
            return x>y?x:y;
        }
        int maxDepth(TreeNode* root) {
            if(root == NULL) return 0;
            if(root->left == NULL && root->right == NULL ) return 1;
    
            int lh = maxDepth(root->left);
            int rh = maxDepth(root->right);
    
            return max(lh,rh)+1;
    
            
        }
    };