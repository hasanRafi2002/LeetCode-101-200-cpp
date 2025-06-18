#include <iostream>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

int maxDepth(TreeNode* root){
    if(!root) return 0;
    return 1+ max(maxDepth(root->left), maxDepth(root->right));
}

TreeNode* buildTree(){
    int val;
    cout<<"Enter value (-1 for NULL): ";
    cin>>val;
    if(val == -1) return NULL;
    TreeNode* node = new TreeNode(val);
    cout<<"Enter left child of "<<val<<":\n";
    node->right = buildTree();

    return node;
}

int main(){
    cout<<"Build the tree:\n";
    TreeNode* root = buildTree();

    int depth = maxDepth(root);
    cout<<"Maximum Depth of the Tree: "<<depth<<endl;

    return 0;
}