#include<iostream>
#include<vector>

struct TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode *right;
    TreeNode(int data) {
        val = data;
        left = nullptr;
        right = nullptr;
    }
}
class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
    
            vector<vector<int>>res;
            if (root==NULL) return res;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()) {
                int n= q.size();
                vector<int> data;
                while(n) {
                    TreeNode* temp= q.front();
                    q.pop();
                    data.push_back(temp->val);
                    if(temp->left != NULL) q.push(temp->left);
                    if(temp->right!= NULL) q.push(temp->right);
                    n--;
                }
                res.push_back(data);
                data.clear();
            }
            return res;
        }
    };