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

TreeNode* BuildLevelOrderTree(queue<TreeNode*> q)  {
    int n;
    cin>>n;
    TreeNode* root = new TreeNode(n);
    q.push(root);
    while(!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        cin>>n;
        if (n!=-1){
            temp->left = new TreeNode(n);
            q.push(temp->left);
        }
        cin>>n;
        if (n!=-1){
            temp->right = new TreeNode(n);
            q.push(temp->right);
        }
    }
    return root;
}

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
            data.push_back(temp->data);
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right!= NULL) q.push(temp->right);
            n--;
        }
        res.push_back(data);
        data.clear();
    }
    return res;
}

int main () {

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    queue<TreeNode*>q;
    TreeNode* root = BuildLevelOrderTree(q);
    vector<vector<int>> res = levelOrder(root);

    for(auto v: res) {
        for(auto x: v) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}