#include <iostream>
#include <queue>
#include <string>
#include<sstream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

TreeNode* buildTree(const vector<string>& nodes){
    if (nodes.empty() || nodes[0] == "null") return nullptr;
    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while(!q.empty() && i<nodes.size()){
        TreeNode*curr = q.front();
        q.pop();

        if(i<nodes.size() && nodes[i] != "null"){
            curr->left = new TreeNode(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;
        if(i<nodes.size() && nodes[i] != "null"){
            curr->right = new TreeNode(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;

}

bool isMirror(TreeNode* left, TreeNode* right){
    if(!left && !right) return true;
    if(!left || !right) return false;
    return (left->val == right->val)
    && isMirror(left->left, right->right)
    && isMirror(left->right, right->left);
}

bool isSymmetricRecursive(TreeNode* root){
    return !root || isMirror(root->left, root->right);
}

bool isSymmetricIterative(TreeNode* root){
    if(!root) return true;
    queue<TreeNode*> q;
    q.push(root->left);
    q.push(root->right);

    while(!q.empty()){
        TreeNode* left = q.front(); q.pop();
        TreeNode* right = q.front(); q.pop();

        if(!left && !right) continue;
        if(!left || !right || left->val != right->val)
        return false;

        q.push(left->left);
        q.push(right->right);
        q.push(left->right);
        q.push(right->left);
    }
    return true;
}

void deleteTree(TreeNode* root){
    if(!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main(){
    cout<<"Enter the tree nodes in level-order (spaece separated):\n";
    cout<<"Use 'null' for empty nodes. Press Enter when done.\n";
    string input;
    getline(cin, input);
    stringstream ss(input);
    vector<string> nodes;
    string node;
    while(ss>>node){
        nodes.push_back(node);
    }
    TreeNode* root = buildTree(nodes);
    if(!root){
        cout<<"\nResult (empty tree is symmetric): true\n";
        return 0;
    }


    bool recursiveResult = isSymmetricRecursive(root);
    bool iterativeResult = isSymmetricIterative(root);

    cout<<"\nRecursive result: "<<(recursiveResult ? "true" : "false")<<endl;
    cout<<"Iterative result: "<<(iterativeResult ? "true" : "false")<<endl;
    deleteTree(root);

    return 0;
}