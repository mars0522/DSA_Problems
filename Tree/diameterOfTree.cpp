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
        int d = 0;
        int max(int x, int y) {
            return x>y?x:y;
        }
        int findDiameter(TreeNode* root) {
            if (root==NULL) return 0 ;
            if (root->left == NULL && root->right == NULL) return 0;
            int lh = findDiameter(root->left);
            int rh = findDiameter(root->right);
            if(root->left == NULL || root->right == NULL) {
                d = lh+rh+1>d?lh+rh+1:d;
            }else {
                d = lh+rh+2>d?lh+rh+2:d;
            }
            return max(lh,rh)+1;
        }
        int diameterOfBinaryTree(TreeNode* root) {
            findDiameter(root);
            return d;
        }
    };