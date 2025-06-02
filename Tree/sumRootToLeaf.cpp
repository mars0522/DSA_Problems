#include<iostream>
#include<queue>
using namespace std;
class TreeNode {
    public:
    int data;
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int val) {
        data = val;
        left =nullptr;
        right = nullptr;
    }
};

class Solution {
    public:
        int sum = 0;
        void RootSum(TreeNode* root, int sumtillnow) {
            if(root==NULL) return ;
            sumtillnow = 10*sumtillnow + root->val;
            if(root->left ==NULL && root->right == NULL) {
                sum += sumtillnow;
                return ;
            }
            RootSum(root->left, sumtillnow);
            RootSum(root->right,sumtillnow);
            
        }
        int sumNumbers(TreeNode* root) {
            RootSum(root,0);
            return sum;
        }
    };