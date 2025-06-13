#include <iostream>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

bool isMirror(TreeNode* left, TreeNode* right){
    if(!left && !right) return true;
    if(!left || !right || left->val != right->val) return false;
    return isMirror(left->left, right->right) && isMirror(left->right, right->left);
}


bool isSymmetric(TreeNode* root){
    if(!root) return true;
    return isMirror(root->left, root->right);
}


TreeNode* buildTree(){
    cout<<"Enter level-order tree values (-1 for NULL): ";
    int val;
    cin>>val;

    if(val == -1) return nullptr;
    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* current = q.front();
        q.pop();

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

int main(){
    TreeNode* root = buildTree();
    bool result = isSymmetric(root);

    if(result)
    cout<<"The tree is Symmetric."<<endl;
    else
    cout<<"The tree is Not symmetric"<<endl;

    return 0;
}
