#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

TreeNode* buildTree(){
    cout<<"Enter values in level-order (-1 for null): ";
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

vector<int> preorderTraversal(TreeNode* root){
    vector<int> result;
    if(!root) return result;

    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty()){
        TreeNode* node = st.top();
        st.pop();
        result.push_back(node->val);

        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);
    }
    return result;
}


int main(){
    TreeNode* root = buildTree();
    vector<int> result = preorderTraversal(root);

    cout<<"Preorder Traversal: ";
    for(int val : result){
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}