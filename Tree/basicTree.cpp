#include<iostream>
#include<queue>
using namespace std;
class node {
    public:
    int data;
    node *left;
    node* right;
    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
node* BuildTree() {
    int data;
    cin>>data;
    if (data ==-1){
        return NULL;
    }
    node *root = new node(data);
    root->left = BuildTree();
    root->right = BuildTree();
    return root;
}

void Inorder(node *root) {
    if (root == NULL) {
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void LevelOrderTraveral(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
       node *temp = q.front();
       q.pop();
       cout<<temp->data<<" "; 
       if (temp->left!= NULL){
              q.push(temp->left);
       }
       if (temp->right!= NULL){
              q.push(temp->right);
       }
    }
}
int main () {
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    node *root = BuildTree();
    cout<<"Inorder Traversal: ";
    Inorder(root);
    cout<<endl;
    cout<<"Level Order Traversal: ";
    LevelOrderTraveral(root);

}