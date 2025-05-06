#include "iostream"

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
    TreeNode(int val,TreeNode *left,TreeNode *right){
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

int heightOfTree(TreeNode *&root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);
    return 1 + max(leftHeight,rightHeight);
}

int diameterOfTree(TreeNode *&root){
    if(root == NULL){
        return 0;
    }
    int leftDiameter = diameterOfTree(root->left);
    int rightDiameter = diameterOfTree(root->right);

    int diameterThroughRoot = 1 + heightOfTree(root->left) + heightOfTree(root->right);

    return max(leftDiameter ,max(rightDiameter,diameterThroughRoot));


}


int main(){
    TreeNode *root = NULL;
    root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(13);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);

    root->right = new TreeNode(10);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(16);
    root->right->right->left = new TreeNode(15);
    root->right->right->right = new TreeNode(2);
    root->right->right->left->left = new TreeNode(9);
    root->right->right->left->right = new TreeNode(4);

    cout<<heightOfTree(root);
}