#include<iostream>
#include<queue>
using namespace std;
class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) {
        this->val = val;
        left =nullptr;
        right = nullptr;
    }
};

class Solution {
    public:
        void func(TreeNode* root, vector<int>&arr, vector<vector<int>>& res, int sum) {
            if(root==NULL) return ;
            if(root->left == NULL && root->right == NULL){
                if(sum-root->val==0){
                    arr.push_back(root->val);
                    res.push_back(arr);
                    arr.pop_back();
                }
            }else {
                arr.push_back(root->val);
                func(root->left,arr,res,sum-root->val);
                func(root->right,arr,res,sum-root->val);
                arr.pop_back();
            }
        }
        vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
            vector<int>arr;
            vector<vector<int>>res;
            func(root,arr,res,targetSum);
            return res;
            
        }
    };