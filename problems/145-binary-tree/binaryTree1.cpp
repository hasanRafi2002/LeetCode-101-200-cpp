#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr) , right(nullptr){}
};

TreeNode* buildTree(){
    cout<<"Enter node values in level order (-1 for NULL): ";
    int val;
    cin>>val;
    if(val == -1) return nullptr;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* current = q.front(); q.pop();

        int leftVal, rightVal;
        cin>>leftVal;
        if(leftVal != -1){
            current->left = new TreeNode(leftVal);
            q.push(current->left);
        }

        cin>>rightVal;
        if(rightVal != -1){
            current->right = new TreeNode(rightVal);
            q.push(current->right);
        }
    }
    return root;
}

void postorder(TreeNode* root, vector<int>& result){
    if(!root) return;
    postorder(root->left, result);
    postorder(root->right, result);
    result.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root){
    vector<int> result;
    postorder(root, result);
    return result;
}


int main(){
    TreeNode* root = buildTree();
    vector<int> result = postorderTraversal(root);
    cout<<"Postorder Traversal: ";
    for(int val : result){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}